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
                static unsigned char brightness = 255;
                static unsigned int  frameRate  = 60;
        
                static unsigned int width;
                static unsigned int height;
                
                void initialize();
                unsigned int getWidth();
                unsigned int getHeight();
                unsigned char getBrightness();
                unsigned int  getFrameRate();
                void setFrameRate(unsigned int frameRate);
                void setBrightness(unsigned char brightness);
                void update();
                void wait(unsigned int duration);
                void fadeout(unsigned int duration);
                void resizeScreen(unsigned short width, unsigned short height);
                void playMovie(string filename);
        };
};

#endif	/* GRAPHICS_HPP */

