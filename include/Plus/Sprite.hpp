#ifndef PLUS_SPRITE_HPP
#define	PLUS_SPRITE_HPP

#include <Plus.hpp>

namespace Plus {
    class Sprite : public Drawable {
        struct ShaderData {
            unsigned int program;
            // Mirror
            unsigned int mirroredLoc;
            // Opacity
            unsigned int opacityLoc;
            // Tone
            unsigned int toneLoc;
            // Color
            unsigned int colorLoc;
            // Wave
            unsigned int pixelAmplitudeLoc;
            unsigned int amplitudeLoc;
            unsigned int lengthLoc;
            unsigned int phaseLoc;
            unsigned int speedLoc;
            unsigned int timeLoc;
            unsigned int texRightLoc;
            unsigned int texLeftLoc;
            unsigned int vertCenterXLoc;
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
            this->bushOpacity   = 128;
        };

        Sprite(Plus::Viewport* viewport) : Drawable::Drawable(viewport) {
            Sprite();
        };

        static ShaderData* getShaderData();
        static ShaderData* shaderData;

        void setBitmap(Plus::Bitmap *bitmap);
        long getX();
        void setX(long x);
        long getY();
        void setY(long y);
        Plus::Rect* getSrcRect();
        void setSrcRect(Plus::Rect* rect);
        float getAngle();
        void setAngle(float angle);
        bool getMirror();
        void setMirror(bool mirror);
        float getWaveAmp();
        void setWaveAmp(float waveAmp);
        float getWaveLength();
        void setWaveLength(float waveLength);
        float getWaveSpeed();
        void setWaveSpeed(float waveSpeed);
        float getWavePhase();
        void setWavePhase(float wavePhase);
        unsigned int getBushDepth();
        void setBushDepth(unsigned int bushDepth);
        unsigned char getBushOpacity();
        void setBushOpacity(unsigned char bushOpacity);
        void flash(Plus::Color* color, unsigned int duration);
        void update();
        virtual void draw();

    private:
        long x, y;
        float angle;
        Plus::Rect* srcRect;
        bool mirror;
        float waveAmp, waveLength, wavePhase, waveSpeed, waveTimer;
        Plus::Color* flashColor;
        unsigned int bushDepth, flashDuration;
        unsigned char bushOpacity;
    };
};

#endif	/* PLUS_SPRITE_HPP */

