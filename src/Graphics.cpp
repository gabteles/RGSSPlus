#include <Plus.hpp>

namespace Plus {
    _MGraphics Graphics;

    /*
     * Initialize graphics routines
     *
     * @param unsigned int Screen width
     * @param unsigned int Screen height
     * @param std::string Window title
     * @return void
     */
    void _MGraphics::initialize(unsigned int width, unsigned int height, std::string title){
        // Save Graphics size and title
        this->width  = width;
        this->height = height;
        this->title  = title;

        // Start other variables
        this->brightness = 255;
        this->frameRate  = 60;
        this->microsecByFrame = 1000000/60.f;
        this->objects = new stack<Drawable*>();

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
        //HWND freeWindow = FindWindow("FreeGLUT", charTitle);
        //long Style = GetWindowLong(freeWindow, GWL_STYLE);
        //Style &= ~(WS_MAXIMIZE|WS_SIZEBOX);
        //SetWindowLong(freeWindow, GWL_STYLE, Style);

        // GL Configuration
        glViewport(0, 0, width, height);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, width, 0, height);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClearDepth(1.0f);
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
        glDepthFunc(GL_LEQUAL);

        // Initialize timer (frame rate controller)
        this->timer = new Timer();
        this->timer->start();
    }

    /*
     * Initialize graphics specifying only window dimensions
     *
     * @param unsigned int Screen width
     * @param unsigned int Screen height
     * @return void
     */
    void _MGraphics::initialize(unsigned int width, unsigned int height){
        initialize(width, height, Plus::Config.getTitle());
    }

    /*
     * Initialize graphics specifying only a different title
     *
     * @param std::string Title
     * @return void
     */
    void _MGraphics::initialize(std::string title){
        initialize(PLUS_GRAPHICS_WIDTH, PLUS_GRAPHICS_HEIGHT, title);
    }

    /*
     * Initialize graphics with default values
     *
     * @return void
     */
    void _MGraphics::initialize(){
        initialize(PLUS_GRAPHICS_WIDTH, PLUS_GRAPHICS_HEIGHT, Plus::Config.getTitle());
    }

    /*
     * Get screen width
     *
     * @return unsigned int Width
     */
    unsigned int _MGraphics::getWidth(){
        return this->width;
    }

    /*
     * Get screen height
     *
     * @return unsigned int Height
     */
    unsigned int _MGraphics::getHeight(){
        return this->height;
    }

    /*
     * Set screen brightness. All graph element will be rendered
     * with opacity multiplied by 255/Plus::Graphics::brightness.
     *
     * @param unsigned char New brightness
     * @return void
     */
    void _MGraphics::setBrightness(unsigned char brightness){
        this->brightness = brightness;
    }

    /*
     * Graphic update rate. Frames per second.
     *
     * @param unsigned int New frame rate
     */
    void _MGraphics::setFrameRate(unsigned int framerate){
        this->frameRate = framerate;
        this->microsecByFrame = (1000000/(double)framerate);
    }

    /*
     * Get graphics actual brightness.
     *
     * @return unsigned char Brightness
     */
    unsigned char _MGraphics::getBrightness(){
        return this->brightness;
    };

    /*
     * Get graphics actual [target] frame rate
     *
     * @return unsigned int Frame rate in frames per second.
     */
    unsigned int _MGraphics::getFrameRate(){
        return this->frameRate;
    };

    /*
     * Add Drawable object to be updated with the graphics
     *
     * @param  Drawable* Object to add
     * @return void
     */
    void _MGraphics::addObject(Drawable* object){
        this->objects->push(object);
    }

    /*
     * Remove Drawable object
     *
     * @param  Drawable* Object to remove
     * @return void
     */
    void _MGraphics::removeObject(Drawable* object){
        Drawable* aObj;
        for (register unsigned int i = 0; i < this->objects->size(); i++) {
                aObj = this->objects->top();
                this->objects->pop();

                if (aObj == object) return;

                this->objects->push(aObj);
        }
    }

    /*
     * Realizes real updating of graphics and frame control.
     *
     * @return void
     */
    void _MGraphics::update(){
        glutMainLoopEvent();

        // Correct frame rating? (Probably not)
        if (this->timer->getElapsedTimeInMicroSec() > this->microsecByFrame){
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

            Drawable* aObj;
            for (register unsigned int i = 0; i < this->objects->size(); i++) {
                glLoadIdentity(); // Reset matrix for each Drawable

                aObj = this->objects->top();
                this->objects->pop();
                aObj->draw();
                this->objects->push(aObj);
            }

            glutSwapBuffers();
            this->timer->reset();
        }
    };

    /*
     * Sleep by a moment, without letting graphics die
     *
     * @param unsigned int Frames to wait
     * @return void
     */
    void _MGraphics::wait(unsigned int duration){
        for (duration; duration > 0; duration--)
            this->update();
    };

    /*
     * Fade in all graphics
     *
     * @param unsigned int Duration in frames of the fade.
     * @return void
     */
    void _MGraphics::fadein(unsigned int duration){
        // TODO
    };

    /*
     * Fade out all graphics
     *
     * @param unsigned int Duration in frames of the fade.
     * @return void
     */
    void _MGraphics::fadeout(unsigned int duration){
        // TODO
    };

    /*
     * Resize screen to specified width/height.
     *
     * @param int New width
     * @param int New height
     */
    void _MGraphics::resizeScreen(int width, int height){
        std::cout << std::endl << "Resized: " << width << ", " << height << std::endl;
        // GL Resize
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, width, 0, height);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // TODO: Window Resize
    };

    /*
     * Play movie on the screen
     *
     * @param std::string Movie filename
     */
    void _MGraphics::playMovie(std::string filename){
        // TODO
    };
};
