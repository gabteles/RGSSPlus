#include <Plus.hpp>

namespace Plus {
    /*
     * "Transparent" tone
     *
     * @return Plus::Tone New blank tone
     */
    Tone::Tone(){
        this->r  = 0;
        this->g  = 0;
        this->b  = 0;
        this->gr = 0;
    }

    /*
     * Construct a tone with RGB data
     *
     * @param float Red channel
     * @param float Green channel
     * @param float Blue channel
     * @return Plus::Tone Tone with RGB data + Neutral (0) Alpha Channel
     */
    Tone::Tone(float red, float green, float blue){
        this->r  = red;
        this->g  = green;
        this->b  = blue;
        this->gr = 0;
    }

    /*
     * Construct a color with RGBA data
     *
     * @param float Red channel
     * @param float Green channel
     * @param float Blue channel
     * @param float Gray channel
     * @return Plus::Tone Tone with RGBGr data
     */
    Tone::Tone(float red, float green, float blue, float gray){
        this->r  = red;
        this->g  = green;
        this->b  = blue;
        this->gr = gray;
    }

    /*
     * Change all tone data to parameter's data
     *
     * @param Plus::Tone Tone to copy data
     * @return void
     */
    void Tone::set(Plus::Tone* src){
        this->r  = src->getRed();
        this->g  = src->getGreen();
        this->b  = src->getBlue();
        this->gr = src->getGray();
    }

    /*
     * Change RGB channels
     *
     * @param float Red channel
     * @param float Green channel
     * @param float Blue channel
     * @return void
     */
    void Tone::set(float red, float green, float blue){
        this->r = red;
        this->g = green;
        this->b = blue;
    }

    /*
     * Change RGBGr channels
     *
     * @param float Red channel
     * @param float Green channel
     * @param float Blue channel
     * @param float Gray channel
     * @return void
     */
    void Tone::set(float red, float green, float blue, float gray){
        this->r  = red;
        this->g  = green;
        this->b  = blue;
        this->gr = gray;
    }

    /*
     * Clear tone and leave it blank
     *
     * @return void
     */
    void Tone::empty(){
        this->r  = 0;
        this->g  = 0;
        this->b  = 0;
        this->gr = 0;
    }

    /*
     * Set red channel value
     *
     * @param float Value
     * @return void
     */
    void Tone::setRed(float red){
        this->r = r;
    }

    /*
     * Set green channel value
     *
     * @param float Value
     * @return void
     */
    void Tone::setGreen(float green){
        this->g = green;
    }

    /*
     * Set blue channel value
     *
     * @param float Value
     * @return void
     */
    void Tone::setBlue(float blue){
        this->b = blue;
    }

    /*
     * Set gray channel value
     *
     * @param float Value
     * @return void
     */
    void Tone::setGray(float gray){
        this->g = gray;
    }

    /*
     * Get red channel value
     *
     * @return float Value
     */
    float Tone::getRed(){
        return this->r;
    }

    /*
     * Get green channel value
     *
     * @return float Value
     */
    float Tone::getGreen(){
        return this->g;
    }

    /*
     * Get blue channel value
     *
     * @return float Value
     */
    float Tone::getBlue(){
        return this->b;
    }

    /*
     * Get gray channel value
     *
     * @return float Value
     */
    float Tone::getGray(){
        return this->gr;
    }

    /*
     * Simplify tone in a structure
     *
     * @return float* Packed tone data
     */
    float* Tone::dump(){
        float* dump = new float[4];
        dump[0] = this->r;
        dump[1] = this->g;
        dump[2] = this->b;
        dump[3] = this->gr;
        return dump;
    }

    /*
     * Load packed tone data
     *
     * @param float* Packed tone data
     * @return void
     */
    void Tone::load(float* pack){
        this->r  = *pack++;
        this->g  = *pack++;
        this->b  = *pack++;
        this->gr = *pack++;
    }

    /*
     * Destructor
     */
    Tone::~Tone(){

    }
};

