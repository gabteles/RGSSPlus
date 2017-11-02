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
     * @param double Red channel
     * @param double Green channel
     * @param double Blue channel
     * @return Plus::Tone Tone with RGB data + Neutral (0) Alpha Channel
     */
    Tone::Tone(double red, double green, double blue){
        this->r  = red;
        this->g  = green;
        this->b  = blue;
        this->gr = 0;
    }

    /*
     * Construct a color with RGBA data
     *
     * @param double Red channel
     * @param double Green channel
     * @param double Blue channel
     * @param double Gray channel
     * @return Plus::Tone Tone with RGBGr data
     */
    Tone::Tone(double red, double green, double blue, double gray){
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
     * @param double Red channel
     * @param double Green channel
     * @param double Blue channel
     * @return void
     */
    void Tone::set(double red, double green, double blue){
        this->r = red;
        this->g = green;
        this->b = blue;
    }

    /*
     * Change RGBGr channels
     *
     * @param double Red channel
     * @param double Green channel
     * @param double Blue channel
     * @param double Gray channel
     * @return void
     */
    void Tone::set(double red, double green, double blue, double gray){
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
     * @param double Value
     * @return void
     */
    void Tone::setRed(double red){
        this->r = r;
    }

    /*
     * Set green channel value
     *
     * @param double Value
     * @return void
     */
    void Tone::setGreen(double green){
        this->g = green;
    }

    /*
     * Set blue channel value
     *
     * @param double Value
     * @return void
     */
    void Tone::setBlue(double blue){
        this->b = blue;
    }

    /*
     * Set gray channel value
     *
     * @param double Value
     * @return void
     */
    void Tone::setGray(double gray){
        this->g = gray;
    }

    /*
     * Get red channel value
     *
     * @return double Value
     */
    double Tone::getRed(){
        return this->r;
    }

    /*
     * Get green channel value
     *
     * @return double Value
     */
    double Tone::getGreen(){
        return this->g;
    }

    /*
     * Get blue channel value
     *
     * @return double Value
     */
    double Tone::getBlue(){
        return this->b;
    }

    /*
     * Get gray channel value
     *
     * @return double Value
     */
    double Tone::getGray(){
        return this->gr;
    }

    /*
     * Simplify tone in a structure
     *
     * @return Plus::Tone::packedTone Packed tone data
     */
    Tone::packedTone Tone::dump(){
        packedTone pack;
        pack.red   = this->r;
        pack.green = this->g;
        pack.blue  = this->b;
        pack.gray  = this->gr;
        return pack;
    }

    /*
     * Load packed tone data
     *
     * @param Plus::Tone::packedTone Packed tone data
     * @return void
     */
    void Tone::load(Tone::packedTone pack){
        this->r  = pack.red;
        this->g  = pack.green;
        this->b  = pack.blue;
        this->gr = pack.gray;
    }

    /*
     * Destructor
     */
    Tone::~Tone(){

    }
};

