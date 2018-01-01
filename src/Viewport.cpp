#include <Plus.hpp>

void print_log2(GLuint object)
{
  GLint log_length = 0;
  if (glIsShader(object))
    glGetShaderiv(object, GL_INFO_LOG_LENGTH, &log_length);
  else if (glIsProgram(object))
    glGetProgramiv(object, GL_INFO_LOG_LENGTH, &log_length);
  else {
    fprintf(stderr, "printlog: Não é um shader ou programa\n");
    return;
  }

  char* log = (char*)malloc(log_length);

  if (glIsShader(object))
    glGetShaderInfoLog(object, log_length, NULL, log);
  else if (glIsProgram(object))
    glGetProgramInfoLog(object, log_length, NULL, log);

  fprintf(stderr, "%s", log);
  free(log);
}

namespace Plus {
    // Static variables initialization
    Viewport::ShaderData* Viewport::shaderData = NULL;
    Plus::Viewport* Viewport::DefaultViewport = NULL;

    /*
     * Get wave shader GLSL program
     *
     * @retun unsigned int OpenGL program
     */
    Viewport::ShaderData* Viewport::getShaderData() {
        if (Viewport::shaderData != NULL) {
            return Viewport::shaderData;
        }

        const char* vertexShaderSource = R"EOS(
            void main(void) {
              gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
              gl_TexCoord[0] = gl_MultiTexCoord0;
            }
        )EOS";

        const char* fragmentShaderSource = R"EOS(
            uniform vec4 tone;
            uniform vec4 color;
            uniform sampler2D tex;

            const vec3 luminanceFactors = vec3(0.21, 0.72, 0.07);

