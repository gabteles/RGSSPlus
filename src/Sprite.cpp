#include <Plus.hpp>

void print_log(GLuint object)
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

// TODO:
// - Flash
// - Bush
// - Viewport

namespace Plus {
    // Static variables initialization
    Sprite::ShaderData* Sprite::shaderData = NULL;

    /*
     * Get wave shader GLSL program
     *
     * @retun unsigned int OpenGL program
     */
    Sprite::ShaderData* Sprite::getShaderData() {
        if (Sprite::shaderData != NULL) {
            return Sprite::shaderData;
        }

        const char* vertexShaderSource = R"EOS(
            uniform vec4 wave;
            uniform vec4 coords;
            uniform int mirrored;

            void main(void) {
              float sideModifier = (gl_Vertex.x < coords.w ? -0.5 : 0.5);
              float mirrorModifier = (mirrored == 1 ? -1.0 : 1.0);

              vec4 vertMod = vec4(coords.x, 0, 0, 0) * sideModifier;
              vec4 texMod = vec4(wave.x, 0, 0, 0) * sideModifier * mirrorModifier;

              gl_Position = gl_ModelViewProjectionMatrix * (gl_Vertex + vertMod);
              gl_TexCoord[0] = gl_MultiTexCoord0 + texMod;
            }
        )EOS";

        const char* fragmentShaderSource = R"EOS(
            #define PI 3.14159265359

            uniform float time;
            uniform vec4 wave;
            uniform vec4 coords;
            uniform vec4 tone;
            uniform vec4 color;
            uniform float opacity;
            uniform sampler2D tex;

            const vec3 luminanceFactors = vec3(0.21, 0.72, 0.07);

            void main(void) {
                vec2 p = gl_TexCoord[0].xy;

                if (wave.y != 0.0)
                    p.x += sin(wave.z + wave.w * time + p.y * 2.0 * PI / wave.y) * wave.x/2.0;

                // Pixel is off the wave boundaries
                if (p.x < coords.z || p.x > coords.y) {
                    gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);
                    return;
                }

                vec4 normColor = color/255.0;
                vec4 normTone = tone/255.0;

                // Base Fragment color
                vec4 frag = texture2D(tex, p);

                // Apply Gray
                float luminance = dot(normTone.rgb, luminanceFactors);
                frag.rgb = mix(frag.rgb, vec3(luminance), normTone.w);

                // Apply Tone
                frag.rgb += normTone.rgb;

                // Apply opacity
                frag.a *= opacity;

