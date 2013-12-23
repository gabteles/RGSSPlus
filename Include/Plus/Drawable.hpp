/* 
 * File:   Drawable.hpp
 * Author: Gab
 *
 * Created on 3 de Maio de 2013, 14:23
 */

#ifndef DRAWABLE_HPP
#define	DRAWABLE_HPP

#include <Plus.hpp>

namespace Plus {
    class Drawable {
    public:
        Drawable();
        Drawable(Plus::Viewport* viewport);
        void draw();
        Plus::Bitmap* getBitmap();
        void setBitmap(Plus::Bitmap* bitmap);
        Plus::Viewport* getViewport();
        void setViewport(Plus::Viewport* viewport);
        long getOx();
        void setOx(long ox);
        long getOy();
        void setOy(long oy);
        int getZ();
        void setZ(long z);
        bool getVisible();
        void setVibible(bool visible);
        double getZoomX();
        void setZoomX(double zoomX);
        double getZoomY();
        void setZoomY(double zoomY);
        unsigned char getOpacity();
        void setOpacity(unsigned char);
        unsigned char getBlendType();
        void setBlendType(unsigned char blendType);
        Plus::Color* getColor();
        void setColor(Plus::Color* color);
        Plus::Tone* getTone();
        void setTone(Plus::Tone* tone);
        void dispose();
        bool disposed();
        unsigned long getWidth();
        unsigned long getHeight();
        virtual ~Drawable();
        
    private:
        Plus::Bitmap* bitmap;
        Plus::Viewport* viewport;
        long ox, oy;
        int z;
        bool visible, _disposed;
        unsigned char opacity, blendType;
        double zoomX, zoomY;
        Plus::Color* color;
        Plus::Tone* tone;
    };
}

#endif	/* DRAWABLE_HPP */
