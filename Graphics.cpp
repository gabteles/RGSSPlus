/* 
 * File:   Graphics.cpp
 * Author: Gab
 * 
 * Created on 24 de Janeiro de 2013, 02:09
 */

#include <Plus.hpp>

namespace Plus {
    namespace Graphics {
        /*
         * Initialize graphics routines
         * 
         * @param unsigned int Screen width
         * @param unsigned int Screen height
         * @param std::string Window title
         * @return void
         */
        void initialize(unsigned int width, unsigned int height, std::string title){
            // Save Graphics size and title
            Plus::Graphics::width  = width;
            Plus::Graphics::height = height;
            Plus::Graphics::title  = title;

            // Fake argc and argv, because we don't want conflicts or
            // unexpected results by passing a combination of arguments
            int argc = 0;
            char* argv = (char*)malloc(1);

            // Initialize GLUT and setup it.
            const char* charTitle = title.c_str();
            glutInit(&argc, &argv);
            glutInitWindowPosition(-1, -1);
            glutInitWindowSize(width, height);
            glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
            glutCreateWindow(charTitle);

            // Resolve style issues (remove sizeable border & maximize button)
            HWND freeWindow = FindWindow("FreeGLUT", charTitle);
            long Style = GetWindowLong(freeWindow, GWL_STYLE);
            Style &= ~(WS_MAXIMIZE|WS_SIZEBOX);
            SetWindowLong(freeWindow, GWL_STYLE, Style);

            // Initialize timer (frame rate controller)
            Plus::Graphics::timer = new Timer();
            Plus::Graphics::timer->start();
        }

        /*
         * Initialize graphics specifying only window dimensions
         * 
         * @param unsigned int Screen width
         * @param unsigned int Screen height
         * @return void
         */
        void initialize(unsigned int width, unsigned int height){
            initialize(width, height, Plus::Config::getTitle());
        }

        /*
         * Initialize graphics specifying only a different title
         * 
         * @param std::string Title
         * @return void
         */
        void initialize(std::string title){
            initialize(PLUS_GRAPHICS_WIDTH, PLUS_GRAPHICS_HEIGHT, title);
        }

        /*
         * Initialize graphics with default values
         * 
         * @return void
         */
        void initialize(){
            initialize(PLUS_GRAPHICS_WIDTH, PLUS_GRAPHICS_HEIGHT, Plus::Config::getTitle());
        }

        /*
         * Get screen width
         * 
         * @return unsigned int Width
         */
        unsigned int getWidth(){
            return Plus::Graphics::width;
        }

        /*
         * Get screen height
         * 
         * @return unsigned int Height
         */
        unsigned int getHeight(){
            return Plus::Graphics::height;
        }

        /*
         * Set screen brightness. All graph element will be rendered
         * with opacity multiplied by 255/Plus::Graphics::brightness.
         * 
         * @param unsigned char New brightness 
         * @return void
         */
        void setBrightness(unsigned char brightness){
            Plus::Graphics::brightness = brightness;
        }

        /*
         * Graphic update rate. Frames per second.
         * 
         * @param unsigned int New frame rate
         */
        void setFrameRate(unsigned int framerate){
            Plus::Graphics::frameRate = framerate;
            Plus::Graphics::microsecByFrame = (1000000/(double)framerate);
        }

        /*
         * Get graphics actual brightness.
         * 
         * @return unsigned char Brightness
         */
        unsigned char getBrightness(){
            return Plus::Graphics::brightness;
        };

        /*
         * Get graphics actual frame rate
         * 
         * @return unsigned int Frame rate in frames per second.
         */
        unsigned int  getFrameRate(){
            return Plus::Graphics::frameRate;
        };

        /*
         * Realizes real updating of graphics and frame control.
         * 
         * @return void
         */
        void update(){
            glutMainLoopEvent();

            
            // Correct? (Probably not)
            if (Plus::Graphics::timer->getElapsedTimeInMicroSec() > Plus::Graphics::microsecByFrame){
                Plus::Graphics::timer->reset();
            }
        };

        /*
         * Sleep by a moment, without letting graphics die
         * 
         * @param unsigned int Frames to wait
         * @return void
         */
        void wait(unsigned int duration){
            for (duration; duration > 0; duration--)
                Graphics::update();
        };

        /*
         * Fade in all graphics
         * 
         * @param unsigned int Duration in frames of the fade.
         * @return void
         */
        void fadein(unsigned int duration){
            // TODO
        };

        /*
         * Fade out all graphics
         * 
         * @param unsigned int Duration in frames of the fade.
         * @return void
         */
        void fadeout(unsigned int duration){
            // TODO
        };

        /*
         * Resize screen to specified width/height.
         * 
         * @param unsigned short New width
         * @param unsigned short New height
         */
        void resizeScreen(unsigned short width, unsigned short height){
            // TODO
        };

        /*
         * Play movie on the screen
         * 
         * @param std::string Movie filename
         */
        void playMovie(std::string filename){
            // TODO
        };
    };
};