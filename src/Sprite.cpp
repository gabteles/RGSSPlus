#include <Plus.hpp>

namespace Plus {
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
     * @return unsigned short Angle
     */
    unsigned short Sprite::getAngle(){
        return this->angle;
    }

    /*
     * Set angle value
     *
     * @param unsigned short New angle
     * @return void
     */
    void Sprite::setAngle(unsigned short angle){
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
     * @return int Wave Amplitude
     */
    int Sprite::getWaveAmp(){
        return this->waveAmp;
    }

    /*
     * Set wave amplitude
     *
     * @param int New amplitude
     * @return void
     */
    void Sprite::setWaveAmp(int waveAmp){
        this->waveAmp = waveAmp;
    }

    /*
     * Get wave length of the sprite's renderization.
     * Effect will only update with calling sprite's update method.
     *
     * @return int Wave Length
     */
    int Sprite::getWaveLength(){
        return this->waveLength;
    }

    /*
     * Set wave length
     *
     * @param int New length
     * @return void
     */
    void Sprite::setWaveLength(int waveLength){
        this->waveLength = waveLength;
    }

    /*
     * Get wave speed of the sprite's renderization.
     * Effect will only update with calling sprite's update method.
     *
     * @return int Wave Speed
     */
    int Sprite::getWaveSpeed(){
        return this->waveSpeed;
    }

    /*
     * Set wave speed
     *
     * @param int New speed
     * @return void
     */
    void Sprite::setWaveSpeed(int waveSpeed){
        this->waveSpeed = waveSpeed;
    }

    /*
     * Get wave phase of the sprite's renderization. Specifies the phase
     * of the top line of the sprite using an angle of up to 360 degrees.
     * Effect will only update with calling sprite's update method.
     *
     * @return int Wave Phase
     */
    int Sprite::getWavePhase(){
        return this->wavePhase;
    }

    /*
     * Set wave phase
     *
     * @param int New phase
     * @return void
     */
    void Sprite::setWavePhase(int wavePhase){
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
    void Sprite::setBushOpacity(unsigned char bushOpacity){
        this->bushOpacity = bushOpacity;
    }

    /*
     * Begins flashing the sprite.
     *
     * @param Plus::Color Flash color. If null, Color(0, 0, 0, 0) will be used
     * @param unsigned int Number of frames flashing will last.
     */
    void Sprite::flash(Plus::Color* color, unsigned int duration){
        this->flashColor    = color;
        this->flashDuration = duration;
    }

    /*
     * Updates the sprite's animations. It's not necessary to call if flash
     * or wave aren't in progress.
     */
    void Sprite::update(){
        // Update flash
        if (this->flashDuration > 0)
            this->flashDuration--;

        // TODO
    }

    /*
     * Draw the sprite on screen
     *
     * @return void
     */
    void Sprite::draw(){
        if (this->bitmap and not this->_disposed){
            glTranslatef(this->x - this->ox, this->y - this->oy + Plus::Graphics.getHeight() - this->bitmap->getHeight(),0);
            glBindTexture(GL_TEXTURE_2D, this->bitmap->getTextureId());
            glBegin(GL_QUADS);
                glTexCoord2d(0, 1);
                glVertex2f(0, 0);

                glTexCoord2d(1, 1);
                glVertex2f(this->bitmap->getWidth(), 0);

                glTexCoord2d(1, 0);
                glVertex2f(this->bitmap->getWidth(), this->bitmap->getHeight());

                glTexCoord2d(0, 0);
                glVertex2f(0, this->bitmap->getHeight());
            glEnd();

        }
    }
};

