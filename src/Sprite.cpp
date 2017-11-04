#include <Plus.hpp>

namespace Plus {
    // Static variables initialization
    Sprite::WaveShaderData* Sprite::waveShaderData = NULL;

    /*
     * Get wave shader GLSL program
     *
     * @retun unsigned int OpenGL program
     */
    Sprite::WaveShaderData* Sprite::getWaveShaderData() {
        if (Sprite::waveShaderData != NULL) {
            return Sprite::waveShaderData;
        }

        const char* vertexShaderSource =
            "uniform float pixelWaveAmp;"
            "uniform float waveAmp;"
            "uniform float vertCenterX;"
            "void main(void) {"
            "  float modifier = (gl_Vertex.x < vertCenterX ? -0.5 : 0.5);"
            "  vec4 pixelModifierVec = vec4(pixelWaveAmp, 0, 0, 0) * modifier;"
            "  vec4 texModifierVec = vec4(waveAmp, 0, 0, 0) * modifier;"
            "  gl_Position = gl_ModelViewProjectionMatrix * (gl_Vertex + pixelModifierVec);"
            "  gl_TexCoord[0] = gl_MultiTexCoord0 + texModifierVec;"
            "}";

        const char* fragmentShaderSource =
            "#define PI 3.141592\n"
            "uniform float time;"
            "uniform float waveAmp;"
            "uniform float waveLength;"
            "uniform float wavePhase;"
            "uniform float waveSpeed;"
            "uniform float texLeft;"
            "uniform float texRight;"
            "uniform sampler2D tex;"
            "void main(void) {"
            "  vec2 p = gl_TexCoord[0].xy;"
            "  p.x += sin(wavePhase + waveSpeed * time + p.y * 2.0 * PI / waveLength) * waveAmp/2.0;"
            "  if (p.x >= texLeft && p.x <= texRight) {"
            "    gl_FragColor = texture2D(tex, p);"
            "  } else { "
            "    gl_FragColor = vec4(0, 0, 0, 0);"
            "  }"
            "}";

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

        Sprite::WaveShaderData* data = new Sprite::WaveShaderData;

        data->pixelAmplitudeLoc = glGetUniformLocation(program, "pixelWaveAmp");
        data->amplitudeLoc = glGetUniformLocation(program, "waveAmp");
        data->lengthLoc = glGetUniformLocation(program, "waveLength");
        data->phaseLoc = glGetUniformLocation(program, "wavePhase");
        data->speedLoc = glGetUniformLocation(program, "waveSpeed");
        data->timeLoc = glGetUniformLocation(program, "time");
        data->texRightLoc = glGetUniformLocation(program, "texRight");
        data->texLeftLoc = glGetUniformLocation(program, "texLeft");
        data->vertCenterXLoc = glGetUniformLocation(program, "vertCenterX");
        data->program = program;

        Sprite::waveShaderData = data;
        return Sprite::waveShaderData;
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
            this->srcRect = new Plus::Rect(0, 0, this->getWidth(), this->getHeight());
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

        this->waveTimer = remainder(this->waveTimer + (1.0/Plus::Graphics.getFrameRate()), 180);
    }

    /*
     * Draw the sprite on screen
     *
     * @return void
     */
    void Sprite::draw(){
        if (!this->bitmap || this->_disposed) {
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

        float heightAdjust = (srcRectH < bitmapHeight ? bitmapHeight - srcRectH : 0);

        float texLeft = this->srcRect->getX() / bitmapWidth;
        float texTop = this->srcRect->getY() / bitmapHeight;
        float texRight = texLeft + (vertexW / bitmapWidth);
        float texBottom = texTop + (vertexH / bitmapHeight);

        float vertices[] = {
            0, 0,
            vertexW, 0,
            vertexW, vertexH,
            0, vertexH
        };

        float texCoords[] = {
            texLeft,  texBottom,
            texRight, texBottom,
            texRight, texTop,
            texLeft,  texTop
        };

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY_EXT);
        glBindTexture(GL_TEXTURE_2D, this->bitmap->getTextureId());

        Sprite::WaveShaderData* data = Sprite::getWaveShaderData();
        glUseProgram(data->program);
        glUniform1f(data->pixelAmplitudeLoc, this->waveAmp);
        glUniform1f(data->amplitudeLoc, (this->waveAmp / vertexW));
        glUniform1f(data->lengthLoc, (this->waveLength / vertexH));
        glUniform1f(data->phaseLoc, M_PI * this->wavePhase/180.0);
        glUniform1f(data->speedLoc, this->waveSpeed);
        glUniform1f(data->timeLoc, this->waveTimer);
        glUniform1f(data->texRightLoc, texRight);
        glUniform1f(data->texLeftLoc, texLeft);
        glUniform1f(data->vertCenterXLoc, vertexW/2);

        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
        glTranslatef(this->x, Plus::Graphics.getHeight() - this->y, 0);
        glRotatef(this->angle, 0.f, 0.f, 1.f);
        glTranslatef(-this->ox, -(this->oy - heightAdjust), 0);
        glDrawArrays(GL_QUADS, 0, 4);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY_EXT);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
};


