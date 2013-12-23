/* 
 * File:   Rect.cpp
 * Author: Gab
 * 
 * Created on 24 de Janeiro de 2013, 01:47
 */

#include <Plus.hpp>

namespace Plus {
    /*
     * "Blank" Rect
     * 
     * @return Plus::Rect Zero-width/height rect on position P(0,0)
     */
    Rect::Rect() {
        Rect(0, 0, 0, 0);
    }

    /*
     * Rect from metrics
     * 
     * @param int X Position
     * @param int Y Position
     * @param int Width
     * @param int Height
     * 
     * @return Plus::Rect New Rect
     */
    Rect::Rect(int x, int y, int width, int height){
        this->x = x;
        this->y = y;
        this->w = width;
        this->h = height;
    }

    /*
     * Get X position
     * 
     * @return int X Position
     */
    int Rect::getX(){
        return this->x;
    }

    /*
     * Set X position
     * 
     * @param int New X position
     * @return void
     */
    void Rect::setX(int x){
        this->x = x;
    }

    /*
     * Get Y Position
     * 
     * @return int Y position
     */
    int Rect::getY(){
        return this->y;
    }

    /* 
     * Set Y Position
     * 
     * @param int New Y position
     * @return void
     */
    void Rect::setY(int y){
        this->y = y;
    }


    /* 
     * Get rect width
     * 
     * @return int Rect width
     */
    int Rect::getWidth(){
        return this->w;
    }

    /*
     * Set rect width
     * 
     * @param int New rect width
     * @return void
     */
    void Rect::setWidth(int width){
        this->w = width;
    }

    /*
     * Get rect height
     * 
     * @return Rect Height
     */
    int Rect::getHeight(){
        return this->h;
    }

    /*
     * Set rect height
     * 
     * @param int New rect height
     * @return void
     */
    void Rect::setHeight(int height){
        this->h = height;
    }

    /*
     * Clear rect data (sets all to zero)
     * 
     * @return void
     */
    void Rect::empty(){
        this->x = 0;
        this->y = 0;
        this->w = 0;
        this->h = 0;
    }

    /*
     * Packs a rect in a simple structure
     * 
     * @return Rect::packedRect Packed Rect
     */
    Rect::packedRect Rect::dump(){
        packedRect pack;
        pack.x      = this->x;
        pack.y      = this->y;
        pack.width  = this->w;
        pack.height = this->h;
        return pack;
    }

    /*
     * Loads a previously packed rect
     * 
     * @param Rect::packedRect Rect dump
     * @return void
     */
    void Rect::load(Rect::packedRect pack){
        this->x = pack.x;
        this->y = pack.y;
        this->w = pack.width;
        this->h = pack.height;
    }

    /*
     * Destructor
     */
    Rect::~Rect() {
    }
};
