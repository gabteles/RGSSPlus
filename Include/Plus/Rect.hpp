/* 
 * File:   Rect.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 01:47
 */

#ifndef RECT_HPP
#define	RECT_HPP

#include <Plus.hpp>

namespace Plus {
    class Rect {
        struct packedRect{
            int x;
            int y;
            int width;
            int height;
        };

    public:
        Rect();
        Rect(int x, int y, int width, int height);
        int getX();
        void setX(int x);
        int getY();
        void setY(int y);
        int getWidth();
        void setWidth(int width);
        int getHeight();
        void setHeight(int height);
        void empty();
        packedRect dump();
        void load(packedRect pack);
        ~Rect();
        
    private:
        int x, y, w, h;
    };
};

#endif	/* RECT_HPP */

