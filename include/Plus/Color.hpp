#ifndef PLUS_COLOR_HPP
#define	PLUS_COLOR_HPP

#include <Plus.hpp>

namespace Plus {
    class Color {
    public:
        Color();
        Color(float red, float green, float blue);
        Color(float red, float green, float blue, float alpha);
        void set(Plus::Color src);
        void set(float red, float green, float blue);
        void set(float red, float green, float blue, float alpha);
        void empty();
        void setRed(float red);
        void setGreen(float green);
        void setBlue(float blue);
        void setAlpha(float alpha);
        float getRed();
        float getGreen();
        float getBlue();
        float getAlpha();
        float* dump();
        void load(float* pack);
        ~Color();

    private:
        float r, g, b, a;
    };
};

#endif	/* PLUS_COLOR_HPP */

