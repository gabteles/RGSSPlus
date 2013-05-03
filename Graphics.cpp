/* 
 * File:   Graphics.cpp
 * Author: Gab
 * 
 * Created on 24 de Janeiro de 2013, 02:09
 */

#include <Plus.hpp>

namespace Plus {
        namespace Graphics {
                void initialize(int width, int height){
                    Plus::Graphics::width  = width;
                    Plus::Graphics::height = height;
                }
                
                unsigned int getWidth(){
                    return Plus::Graphics::width;
                }
                
                unsigned int getHeight(){
                    return Plus::Graphics::height;
                }
                
                void setBrightness(unsigned char brightness){
                        Plus::Graphics::brightness = brightness;
                }
        
                void setFrameRate(unsigned char framerate){
                        Plus::Graphics::frameRate = framerate;
                }
        
                unsigned char getBrightness(){
                        return Plus::Graphics::brightness;
                };
        
                unsigned int  getFrameRate(){
                        return Plus::Graphics::frameRate;
                };
        
                void update(){
                        // TODO
                };
        
                void wait(unsigned int duration){
                        for (duration; duration > 0; duration--)
                                Graphics::update();
                };
        
                void fadeout(unsigned int duration){
                        // TODO
                };
        
                void resizeScreen(unsigned short width, unsigned short height){
                        // TODO
                };
        
                void playMovie(string filename){
                        // TODO
                };
    };
};