/* 
 * File:   Viewport.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 02:05
 */

#ifndef VIEWPORT_HPP
#define	VIEWPORT_HPP

namespace Plus {
    class Viewport {
    public:
        Viewport();
        Viewport(Plus::Rect);
        Viewport(int x, int y, int width, int height);
        void dispose();
        bool disposed();
        void flash(Plus::Color color, unsigned int duration);
        void update();
        ~Viewport();
    private:

    };
};

#endif	/* VIEWPORT_HPP */

