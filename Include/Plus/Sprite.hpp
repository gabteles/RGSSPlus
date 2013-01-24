/* 
 * File:   Sprite.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 02:00
 */

#ifndef SPRITE_HPP
#define	SPRITE_HPP

#include "Color.hpp"


namespace Plus {
        class Sprite {
        public:
            Sprite();
            Sprite(Plus::Viewport viewport);
            Plus::Bitmap getBitmap();
            void setBitmap(Plus::Bitmap bitmap);
            Plus::Viewport getViewport();
            void setViewport(Plus::Viewport);
            Plus::Rect getSrcRect();
            void setSrcRect(Plus::Rect);
            long getOx();
            void setOx(long ox);
            long getOy();
            void setOy(long oy);
            long getX();
            void setX(long x);
            long getY();
            void setY(long y);
            int getZ();
            void setZ(long z);
            unsigned short getAngle();
            void setAngle(unsigned short angle);
            bool getVisible();
            void setVibible(bool visible);
            double getZoomX();
            void setZoomX(double zoomX);
            double getZoomY();
            void setZoomY(double zoomY);
            unsigned char getOpacity();
            void setOpacity(unsigned char);
            bool getMirror();
            void setMirror(bool mirror);
            int getWaveAmp();
            void setWaveAmp(int waveAmp);
            int getWaveLength();
            void setWaveLength(int waveLength);
            int getWaveSpeed();
            void setWaveSpeed(int waveSpeed);
            int getWavePhase();
            void setWavePhase(int wavePhase);
            unsigned int getBushDepth();
            void setBushDepth(unsigned int bushDepth);
            unsigned char getBushOpacity();
            void setBushOpacity(unsigned char bushOpacity);
            unsigned char getBlendType();
            void setBlendType(unsigned char blendType);
            Plus::Color getColor();
            void setColor(Plus::Color color);
            Plus::Tone getTone();
            void setTone(Plus::Tone tone);
            void dispose();
            bool disposed();
            void flash(Plus::Color color, unsigned int duration);
            void update();
            unsigned int getWidth();
            unsigned int getHeight();
            ~Sprite();
        private:

        };
};

#endif	/* SPRITE_HPP */

