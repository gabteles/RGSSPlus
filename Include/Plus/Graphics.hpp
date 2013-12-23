/* 
 * File:   Graphics.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 02:09
 */

#ifndef GRAPHICS_HPP
#define	GRAPHICS_HPP

namespace Plus {
    namespace Graphics {       
        static unsigned int width;
        static unsigned int height;
        static string title;
        static unsigned char brightness = 255;
        static unsigned int  frameRate  = 60;
        static Timer* timer;
        static double microsecByFrame = 1000000/60.f;

        void initialize(unsigned int width, unsigned int height, std::string title);
        void initialize(unsigned int width, unsigned int height);
        void initialize(std::string title);
        void initialize();
        unsigned int getWidth();
        unsigned int getHeight();
        unsigned char getBrightness();
        unsigned int  getFrameRate();
        void setFrameRate(unsigned int frameRate);
        void setBrightness(unsigned char brightness);
        void update();
        void wait(unsigned int duration);
        bool isAlive();
        void fadein(unsigned int duration);
        void fadeout(unsigned int duration);
        void resizeScreen(unsigned short width, unsigned short height);
        void playMovie(std::string filename);
    };
};

#endif	/* GRAPHICS_HPP */

