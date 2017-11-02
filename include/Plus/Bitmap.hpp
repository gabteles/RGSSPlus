#ifndef PLUS_BITMAP_HPP
#define	PLUS_BITMAP_HPP

#include "Rect.hpp"


namespace Plus {
    class Bitmap {
    public:
        Bitmap(std::string filename);
        Bitmap(unsigned int width, unsigned int height);
        unsigned int getTextureId();
        unsigned int getWidth();
        unsigned int getHeight();
        void dispose();
        bool isDisposed();
        void blt(int x, int y, Plus::Bitmap srcBitmap, Plus::Rect srcRect);
        void blt(int x, int y, Plus::Bitmap srcBitmap, Plus::Rect srcRect, unsigned char opacity);
        void stretchBlt(Plus::Rect destRect, Plus::Bitmap srcBitmap, Plus::Rect srcRect);
        void stretchBlt(Plus::Rect destRect, Plus::Bitmap srcBitmap, Plus::Rect srcRect, unsigned char opacity);
        void fillRect(int x, int y, unsigned int width, unsigned int height, Plus::Color color);
        void fillRect(Plus::Rect rect, Plus::Color color);
        void gradientFillRect(int x, int y, unsigned int width, unsigned int height, Plus::Color color1, Plus::Color color2);
        void gradientFillRect(Plus::Rect rect, Plus::Color color1, Plus::Color color2);
        void clear();
        void clearRect(int x, int y, unsigned int width, unsigned int height);
        void clearRect(Plus::Rect rect);
        Plus::Color getPixel(unsigned int x, unsigned int y);
        void setPixel(unsigned int x, unsigned int y, Plus::Color color);
        void hueChange(int angle);
        void blur();
        void radialBlur(int angle, int division);
        void drawText(int x, int y, unsigned int width, unsigned int height, std::string text);
        void drawText(int x, int y, unsigned int width, unsigned int height, std::string text, unsigned char align);
        void drawText(Plus::Rect rect, std::string text);
        void drawText(Plus::Rect rect, std::string text, unsigned char align);
        Plus::Rect textSize(std::string text);
        ~Bitmap();

    private:
        unsigned int width;
        unsigned int height;
        bool _disposed;
        unsigned int textureId;
    };
};

#endif	/* PLUS_BITMAP_HPP */

