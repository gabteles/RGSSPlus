#ifndef PLUS_SPRITE_HPP
#define	PLUS_SPRITE_HPP

#include <Plus.hpp>

namespace Plus {
    class Sprite : public Drawable {
        struct WaveShaderData {
            unsigned int program;
            unsigned int amplitudeLoc;
            unsigned int lengthLoc;
            unsigned int phaseLoc;
            unsigned int speedLoc;
            unsigned int timeLoc;
            unsigned int texRightLoc;
            unsigned int texLeftLoc;
        };

    public:
        Sprite() : Drawable::Drawable() {
            this->x             = 0;
            this->y             = 0;
            this->angle         = 0;
            this->srcRect       = NULL;
            this->mirror        = false;
            this->waveAmp       = 0;
            this->waveLength    = 1;
            this->waveSpeed     = 0;
            this->wavePhase     = 0;
            this->waveTimer     = 0;
            this->flashColor    = new Plus::Color();
            this->flashDuration = 0;
            this->bushDepth     = 0;
            this->bushOpacity   = 127;
        };

        Sprite(Plus::Viewport* viewport) : Drawable::Drawable(viewport) {
            Sprite();
        };

        static WaveShaderData* getWaveShaderData();
        static WaveShaderData* waveShaderData;

        void setBitmap(Plus::Bitmap *bitmap);
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
        float getWaveSpeed();
        void setWaveSpeed(float waveSpeed);
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
        int waveAmp, waveLength, wavePhase;
        double waveSpeed;
        float waveTimer;
        Plus::Color* flashColor;
        unsigned int bushDepth, flashDuration;
        unsigned char bushOpacity;
    };
};

#endif	/* PLUS_SPRITE_HPP */

