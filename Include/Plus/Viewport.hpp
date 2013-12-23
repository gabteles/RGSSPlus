/* 
 * File:   Viewport.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 02:05
 */

#ifndef VIEWPORT_HPP
#define	VIEWPORT_HPP

#include <Plus.hpp>

namespace Plus {
    class Viewport {
    public:
        Viewport();
        Viewport(Plus::Rect* rect);
        Viewport(int x, int y, int width, int height);
        void dispose();
        bool disposed();
        void flash(Plus::Color* color, unsigned int duration);
        void update();
        Plus::Color* getColor();
        Plus::Tone*  getTone();
        Plus::Rect*  getRect();
        bool getVisible();
        int getZ();
        int getOx();
        int getOy();
        void setColor(Plus::Color* color);
        void setTone(Plus::Tone* tone);
        void setRect(Plus::Rect* rect);
        void setVisible(bool visible);
        void setZ(int z);
        void setOx(int ox);
        void setOy(int oy);
        ~Viewport();

    private:
        Plus::Rect* rect;
        Plus::Color* color;
        Plus::Tone* tone;
        int z;
        int ox;
        int oy;
        bool _disposed;
        bool visible;
    };
};

#endif	/* VIEWPORT_HPP */

