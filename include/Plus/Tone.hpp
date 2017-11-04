#ifndef PLUS_TONE_HPP
#define	PLUS_TONE_HPP

namespace Plus {
    class Tone {
    public:
        Tone();
        Tone(float red, float green, float blue);
        Tone(float red, float green, float blue, float gray);
        void set(Plus::Tone* src);
        void set(float red, float green, float blue);
        void set(float red, float green, float blue, float gray);
        void empty();
        void setRed(float red);
        void setGreen(float green);
        void setBlue(float blue);
        void setGray(float gray);
        float getRed();
        float getGreen();
        float getBlue();
        float getGray();
        float* dump();
        void load(float* pack);
        ~Tone();

    private:
        float r, g, b, gr;
    };
};

#endif	/* PLUS_TONE_HPP */

