/* 
 * File:   Plane.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 01:41
 */

#ifndef PLANE_HPP
#define	PLANE_HPP

#include "Viewport.hpp"
#include "Bitmap.hpp"
#include "Tone.hpp"


namespace Plus {
    class Plane {
    public:
        Plane();
        Plane(Plus::Viewport viewport);
        Plus::Bitmap getBitmap();
        void setBitmap(Plus::Bitmap bitmap);
        Plus::Viewport getViewport();
        void setViewport(Plus::Viewport);
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
        Plus::Color getColor();
        void setColor(Plus::Color color);
        Plus::Tone getTone();
        void setTone(Plus::Tone tone);
        void dispose();
        bool disposed();
        ~Plane();
    private:

    };
};

#endif	/* PLANE_HPP */

