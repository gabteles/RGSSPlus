#ifndef PLUS_DRAWABLE_HPP
#define	PLUS_DRAWABLE_HPP

#include <Plus.hpp>

namespace Plus {
    class Drawable {
    public:
        Drawable();
        Drawable(Plus::Viewport* viewport);
        virtual void draw();
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

#endif	/* PLUS_DRAWABLE_HPP */
