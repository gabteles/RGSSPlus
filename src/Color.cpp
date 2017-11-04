#include <Plus.hpp>

namespace Plus {
    /*
     * Transparent color
     *
     * @return Plus::Color New blank color
     */
    Color::Color(){
        this->r = 0;
        this->g = 0;
        this->b = 0;
        this->a = 0;
    }

    /*
     * Construct a color with RGB data
     *
     * @param float Red channel
     * @param float Green channel
     * @param float Blue channel
     * @return Plus::Color Color with RGB data + 255 Alpha Channel
     */
    Color::Color(float red, float green, float blue){
        this->r = red;
        this->g = green;
        this->b = blue;
        this->a = 255;
    }

    /*
     * Construct a color with RGBA data
     *
     * @param float Red channel
     * @param float Green channel
     * @param float Blue channel
     * @param float Alpha channel
     * @return Plus::Color Color with RGBA data
     */
    Color::Color(float red, float green, float blue, float alpha){
        this->r = red;
        this->g = green;
        this->b = blue;
        this->a = alpha;
    }

    /*
     * Change all color data to parameter's data
     *
     * @param Plus::Color Color to copy data
     * @return void
     */
    void Color::set(Plus::Color src){
        this->r = src.getRed();
        this->g = src.getGreen();
        this->b = src.getBlue();
        this->a = src.getAlpha();
    }

    /*
     * Change RGB channels
     *
     * @param float Red channel
     * @param float Green channel
     * @param float Blue channel
     * @return void
     */
    void Color::set(float red, float green, float blue){
        this->r = red;
        this->g = green;
        this->b = blue;
    }

    /*
     * Change RGBA channels
     *
     * @param float Red channel
     * @param float Green channel
     * @param float Blue channel
     * @param float Alpha channel
     * @return void
     */
    void Color::set(float red, float green, float blue, float alpha){
        this->r = red;
        this->g = green;
        this->b = blue;
        this->a = alpha;
    }

    /*
     * Clear color and set it to a blank color
     *
     * @return void
     */
    void Color::empty(){
        this->r = 0;
        this->g = 0;
        this->b = 0;
        this->a = 0;
    }

    /*
     * Set red channel value
     *
     * @param float Value
     * @return void
     */
    void Color::setRed(float red){
        this->r = red;
    }

    /*
     * Set green channel value
     *
     * @param float Value
     * @return void
     */
    void Color::setGreen(float green){
        this->g = green;
    }

    /*
     * Set blue channel value
     *
     * @param float Value
     * @return void
     */
    void Color::setBlue(float blue){
        this->b = blue;
    }

    /*
     * Set alpha channel value
     *
     * @param float Value
     * @return void
     */
    void Color::setAlpha(float alpha){
        this->a = alpha;
    }

    /*
     * Get red channel value
     *
     * @return float Value
     */
    float Color::getRed(){
        return this->r;
    }

    /*
     * Get green channel value
     *
     * @return float Value
     */
    float Color::getGreen(){
        return this->g;
    }

    /*
     * Get blue channel value
     *
     * @return float Value
     */
    float Color::getBlue(){
        return this->b;
    }

    /*
     * Get alpha channel value
     *
     * @return float Value
     */
    float Color::getAlpha(){
        return this->a;
    }

    /*
     * Simplify color in a structure
     *
     * @return float* Packed color data
     */
    float* Color::dump(){
        float* dump = new float[4];
        dump[0] = this->r;
        dump[1] = this->g;
        dump[2] = this->b;
        dump[3] = this->a;
        return dump;
    }

    /*
     * Load packed color data
     *
     * @param float* Packed color data
     * @return void
     */
    void Color::load(float* pack) {
        this->r = *pack++;
        this->g = *pack++;
        this->b = *pack++;
        this->a = *pack++;
    }

    /*
     * Destructor
     */
    Color::~Color() {
    }
};
