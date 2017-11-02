#ifndef PLUS_RECT_HPP
#define	PLUS_RECT_HPP

#include <Plus.hpp>

namespace Plus {
    class Rect {
        struct packedRect{
            int x;
            int y;
            int width;
            int height;
        };

    public:
        Rect();
        Rect(int x, int y, int width, int height);
        int getX();
        void setX(int x);
        int getY();
        void setY(int y);
        int getWidth();
        void setWidth(int width);
        int getHeight();
        void setHeight(int height);
        void empty();
        packedRect dump();
        void load(packedRect pack);
        ~Rect();

    private:
        int x, y, w, h;
    };
};

#endif	/* PLUS_RECT_HPP */

