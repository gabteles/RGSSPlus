/* 
 * File:   Color.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 01:35
 */

#ifndef COLOR_HPP
#define	COLOR_HPP

namespace Plus {
    
    class Color {
        struct packedColor {
            double red;
            double green;
            double blue;
            double alpha;
        };
        
    public:
        Color();
        Color(double red, double green, double blue);
        Color(double red, double green, double blue, double alpha);
        void set(Plus::Color);
        void set(double red, double green, double blue);
        void set(double red, double green, double blue, double alpha);
        void empty();
        void setRed(double red);
        void setGreen(double green);
        void setBlue(double blue);
        void setAlpha(double alpha);
        double getRed();
        double getGreen();
        double getBlue();
        double getAlpha();
        packedColor dump();
        void load(packedColor packed);
        ~Color();
    private:

    };
};

#endif	/* COLOR_HPP */

