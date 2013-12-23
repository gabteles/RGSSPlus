/* 
 * File:   Bitmap.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 01:26
 */

#ifndef BITMAP_HPP
#define	BITMAP_HPP

#include "Rect.hpp"


namespace Plus {
    class Bitmap {
    public:
        /* Functions */
        Bitmap(std::string filename);
        Bitmap(unsigned int width, unsigned int height);
        unsigned int getWidth();
        unsigned int getHeight();
        void dispose();
        bool disposed();
        void blt(int x, int y, Plus::Bitmap src_bitmap, Plus::Rect src_rect);
        void blt(int x, int y, Plus::Bitmap src_bitmap, Plus::Rect src_rect, unsigned char opacity);
        void stretch_blt(Plus::Rect dest_rect, Plus::Bitmap src_bitmap, Plus::Rect src_rect);
        void stretch_blt(Plus::Rect dest_rect, Plus::Bitmap src_bitmap, Plus::Rect src_rect, unsigned char opacity);
        void fill_rect(int x, int y, unsigned int width, unsigned int height, Plus::Color color);
        void fill_rect(Plus::Rect rect, Plus::Color color);
        void gradient_fill_rect(int x, int y, unsigned int width, unsigned int height, Plus::Color color1, Plus::Color color2);
        void gradient_fill_rect(Plus::Rect rect, Plus::Color color1, Plus::Color color2);
        void clear();
        void clear_rect(int x, int y, unsigned int width, unsigned int height);
        void clear_rect(Plus::Rect rect);
        Plus::Color get_pixel(unsigned int x, unsigned int y);
        void set_pixel(unsigned int x, unsigned int y, Plus::Color color);
        void hue_change(int angle);
        void blur();
        void radial_blur(int angle, int division);
        void draw_text(int x, int y, unsigned int width, unsigned int height, std::string text);
        void draw_text(int x, int y, unsigned int width, unsigned int height, std::string text, unsigned char align);
        void draw_text(Plus::Rect rect, std::string text);
        void draw_text(Plus::Rect rect, std::string text, unsigned char align);
        Plus::Rect text_size(std::string text);
        ~Bitmap();
        
    private:
        unsigned int width;
        unsigned int height;
        bool _disposed;
    };
};

#endif	/* BITMAP_HPP */

