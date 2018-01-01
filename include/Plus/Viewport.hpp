#ifndef PLUS_VIEWPORT_HPP
#define	PLUS_VIEWPORT_HPP

#include <Plus.hpp>

namespace Plus {
    class Viewport {
        struct ShaderData {
            unsigned int program;
            unsigned int toneLoc;
            unsigned int colorLoc;
            unsigned int flashLoc;
        };

    public:
        static Plus::Viewport* getDefault();
        static Plus::Viewport* DefaultViewport;
        static ShaderData* getShaderData();
        static ShaderData* shaderData;

        Viewport();
        Viewport(Plus::Rect* rect);
        Viewport(int x, int y, int width, int height);
        void dispose();
        bool disposed();
        void flash(const Plus::Color* color, unsigned int duration);
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
        void drawInnerObjects();
        bool shouldResizeBuffer();

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

        int bufferWidth;
        int bufferHeight;

        Plus::FlashControl* flashControl;
    };
};

#endif	/* PLUS_VIEWPORT_HPP */

