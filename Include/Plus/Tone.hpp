/* 
 * File:   Tone.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 02:03
 */

#ifndef TONE_HPP
#define	TONE_HPP

namespace Plus {
    class Tone {
        struct packedTone {
            double red;
            double green;
            double blue;
            double gray;
        };

    public:
        Tone();
        Tone(double red, double green, double blue);
        Tone(double red, double green, double blue, double gray);
        void set(Plus::Tone* src);
        void set(double red, double green, double blue);
        void set(double red, double green, double blue, double gray);
        void empty();
        void setRed(double red);
        void setGreen(double green);
        void setBlue(double blue);
        void setGray(double gray);
        double getRed();
        double getGreen();
        double getBlue();
        double getGray();
        packedTone dump();
        void load(packedTone pack);
        ~Tone();

    private:
        double r, g, b, gr;
    };
};

#endif	/* TONE_HPP */

