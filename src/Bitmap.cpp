#include <Plus.hpp>

namespace Plus {
    /*
     * Initialize bitmap from filename (extension not necessary)
     *
     * @param std::string Filename
     * @return Plus::Bitmap New bitmap from file
     */
    Bitmap::Bitmap(std::string filename) {
        this->_disposed = false;

        glGenTextures(1, &this->textureId);

        glBindTexture(GL_TEXTURE_2D, this->textureId);
        int w, h;
        unsigned char* image = SOIL_load_image(filename.c_str(), &w, &h, NULL, SOIL_LOAD_RGBA);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

        SOIL_free_image_data(image);

        this->width = w;
        this->height = h;

        // TODO: Create bitmap
    }

    /*
     * Initialize bitmap from dimensions
     *
     * @param uint Width
     * @param uint Height
     * @return Plus::Bitmap New bitmap
     */
    Bitmap::Bitmap(unsigned int width, unsigned int height){
        this->_disposed = false;
        this->width     = width;
        this->height    = height;

        // TODO: Create bitmap
    }

    /*
     * Return bitmap's GL texture id
     *
     * @return uint Texture ID
     */
    unsigned int Bitmap::getTextureId(){
        return this->textureId;
    }

    /*
     * Return bitmap's width
     *
     * @return uint Width
     */
    unsigned int Bitmap::getWidth(){
        return this->width;
    }

    /*
     * Return bitmap's height
     *
     * @return uint Height
     */
    unsigned int Bitmap::getHeight(){
        return this->height;
    }

    /*
     * Disposes the bitmap
     *
     * @return void
     */
    void Bitmap::dispose(){
        // TODO
    }

    /*
     * Check if bitmap is disposed
     */
    bool Bitmap::isDisposed(){
        return this->_disposed;
    }

    /*
     * Blit another bitmap in this bitmap without opacity parsing
     *
     * @param int X Position
     * @param int Y Position
     * @param Plus::Bitmap Origin bitmap
     * @param Plus::Rect Rect from origin to blit
     * @return void
     */
    void Bitmap::blt(int x, int y, Plus::Bitmap src_bitmap, Plus::Rect src_rect){
        // TODO
    }

    /*
     * Blit another bitmap in this bitmap with opacity parsing
     *
     * @param int X Position
     * @param int Y Position
     * @param Plus::Bitmap Origin bitmap
     * @param Plus::Rect Rect from origin to blit
     * @param unsigned char Opacity
     * @return void
     */
    void Bitmap::blt(int x, int y, Plus::Bitmap src_bitmap, Plus::Rect src_rect, unsigned char opacity){
        // TODO
    }

    /*
     * Blit another bitmap in this bitmap without opacity parsing and using
     * stretch methods.
     *
     * @param Plus::Rect Destiny rect
     * @param Plus::Bitmap Origin bitmap
     * @param Plus::Rect Rect from origin to blit
     * @return void
     */
    void Bitmap::stretchBlt(Plus::Rect dest_rect, Plus::Bitmap src_bitmap, Plus::Rect src_rect){
        // TODO
    }

    /*
     * Blit another bitmap in this bitmap with opacity parsing and using
     * stretch methods.
     *
     * @param Plus::Rect Destiny rect
     * @param Plus::Bitmap Origin bitmap
     * @param Plus::Rect Rect from origin to blit
     * @param unsigned char Opacity
     * @return void
     */
    void Bitmap::stretchBlt(Plus::Rect dest_rect, Plus::Bitmap src_bitmap, Plus::Rect src_rect, unsigned char opacity){
        // TODO
    }

    /*
     * Fill a rect
     *
     * @param int X Position
     * @param int Y Position
     * @param uint Width
     * @param uint Height
     * @param Plus::Color Color to fill
     * @return void
     */
    void Bitmap::fillRect(int x, int y, unsigned int width, unsigned int height, Plus::Color color){
        // TODO
    }

    /*
     * Fill a rect
     *
     * @param Plus::Rect Rect to fill
     * @param Plus::Color Destination Color
     * @return void
     */
    void Bitmap::fillRect(Plus::Rect rect, Plus::Color color){
        // TODO
    }

