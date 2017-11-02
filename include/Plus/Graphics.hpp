#ifndef PLUS_GRAPHICS_HPP
#define	PLUS_GRAPHICS_HPP

namespace Plus {
    class _MGraphics {
        public:
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
            void addObject(Drawable* object);
            void removeObject(Drawable* object);
            void update();
            void wait(unsigned int duration);
            void fadein(unsigned int duration);
            void fadeout(unsigned int duration);
            void resizeScreen(unsigned short width, unsigned short height);
            void playMovie(std::string filename);

        private:
            unsigned int width;
            unsigned int height;
            string title;
            unsigned char brightness;
            unsigned int  frameRate;
            Timer* timer;
            double microsecByFrame;
            stack<Drawable*>* objects;
    };
};

#endif	/* PLUS_GRAPHICS_HPP */

