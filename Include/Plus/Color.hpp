/* 
 * File:   Color.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 01:35
 */

#ifndef COLOR_HPP
#define	COLOR_HPP

#include <Plus.hpp>

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
                void set(Plus::Color src);
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
                void load(packedColor pack);
                ~Color();
        private:
            double r, g, b, a;
        };
};

#endif	/* COLOR_HPP */

