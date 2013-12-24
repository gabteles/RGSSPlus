/* 
 * File:   Drawable.cpp
 * Author: Gab
 * 
 * Created on 3 de Maio de 2013, 14:23
 */

#include <Plus.hpp>

namespace Plus {
    /*
     * New drawable with default data
     * 
     * @return Plus::Plane New default plane
     */
    Drawable::Drawable(){
        this->bitmap    = NULL;
        this->ox        = 0;
        this->oy        = 0;
        this->visible   = true;
        this->_disposed = false;
        this->viewport  = new Plus::Viewport();
        this->color     = new Plus::Color();
        this->tone      = new Plus::Tone();
        
        Plus::Graphics.addObject(this);
    }

    /*
     * New Drawable with a limited screen space
     * 
     * @param Plus::Viewport Plane viewport
     * @return Plus::Plane New plane
     */
    Drawable::Drawable(Plus::Viewport* viewport){
        this->bitmap    = NULL;
        this->ox        = 0;
        this->oy        = 0;
        this->visible   = true;
        this->_disposed = false;
        this->viewport  = viewport;
        this->color     = new Plus::Color();
        this->tone      = new Plus::Tone();
        
        Plus::Graphics.addObject(this);
    }

    /*
     * Draw funcion
     * 
     * @return void
     */
    void Drawable::draw(){
        // DO NOTHING
    }

    /*
     * Get Drawable's bitmap. NULL If unset.
     * 
     * @return Plus::Bitmap Bitmap
     */
    Plus::Bitmap* Drawable::getBitmap(){
        return this->bitmap;
    }

    /*
     * Set plane's bitmap. NULL to unset.
     * 
     * @param Plus::Bitmap New bitmap
     * @retun void
     */
    void Drawable::setBitmap(Plus::Bitmap *bitmap){
        this->bitmap = bitmap;
    }

    /*
     * Get plane's Drawable
     * 
     * @return Plus::Viewport Viewport
     */
    Plus::Viewport* Drawable::getViewport(){
        return this->viewport;
    }

    /*
     * Set Drawable's Viewport
     * 
     * @param Plus::Viewport New Viewport
     * @return void
     */
    void Drawable::setViewport(Plus::Viewport* viewport){
        this->viewport = viewport;
    }

    /*
     * Get Drawable's offset x position
     * 
     * @return long Offset x
     */
    long Drawable::getOx(){
        return this->ox;
    }

    /*
     * Set Drawable's offset x position
     * 
     * @param long New offset x
     * @return void
     */
    void Drawable::setOx(long ox){
        this->ox = ox;
    }

    /*
     * Get Drawable's offset y position
     * 
     * @return long Offset y
     */
    long Drawable::getOy(){
        return this->oy;
    }

    /*
     * Set Drawable's offset y position
     * 
     * @param long New offset y
     * @return void
     */
    void Drawable::setOy(long oy){
        this->oy = oy;
    }

    /*
     * Get z position
     * 
     * @return int Z Position
     */
    int Drawable::getZ(){
        return this->z;
    }

    /*
     * Set z position
     * 
     * @param long New Z Position
     * @return void
     */
    void Drawable::setZ(long z){
        this->z = z;
    }

    /*
     * Check if plane is visible
     * 
     * @return bool Plane visibility
     */
    bool Drawable::getVisible(){
        return this->visible;
    }

    /*
     * Set Drawable visible or remove it's visibility
     * 
     * @param bool New state (true = visible // false = hidden)
     * @return void
     */
    void Drawable::setVibible(bool visible){
        this->visible = visible;
    }

    /*
     * Get zoom x on Drawable's bitmap
     * 
     * @return double Zoom X
     */
    double Drawable::getZoomX(){
        return this->zoomX;
    }

    /*
     * Set horizontal zoom
     * 
     * @param double New zoom x
     * @return void
     */
    void Drawable::setZoomX(double zoomX){
        this->zoomX = zoomX;
    }

    /*
     * Get zoom y on Drawable's bitmap
     * 
     * @return double Zoom Y
     */
    double Drawable::getZoomY(){
        return this->zoomY;
    }

    /*
     * Set vertical zoom
     * 
     * @param double New zoom y
     * @return void
     */
    void Drawable::setZoomY(double zoomY){
        this->zoomY = zoomY;
    }

    /*
     * Get opacity
     * 
     * @return unsigned char Opacity
     */
    unsigned char Drawable::getOpacity(){
        return this->opacity;
    }

    /*
     * Set new opacity
     * 
     * @param unsigned char New opacity
     */
    void Drawable::setOpacity(unsigned char opacity){
        this->opacity = opacity;
    }

    /*
     * Get blending type
     * 
     * @return unsigned char Plane blend type
     */
    unsigned char Drawable::getBlendType(){
        return this->blendType;
    }

    /*
     * Set new blending type to Drawable
     * 
     * @param unsigned char New blend type
     * @return void
     */
    void Drawable::setBlendType(unsigned char blendType){
        this->blendType = blendType;
    }

    /*
     * Get Drawable's color
     * 
     * @return Plus::Color Color
     */        
    Plus::Color* Drawable::getColor(){
        return this->color;
    }

    /*
     * Set Drawable's color
     * 
     * @param Plus::Color New color
     * @return void
     */
    void Drawable::setColor(Plus::Color* color){
        this->color = color;
    }

    /*
     * Get Drawable's tone
     * 
     * @return Plus::Tone Tone
     */
    Plus::Tone* Drawable::getTone(){
        return this->tone;
    }

    /*
     * Set Drawable's tone
     * 
     * @param Plus::Tone New tone
     * @return void
     */
    void Drawable::setTone(Plus::Tone* tone){
        this->tone = tone;
    }

    /*
     * Mark as disposed
     * 
     * @return void
     */
    void Drawable::dispose(){
        this->_disposed = true;
    }

    /*
     * Check if disposed
     * 
     * @return void
     */
    bool Drawable::disposed(){
        return this->_disposed;
    }

    /*
     * Get drawable's bitmap width
     * 
     * @return unsigned long Width   
     */
    unsigned long Drawable::getWidth(){
        return (this->bitmap ? this->bitmap->getWidth() : 0);
    }

    /*
     * Get drawable's bitmap height
     * 
     * @return unsigned long Height  
     */
    unsigned long Drawable::getHeight(){
        return (this->bitmap ? this->bitmap->getHeight() : 0);
    }

    /*
     * Destructor
     */
    Drawable::~Drawable(){
        Plus::Graphics.removeObject(this);
    }
}