#ifndef PLUS_SPRITE_HPP
#define	PLUS_SPRITE_HPP

#include <Plus.hpp>

namespace Plus {
    class Sprite : public Drawable {
    public:
        Sprite() : Drawable::Drawable(){
            this->x             = 0;
            this->y             = 0;
            this->angle         = 0;
            this->srcRect       = new Plus::Rect();
            this->mirror        = false;
            this->waveAmp       = 0;
            this->waveLength    = 0;
            this->waveSpeed     = 360;
            this->wavePhase     = 0;
            this->flashColor    = new Plus::Color();
            this->flashDuration = 0;
            this->bushDepth     = 0;
            this->bushOpacity   = 127;
        };

        Sprite(Plus::Viewport* viewport) : Drawable::Drawable(viewport){
            Sprite();
        };

        long getX();
        void setX(long x);
        long getY();
        void setY(long y);
        Plus::Rect* getSrcRect();
        void setSrcRect(Plus::Rect* rect);
        unsigned short getAngle();
        void setAngle(unsigned short angle);
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
        void flash(Plus::Color* color, unsigned int duration);
        void update();
        virtual void draw();


    private:
        long x, y;
        unsigned short angle;
        Plus::Rect* srcRect;
        bool mirror;
        int waveAmp, waveLength, waveSpeed, wavePhase;
        Plus::Color* flashColor;
        unsigned int bushDepth, flashDuration;
        unsigned char bushOpacity;
    };
};

#endif	/* PLUS_SPRITE_HPP */