                // Apply Color
                frag.rgb = mix(frag.rgb, color.rgb, color.a);

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
            print_log(vertexShader);
            print_log(fragmentShader);
            print_log(program);
            return 0;
        }

        Sprite::ShaderData* data = new Sprite::ShaderData;

        data->mirroredLoc = glGetUniformLocation(program, "mirrored");
        data->opacityLoc = glGetUniformLocation(program, "opacity");
        data->toneLoc = glGetUniformLocation(program, "tone");
        data->colorLoc = glGetUniformLocation(program, "color");
        data->coordsLoc = glGetUniformLocation(program, "coords");
        data->waveLoc = glGetUniformLocation(program, "wave");
        data->timeLoc = glGetUniformLocation(program, "time");

        data->program = program;

        Sprite::shaderData = data;
        return Sprite::shaderData;
    }

    /*
     * Set sprits's bitmap. NULL to unset.
     *
     * @param Plus::Bitmap New bitmap
     * @retun void
     */
    void Sprite::setBitmap(Plus::Bitmap *bitmap) {
        Drawable::setBitmap(bitmap);

        if (this->bitmap && !this->srcRect) {
            this->srcRect = new Plus::Rect(0, 0, this->bitmap->getWidth(), this->bitmap->getHeight());
        }
    }

    /*
     * Get X Position
     *
     * @return long Horizontal position
     */
    long Sprite::getX(){
        return this->x;
    }

    /*
     * Set X Position
     *
     * @param long New horizontal position
     * @return void
     */
    void Sprite::setX(long x){
        this->x = x;
    }

    /*
     * Get Y Position
     *
     * @return long Vertical position
     */
    long Sprite::getY(){
        return this->y;
    }

    /*
     * Set Y Position
     *
     * @param long New vertical position
     * @return void
     */
    void Sprite::setY(long y){
        this->y = y;
    }

    /*
     * Get sprite's srcRect (relative "viewport" to bitmap)
     *
     * @return Plus::Rect Source Rect
     */
    Plus::Rect* Sprite::getSrcRect(){
        return this->srcRect;
    }

    /*
     * Set source rect
     *
     * @param Plus::Rect New srcRect
     * @return void
     */
    void Sprite::setSrcRect(Plus::Rect* rect){
        this->srcRect = rect;
    }

    /*
     * Get angle in degrees
     *
     * @return float Angle
     */
    float Sprite::getAngle(){
        return this->angle;
    }

    /*
     * Set angle value
     *
     * @param float New angle
     * @return void
     */
    void Sprite::setAngle(float angle){
        this->angle = angle;
    }

    /*
     * Check if sprite is mirrored
     *
     * @return bool Mirror state
     */
    bool Sprite::getMirror(){
        return this->mirror;
    }

    /*
     * Apply mirror or remove it
     *
     * @param bool New state
     * @return void
     */
    void Sprite::setMirror(bool mirror){
        this->mirror = mirror;
    }

    /*
     * Get wave amplitude of the sprite's renderization.
     * Effect will only update with calling sprite's update method.
     *
     * @return float Wave Amplitude
     */
    float Sprite::getWaveAmp(){
        return this->waveAmp;
    }

    /*
     * Set wave amplitude
     *
     * @param float New amplitude
     * @return void
     */
    void Sprite::setWaveAmp(float waveAmp){
        this->waveAmp = waveAmp;
    }

    /*
     * Get wave length of the sprite's renderization.
     * Effect will only update with calling sprite's update method.
     *
     * @return float Wave Length
     */
    float Sprite::getWaveLength(){
        return this->waveLength;
    }

    /*
     * Set wave length
     *
     * @param float New length
     * @return void
     */
    void Sprite::setWaveLength(float waveLength){
        this->waveLength = waveLength;
    }

    /*
     * Get wave speed of the sprite's renderization.
     * Effect will only update with calling sprite's update method.
     *
     * @return float Wave Speed
     */
    float Sprite::getWaveSpeed(){
        return this->waveSpeed;
    }

    /*
     * Set wave speed
     *
     * @param float New speed
     * @return void
     */
    void Sprite::setWaveSpeed(float waveSpeed){
        this->waveSpeed = waveSpeed;
    }

    /*
     * Get wave phase of the sprite's renderization. Specifies the phase
     * of the top line of the sprite using an angle of up to 360 degrees.
     * Effect will only update with calling sprite's update method.
     *
     * @return float Wave Phase
     */
    float Sprite::getWavePhase(){
        return this->wavePhase;
    }

    /*
     * Set wave phase
     *
     * @param float New phase
     * @return void
     */
    void Sprite::setWavePhase(float wavePhase){
        this->wavePhase = wavePhase;
    }

    /*
     * Specifies the number of pixels for the bush section is specified.
     * Bush section is defined by:
     *       Rect(0, height - bushDepth, width, bushDepth)
     *
     * @return unsigned int Bush depth
     */
    unsigned int Sprite::getBushDepth(){
        return this->bushDepth;
    }

    /*
     * Set bush depth
     *
     * @param unsigned int New bush depth
     * @return void
     */
    void Sprite::setBushDepth(unsigned int bushDepth){
        this->bushDepth = bushDepth;
    }

    /*
     * Get bush section opacity
     *
     * @return unsigned char Bush opacity
     */
    unsigned char Sprite::getBushOpacity(){
        return this->bushOpacity;
    }

    /*
     * Set bush section opacity
     *
     * @param unsigned char New bush opacity
     * @return void
     */
    void Sprite::setBushOpacity(unsigned char bushOpacity) {
        this->bushOpacity = bushOpacity;
    }

    /*
     * Begins flashing the sprite.
     *
     * @param Plus::Color Flash color. If null, Color(0, 0, 0, 0) will be used
     * @param unsigned int Number of frames flashing will last.
     */
    void Sprite::flash(Plus::Color* color, unsigned int duration) {
        this->flashColor    = color;
        this->flashDuration = duration;
    }

    /*
     * Get sprite's srcRect's width
     *
     * @return unsigned long Width
     */
    unsigned long Sprite::getWidth(){
        return (this->srcRect ? this->srcRect->getWidth() : 0);
    }

    /*
     * Get sprite's srcRect's height
     *
     * @return unsigned long Height
     */
    unsigned long Sprite::getHeight(){
        return (this->srcRect ? this->srcRect->getHeight() : 0);
    }

    /*
     * Updates the sprite's animations. It's not necessary to call if flash
     * or wave aren't in progress.
     */
    void Sprite::update() {
        // Update flash
        if (this->flashDuration > 0)
            this->flashDuration--;

        this->waveTimer = remainder(this->waveTimer + (1.0/Plus::Graphics.getFrameRate()), 180);
    }

    /*
     * Draw the sprite on screen
     *
     * @return void
     */
    void Sprite::draw() {
        if (!this->bitmap || this->_disposed || !this->visible || this->opacity == 0) {
            return;
        }

        float bitmapWidth = this->bitmap->getWidth();
        float bitmapHeight = this->bitmap->getHeight();

        float srcRectW = this->srcRect->getWidth();
        float srcRectH = this->srcRect->getHeight();

        float vertexW = MIN(bitmapWidth, srcRectW);
        float vertexH = MIN(bitmapHeight, srcRectH);

        if (vertexW <= 0 || vertexH <= 0) {
            return;
        }

        float texLeft = this->srcRect->getX() / bitmapWidth;
        float texTop = this->srcRect->getY() / bitmapHeight;
        float texRight = texLeft + (vertexW / bitmapWidth);
        float texBottom = texTop + (vertexH / bitmapHeight);

        float zoomedVertX = vertexW * this->zoomX;
        float zoomedVertY = vertexH * this->zoomY;

        float tmpTexCoord;

        if (this->mirror) {
            tmpTexCoord = texRight;
            texRight = texLeft;
            texLeft = tmpTexCoord;
        }

        float vertices[] = {
            0, 0,
            zoomedVertX, 0,
            zoomedVertX, zoomedVertY,
            0, zoomedVertY
        };

        float texCoords[] = {
            texLeft,  texBottom,
            texRight, texBottom,
            texRight, texTop,
            texLeft,  texTop
        };

        if (this->mirror) {
            tmpTexCoord = texRight;
            texRight = texLeft;
            texLeft = tmpTexCoord;
        }


        switch (this->blendType) {
            case 0:
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glBlendEquation(GL_FUNC_ADD);
                break;
            case 1:
                glBlendFunc(GL_SRC_ALPHA, GL_ONE);
                glBlendEquation(GL_FUNC_ADD);
                break;
            case 2:
                glBlendFunc(GL_SRC_ALPHA, GL_ONE);
                glBlendEquation(GL_FUNC_SUBTRACT);
                break;
        }

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY_EXT);
        glBindTexture(GL_TEXTURE_2D, this->bitmap->getTextureId());

        Sprite::ShaderData* data = Sprite::getShaderData();

        glUseProgram(data->program);

        float waveData[] = {
            this->waveAmp / vertexW,
            this->waveLength / vertexH,
            this->wavePhase * ((float)(M_PI/180.0)),
            this->waveSpeed
        };

        float coordsData[] = {
            this->waveAmp,
            texRight,
            texLeft,
            vertexW/2
        };

        glUniform1i(data->mirroredLoc, this->mirror);
        glUniform1f(data->opacityLoc, this->opacity/255.0);
        glUniform1f(data->timeLoc, this->waveTimer);
        glUniform4fv(data->coordsLoc, 1, coordsData);
        glUniform4fv(data->waveLoc, 1, waveData);
        glUniform4fv(data->toneLoc, 1, this->tone->dump());
        glUniform4fv(data->colorLoc, 1, this->color->dump());

        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
        glTranslatef(this->x, Plus::Graphics.getHeight() - (this->y + vertexH), 0);
        glRotatef(this->angle, 0.f, 0.f, 1.f);
        glTranslatef(-this->ox * this->zoomX, this->oy * this->zoomY, 0);
        glDrawArrays(GL_QUADS, 0, 4);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY_EXT);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
};