            void main(void) {
                vec2 p = gl_TexCoord[0].xy;

                vec4 normColor = color/255.0;
                vec4 normTone = tone/255.0;

                // Base Fragment color
                vec4 frag = texture2D(tex, p);

                // Apply Gray
                float luminance = dot(normTone.rgb, luminanceFactors);
                frag.rgb = mix(frag.rgb, vec3(luminance), normTone.w);

                // Apply Tone
                frag.rgb += normTone.rgb;

                // Apply Color
                frag.rgb = mix(frag.rgb, normColor.rgb, normColor.a);

                gl_FragColor = frag;
            }
        )EOS";

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        unsigned int program = glCreateProgram();

        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(vertexShader);
        glCompileShader(fragmentShader);
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);

        int link_ok;
        glGetProgramiv(program, GL_LINK_STATUS, &link_ok);

        if (!link_ok) {
            print_log2(vertexShader);
            print_log2(fragmentShader);
            print_log2(program);
            return 0;
        }

        Viewport::ShaderData* data = new Viewport::ShaderData;

        data->toneLoc  = glGetUniformLocation(program, "tone");
        data->colorLoc = glGetUniformLocation(program, "color");
        data->program  = program;

        Viewport::shaderData = data;
        return Viewport::shaderData;
    }

    /*
     * Get's default viewport
     *
     * @return Plus::Viewport* Default viewport
     */
    Plus::Viewport* Viewport::getDefault() {
        if (!Viewport::DefaultViewport) {
            Viewport::DefaultViewport = new Plus::Viewport();
        }

        return Viewport::DefaultViewport;
    }


    /*
     * Create a new generic viewport
     *
     * @return Plus::Viewport Viewport that covers all the screen
     */
    Viewport::Viewport() {
        this->rect      = new Plus::Rect(0, 0, Plus::Graphics.getWidth(), Plus::Graphics.getHeight());
        this->color     = new Plus::Color();
        this->tone      = new Plus::Tone();
        this->z         = 0;
        this->ox        = 0;
        this->oy        = 0;
        this->_disposed = false;
        this->visible   = true;
        this->objects = new forward_list<Drawable*>();
        this->flashControl  = new Plus::FlashControl();

        this->createFBO();
        this->createFboAttachments();

        Plus::Graphics.addObject(this);
    }

    /*
     * Create a new viewport based on the rect given as argument
     *
     * @param Plus::Rect Area that the viewport will cover
     * @return Plus::Viewport New viewport
     */
    Viewport::Viewport(Plus::Rect* rect) {
        this->rect      = rect;
        this->color     = new Plus::Color();
        this->tone      = new Plus::Tone();
        this->z         = 0;
        this->ox        = 0;
        this->oy        = 0;
        this->_disposed = false;
        this->visible   = true;
        this->objects = new forward_list<Drawable*>();
        this->flashControl  = new Plus::FlashControl();

        this->createFBO();
        this->createFboAttachments();

        Plus::Graphics.addObject(this);
    }

    /*
     * Create a new viewport based on the coordinates given as argument to
     * form an Plus::Rect
     *
     * @param int X Position
     * @param int Y Position
     * @param int Width
     * @param int Height
     * @return Plus::Viewport New viewport
     */
    Viewport::Viewport(int x, int y, int width, int height) {
        this->rect      = new Plus::Rect(x, y, width, height);
        this->color     = new Plus::Color();
        this->tone      = new Plus::Tone();
        this->z         = 0;
        this->ox        = 0;
        this->oy        = 0;
        this->_disposed = false;
        this->visible   = true;
        this->objects = new forward_list<Drawable*>();
        this->flashControl  = new Plus::FlashControl();

        this->createFBO();
        this->createFboAttachments();

        Plus::Graphics.addObject(this);
    }

    /*
     * Create framebuffer object
     */
    void Viewport::createFBO() {
        glGenFramebuffers(1, &this->framebuffer);
    }

    /*
     * Create texture and renderbuffer, also frees the existing ones if there's any.
     */
    void Viewport::createFboAttachments() {
        int width = this->rect->getWidth();
        int height = this->rect->getHeight();

        this->bufferWidth = width;
        this->bufferHeight = height;

        // Free texture
        if (this->textureId) {
            glDeleteTextures(1, &this->textureId);
        }

        // Free renderbuffer
        if (this->renderbuffer) {
            glDeleteRenderbuffers(1, &this->renderbuffer);
        }

        // No need to create if this dimensions
        if ((width <= 0) || (height <= 0)) {
            return;
        }

        // Generate texture
        glGenTextures(1, &this->textureId);
        glBindTexture(GL_TEXTURE_2D, this->textureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
        glBindTexture(GL_TEXTURE_2D, 0);

        // Create renderbuffer
        glGenRenderbuffers(1, &this->renderbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, this->renderbuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
        glBindRenderbuffer(GL_RENDERBUFFER, 0);

        // Attach buffers to FBO
        glBindFramebuffer(GL_FRAMEBUFFER, this->framebuffer);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, this->textureId, 0);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, this->renderbuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    /*
     * Dispose the viewport
     *
     * @return void
     */
    void Viewport::dispose() {
        this->_disposed = true;
    }

    /*
     * Check if viewport is disposed
     *
     * @return void
     */
    bool Viewport::disposed() {
        return this->_disposed;
    }

    /*
     * Begins flashing the viewport
     *
     * @param Plus::Color Color
     * @param uint Number of frames the flash will last
     */
    void Viewport::flash(const Plus::Color* color, unsigned int duration) {
        this->flashControl->start(color, duration);
    }

    /*
     * Refreshes the viewport flash. It is not necessary to call this
     * method if no flash effect is needed.
     */
    void Viewport::update() {
        this->flashControl->update();
    }

    /*
     * Get viewport rect
     *
     * @return Plus::Rect Viewport rect
     */
    Plus::Rect* Viewport::getRect() {
        return this->rect;
    }

    /*
     * Get viewport color
     *
     * @return Plus::Color Viewport color
     */
    Plus::Color* Viewport::getColor() {
        return this->color;
    }

    /*
     * Get viewport tone
     *
     * @return Plus::Tone Viewport tone
     */
    Plus::Tone* Viewport::getTone() {
        return this->tone;
    }

    /*
     * Check if viewport is visible or not
     *
     * @return bool Viewport visibility
     */
    bool Viewport::getVisible() {
        return this->visible;
    }

    /*
     * Get viewport z coordinate
     *
     * @return int Z coordinate
     */
    int Viewport::getZ() {
        return this->z;
    }

    /*
     * Get viewport ox coordinate
     *
     * @return int Ox coordinate
     */
    int Viewport::getOx() {
        return this->ox;
    }

    /*
     * Get viewport oy coordinate
     *
     * @return int Oy coordinate
     */
    int Viewport::getOy() {
        return this->oy;
    }

    /*
     * Set viewport rect
     *
     * @param Plus::Rect New rect
     * @return void
     */
    void Viewport::setRect(Plus::Rect* rect) {
        this->rect = rect;
    }

    /*
     * Set viewport color
     *
     * @param Plus::Color New color
     * @return void
     */
    void Viewport::setColor(Plus::Color* color) {
        this->color = color;
    }

    /*
     * Set viewport tone
     *
     * @param Plus::Tone New tone
     * @return void
     */
    void Viewport::setTone(Plus::Tone* tone) {
        this->tone = tone;
    }

    /*
     * Set viewport visible or not
     *
     * @param bool New visibility
     * @return void
     */
    void Viewport::setVisible(bool visible) {
        this->visible = visible;
    }

    /*
     * Set viewport z coordinate
     *
     * @param int New z coordinate
     * @return void
     */
    void Viewport::setZ(int z) {
        this->z = z;
    }

    /*
     * Set viewport ox coordinate
     *
     * @param int New ox coordinate
     * @return void
     */
    void Viewport::setOx(int ox) {
        this->ox = ox;
    }

    /*
     * Set viewport oy coordinate
     *
     * @param int New oy coordinate
     * @return void
     */
    void Viewport::setOy(int oy) {
        this->oy = oy;
    }

    /*
     * Add Drawable object to be updated with the graphics
     *
     * @param  Drawable* Object to add
     * @return void
     */
    void Viewport::addObject(Drawable* object) {
        this->objects->push_front(object);
    }

    /*
     * Remove Drawable object
     *
     * @param  Drawable* Object to remove
     * @return void
     */
    void Viewport::removeObject(Drawable* object) {
        this->objects->remove(object);
    }

    /*
     * Checks if buffer should be recreated
     *
     * @return bool
     */
    bool Viewport::shouldResizeBuffer() {
        int currentWidth = this->rect->getWidth();
        int currentHeight = this->rect->getHeight();

        return ((currentWidth != this->bufferWidth) || (currentHeight != this->bufferHeight));
    }

    /*
     * Draw drawables associated with this viewport into framebuffer
     */
    void Viewport::drawInnerObjects() {
        glBindFramebuffer(GL_FRAMEBUFFER, this->framebuffer);
        //glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        for (Drawable* obj : *this->objects) {
            obj->draw();
            glLoadIdentity();
        }
    }

    /*
     * Draws viewport and registered drawables
     */
    void Viewport::draw() {
        float width = (float)this->rect->getWidth();
        float height = (float)this->rect->getHeight();

        if (!this->visible || this->_disposed || (width <= 0) || (height <= 0)) {
            return;
        }

        if (this->shouldResizeBuffer()) {
            this->createFboAttachments();
        }

        this->drawInnerObjects();

        float vertices[] = {
            0, 0,
            width, 0,
            width, height,
            0, height
        };

        float texCoords[] = {
            0, 0,
            1, 0,
            1, 1,
            0, 1
        };

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glBindTexture(GL_TEXTURE_2D, this->textureId);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY_EXT);
        Viewport::ShaderData* data = Viewport::getShaderData();
        glUseProgram(data->program);
        glUniform4fv(data->toneLoc, 1, this->tone->dump());

        Plus::Color flashColor = this->flashControl->getColor();

        if (this->flashControl->isFlashing() && flashColor.getAlpha() > this->color->getAlpha()) {
            glUniform4fv(data->colorLoc, 1, flashColor.dump());
        } else {
            glUniform4fv(data->colorLoc, 1, this->color->dump());
        }

        glTranslatef(this->rect->getX(), Plus::Graphics.getHeight() - this->rect->getY() - height, this->z);
        glTranslatef(-this->ox, -this->oy, 0);
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
        glDrawArrays(GL_QUADS, 0, 4);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY_EXT);
        glDisableClientState(GL_VERTEX_ARRAY);
        glUseProgram(0);
    }

    /*
     * Destructor
     */
    Viewport::~Viewport(){
        Plus::Graphics.removeObject(this);
    }
};

