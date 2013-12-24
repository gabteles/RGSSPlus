/* 
 * File:   Viewport.cpp
 * Author: Gab
 * 
 * Created on 24 de Janeiro de 2013, 02:05
 */

#include <Plus.hpp>

namespace Plus {
    /*
     * Create a new generic viewport
     * 
     * @return Plus::Viewport Viewport that covers all the screen
     */
    Viewport::Viewport(){
        this->rect      = new Plus::Rect(0, 0, Plus::Graphics.getWidth(), Plus::Graphics.getHeight());
        this->color     = new Plus::Color();
        this->tone      = new Plus::Tone();
        this->z         = 0;
        this->ox        = 0;
        this->oy        = 0;
        this->_disposed = false;
        this->visible   = true;
    }

    /*
     * Create a new viewport based on the rect given as argument
     * 
     * @param Plus::Rect Area that the viewport will cover
     * @return Plus::Viewport New viewport
     */
    Viewport::Viewport(Plus::Rect* rect){
        this->rect      = rect;
        this->color     = new Plus::Color();
        this->tone      = new Plus::Tone();
        this->z         = 0;
        this->ox        = 0;
        this->oy        = 0;
        this->_disposed = false;
        this->visible   = true;
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
    Viewport::Viewport(int x, int y, int width, int height){
        Viewport(new Plus::Rect(x, y, width, height));
    }

    /*
     * Dispose the viewport
     * 
     * @return void
     */
    void Viewport::dispose(){
        this->_disposed = true;
    }

    /*
     * Check if viewport is disposed
     * 
     * @return void
     */
    bool Viewport::disposed(){
        return this->_disposed;
    }

    /*
     * Begins flashing the viewport
     * 
     * @param Plus::Color Color
     * @param uint Number of frames the flash will last
     */
    void Viewport::flash(Plus::Color* color, unsigned int duration){
        // TODO
    }

    /*
     * Refreshes the viewport flash. It is not necessary to call this 
     * method if no flash effect is needed.
     */
    void Viewport::update(){
        // TODO
    }

    /*
     * Get viewport rect
     * 
     * @return Plus::Rect Viewport rect
     */
    Plus::Rect* Viewport::getRect(){
        return this->rect;
    }

    /*
     * Get viewport color
     * 
     * @return Plus::Color Viewport color
     */
    Plus::Color* Viewport::getColor(){
        return this->color;
    }

    /*
     * Get viewport tone
     * 
     * @return Plus::Tone Viewport tone
     */
    Plus::Tone* Viewport::getTone(){
        return this->tone;
    }

    /*
     * Check if viewport is visible or not
     * 
     * @return bool Viewport visibility
     */
    bool Viewport::getVisible(){
        return this->visible;
    }

    /*
     * Get viewport z coordinate
     * 
     * @return int Z coordinate
     */
    int Viewport::getZ(){
        return this->z;
    }

    /*
     * Get viewport ox coordinate
     * 
     * @return int Ox coordinate
     */
    int Viewport::getOx(){
        return this->ox;
    }

    /*
     * Get viewport oy coordinate
     * 
     * @return int Oy coordinate
     */
    int Viewport::getOy(){
        return this->oy;
    }

    /*
     * Set viewport rect
     * 
     * @param Plus::Rect New rect
     * @return void
     */
    void Viewport::setRect(Plus::Rect* rect){
        this->rect = rect;
    }

    /*
     * Set viewport color
     * 
     * @param Plus::Color New color
     * @return void
     */
    void Viewport::setColor(Plus::Color* color){
        this->color = color;
    }

    /*
     * Set viewport tone
     * 
     * @param Plus::Tone New tone
     * @return void
     */
    void Viewport::setTone(Plus::Tone* tone){
        this->tone = tone;
    }

    /*
     * Set viewport visible or not
     * 
     * @param bool New visibility
     * @return void
     */
    void Viewport::setVisible(bool visible){
        this->visible = visible;
    }

    /*
     * Set viewport z coordinate
     * 
     * @param int New z coordinate
     * @return void
     */
    void Viewport::setZ(int z){
        this->z = z;
    }

    /*
     * Set viewport ox coordinate
     * 
     * @param int New ox coordinate
     * @return void
     */
    void Viewport::setOx(int ox){
        this->ox = ox;
    }

    /*
     * Set viewport oy coordinate
     * 
     * @param int New oy coordinate
     * @return void
     */
    void Viewport::setOy(int oy){
        this->oy = oy;
    }

    /*
     * Destructor
     */
    Viewport::~Viewport(){

    }
};

