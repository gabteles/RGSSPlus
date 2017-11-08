#include <Plus.hpp>

namespace Plus {
    Plus::Viewport* Viewport::DefaultViewport = NULL;

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
    void Viewport::flash(Plus::Color* color, unsigned int duration) {
        // TODO
    }

    /*
     * Refreshes the viewport flash. It is not necessary to call this
     * method if no flash effect is needed.
     */
    void Viewport::update() {
        // TODO
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
     * Draws viewport and registered drawables
     */
    void Viewport::draw() {
        glBindFramebuffer(GL_FRAMEBUFFER, this->framebuffer);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        for (Drawable* obj : *this->objects) {
            obj->draw();
            glLoadIdentity();
        }

        int width = this->rect->getWidth();
        int height = this->rect->getHeight();

        glUseProgram(0);

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glBindTexture(GL_TEXTURE_2D, this->textureId);

        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);
            glVertex3f(0.0, 0.0, 0.0);

            glTexCoord2f(0.0, 1.0);
            glVertex3f(0.0, height, 0.0);

            glTexCoord2f(1.0, 1.0);
            glVertex3f(width, height, 0.0);

            glTexCoord2f(1.0, 0.0);
            glVertex3f(width, 0, 0.0);
        glEnd();
    }

    /*
     * Destructor
     */
    Viewport::~Viewport(){

    }
};