    /*
     * Fill a rect with a gradient
     *
     * @param int X Position
     * @param int Y Position
     * @param uint Width
     * @param uint Height
     * @param Plus::Color Initial color
     * @param Plus::Color Final color
     * @return void
     */
    void Bitmap::gradientFillRect(int x, int y, unsigned int width, unsigned int height, Plus::Color color1, Plus::Color color2){
        // TODO
    }

    /*
     * Fill a rect with a gradient
     *
     * @param Plus::Rect Rect to fill
     * @param Plus::Color Initial color
     * @param Plus::Color Final color
     * @return void
     */
    void Bitmap::gradientFillRect(Plus::Rect rect, Plus::Color color1, Plus::Color color2){
        // TODO
    }

    /*
     * Clear (fill with Color(0, 0, 0, 0)) all bitmap's data
     *
     * @return void
     */
    void Bitmap::clear(){
        // TODO
    }

    /*
     * Clear a rect
     *
     * @param int X Position
     * @param int Y Position
     * @param uint Width
     * @param uint Height
     * @return void
     */
    void Bitmap::clearRect(int x, int y, unsigned int width, unsigned int height){
        // TODO
    }

    /*
     * Clear a rect
     *
     * @param Plus::Rect Rect to clear
     * @return void
     */
    void Bitmap::clearRect(Plus::Rect rect){
        // TODO
    }

    /*
     * Returns a pixel color
     *
     * @param uint X Position
     * @param uint Y Position
     * @return Plus::Color Color stored in pixel
     */
    Plus::Color Bitmap::getPixel(unsigned int x, unsigned int y){
        // TODO
        return Color(0,0,0,0);
    }

    /*
     * Sets a pixel color
     *
     * @param uint X Position
     * @param uint Y Position
     * @param Plus::Color Color to store
     * @return void
     */
    void Bitmap::setPixel(unsigned int x, unsigned int y, Plus::Color color){
        // TODO
    }

    /*
     * Change bitmap's hue
     *
     * @param int Angle
     */
    void Bitmap::hueChange(int angle){
        // TODO
    }

    /*
     * Apply simple blur in all the bitmap's area
     *
     * @return void
     */
    void Bitmap::blur(){
        // TODO
    }

    /*
     * Apply radial blur in all the bitmap's area
     *
     * @param int Angle of the blur (Higher = Higher Roundness)
     * @param int Number of divisions (Higher = Smother)
     */
    void Bitmap::radialBlur(int angle, int division){
        // TODO
    }

    /*
     * Draw text with font presets
     *
     * @param int X Position
     * @param int Y Position
     * @param uint Width
     * @param uint Height
     * @param std::string text
     * @return void
     */
    void Bitmap::drawText(int x, int y, unsigned int width, unsigned int height, std::string text){
        // TODO
    }

    /*
     * Draw text with font presets
     *
     * @param int X Position
     * @param int Y Position
     * @param uint Width
     * @param uint Height
     * @param std::string text
     * @param unsigned char Align (0 = Left | 1 = Center | 2 = Right)
     * @return void
     */
    void Bitmap::drawText(int x, int y, unsigned int width, unsigned int height, std::string text, unsigned char align){
        // TODO
    }

    /*
     * Draw text with font presets
     *
     * @param Plus::Rect Text rect
     * @param std::string text
     * @return void
     */
    void Bitmap::drawText(Plus::Rect rect, std::string text){
        // TODO
    }

    /*
     * Draw text with font presets
     *
     * @param Plus::Rect Text rect
     * @param std::string text
     * @param unsigned char Align (0 = Left | 1 = Center | 2 = Right)
     * @return void
     */
    void Bitmap::drawText(Plus::Rect rect, std::string text, unsigned char align){
        // TODO
    }

    /*
     * Gets text rect based on font presets
     */
    Plus::Rect Bitmap::textSize(std::string text){
        // TODO
        return Rect(0,0,0,0);
    }

    /*
     * Destructor
     */
    Bitmap::~Bitmap() {
    }
};
