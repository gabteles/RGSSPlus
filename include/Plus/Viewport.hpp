#ifndef PLUS_VIEWPORT_HPP
#define	PLUS_VIEWPORT_HPP

#include <Plus.hpp>

namespace Plus {
    class Viewport {
    public:
        static Plus::Viewport* getDefault();
        static Plus::Viewport* DefaultViewport;

        Viewport();
        Viewport(Plus::Rect* rect);
        Viewport(int x, int y, int width, int height);
        void dispose();
        bool disposed();
        void flash(Plus::Color* color, unsigned int duration);
        void update();
        Plus::Color* getColor();
        Plus::Tone*  getTone();
        Plus::Rect*  getRect();
        bool getVisible();
        int getZ();
        int getOx();
        int getOy();
        void setColor(Plus::Color* color);
        void setTone(Plus::Tone* tone);
        void setRect(Plus::Rect* rect);
        void setVisible(bool visible);
        void setZ(int z);
        void setOx(int ox);
        void setOy(int oy);
        void addObject(Drawable* object);
        void removeObject(Drawable* object);
        void draw();
        ~Viewport();

    private:
        void createFBO();
        void createFboAttachments();

        Plus::Rect* rect;
        Plus::Color* color;
        Plus::Tone* tone;
        int z;
        int ox;
        int oy;
        bool _disposed;
        bool visible;
        forward_list<Drawable*>* objects;

        unsigned int framebuffer;
        unsigned int renderbuffer;
        unsigned int textureId;
    };
};

#endif	/* PLUS_VIEWPORT_HPP */

