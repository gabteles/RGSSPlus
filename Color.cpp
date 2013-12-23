/* 
 * File:   Color.cpp
 * Author: Gab
 * 
 * Created on 24 de Janeiro de 2013, 01:35
 */

#include <Plus.hpp>

namespace Plus {
    /*
     * Transparent color
     * 
     * @return Plus::Color New blank color
     */
    Color::Color(){
        Color(0, 0, 0, 0);
    }

    /*
     * Construct a color with RGB data
     * 
     * @param double Red channel
     * @param double Green channel
     * @param double Blue channel
     * @return Plus::Color Color with RGB data + 255 Alpha Channel
     */
    Color::Color(double red, double green, double blue){
        Color(red, green, blue, 255);
    }

    /* 
     * Construct a color with RGBA data
     * 
     * @param double Red channel
     * @param double Green channel
     * @param double Blue channel
     * @param double Alpha channel
     * @return Plus::Color Color with RGBA data
     */
    Color::Color(double red, double green, double blue, double alpha){
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
     * @param double Red channel
     * @param double Green channel
     * @param double Blue channel
     * @return void
     */
    void Color::set(double red, double green, double blue){
        this->r = red;
        this->g = green;
        this->b = blue;
    }

    /*
     * Change RGBA channels
     * 
     * @param double Red channel
     * @param double Green channel
     * @param double Blue channel
     * @param double Alpha channel
     * @return void
     */
    void Color::set(double red, double green, double blue, double alpha){
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
     * @param double Value
     * @return void
     */
    void Color::setRed(double red){
        this->r = red;
    }

    /*
     * Set green channel value
     * 
     * @param double Value
     * @return void
     */
    void Color::setGreen(double green){
        this->g = green;
    }

    /*
     * Set blue channel value
     * 
     * @param double Value
     * @return void
     */
    void Color::setBlue(double blue){
        this->b = blue;
    }

    /*
     * Set alpha channel value
     * 
     * @param double Value
     * @return void
     */
    void Color::setAlpha(double alpha){
        this->a = alpha;
    }

    /*
     * Get red channel value
     * 
     * @return double Value
     */
    double Color::getRed(){
        return this->r;
    }

    /*
     * Get green channel value
     * 
     * @return double Value
     */
    double Color::getGreen(){
        return this->g;
    }

    /*
     * Get blue channel value
     * 
     * @return double Value
     */
    double Color::getBlue(){
        return this->b;
    }

    /*
     * Get alpha channel value
     * 
     * @return double Value
     */
    double Color::getAlpha(){
        return this->a;
    }

    /*
     * Simplify color in a structure
     * 
     * @return Color::packedColor Packed color data
     */
    Color::packedColor Color::dump(){
        packedColor pack;
        pack.red   = this->r;
        pack.green = this->g;
        pack.blue  = this->b;
        pack.alpha = this->a;

        return pack;
    }

    /*
     * Load packed color data
     * 
     * @param Color::packedColor Packed color data
     * @return void
     */
    void Color::load(Color::packedColor pack){
        this->r = pack.red;
        this->g = pack.green;
        this->b = pack.blue;
        this->a = pack.alpha;
    }

    /*
     * Destructor
     */
    Color::~Color() {
    }
};
