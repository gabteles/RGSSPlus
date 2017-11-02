/*
 * File:   Plus.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 01:22
 */

#ifndef PLUS_HPP
#define	PLUS_HPP

/* Macros */
#define EXPORT(x) extern "C" x __declspec(dllexport)
#define IMPORT(x) extern "C" x __declspec(dllimport)

#ifdef BUILDING_PLUS
#define EXTFUNC(x) EXPORT(x)
#else
#define EXTFUNC(x) IMPORT(x)
#endif

/* Compilation Options */
#define PLUS_GRAPHICS_WIDTH  640        /* Default graphics width  */
#define PLUS_GRAPHICS_HEIGHT 480        /* Default graphics height */
#define PLUS_DEFAULT_TITLE   "RGSS+"    /* Default title */
#define PLUS_CONFIG_FILE     "Game.ini" /* Configuration file. (Ini sintax) */
#define PLUS_TABLE_ENABLE_DIM_CHECK 1   /* Enable dimension checking on get/set
                                         * of elements on Plus::Table. It'll
                                         * prevent erroneous acesses, but disabling
                                         * it can save a little bit (really little)
                                         * of processing on various gets/sets seqs.
                                         */

/* Libraries Compilation Options */
//#define FREEGLUT_STATIC

/* Standard Includes */
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <functional>
#include <math.h>

/* Library Includes */
#include <GL/freeglut.h>         // GLUT
#include <SOIL/SOIL.h>           // SOIL
#include <GL/gl.h>               // GL
#include <SimpleIni/SimpleIni.h> // SimpleIni
#include <Timer/Timer.h>         // Timer

/* Plus Namespace definition */
namespace Plus {
    using std::string;
    using std::stringstream;
    using std::stack;

    class Bitmap;
    class Color;
    class Drawable;
    class Font;
    class Plane;
    class RGSSError;
    class RGSSReset;
    class Rect;
    class Sprite;
    class Table;
    class Tone;
    class Viewport;

    class _MAudio;
    class _MInput;
    class _MGraphics;
    class _MConfig;

    extern _MAudio    Audio;
    extern _MInput    Input;
    extern _MGraphics Graphics;
    extern _MConfig   Config;
};

/* Plus Includes */

// Classes
#include <Plus/Config.hpp>
#include <Plus/RGSSError.hpp>
#include <Plus/RGSSReset.hpp>
#include <Plus/Table.hpp>
#include <Plus/Color.hpp>
#include <Plus/Tone.hpp>
#include <Plus/Font.hpp>
#include <Plus/Rect.hpp>
#include <Plus/Bitmap.hpp>
#include <Plus/Viewport.hpp>
#include <Plus/Drawable.hpp>
#include <Plus/Plane.hpp>
#include <Plus/Sprite.hpp>
// Modules
#include <Plus/Audio.hpp>
#include <Plus/Graphics.hpp>
#include <Plus/Input.hpp>

#endif	/* PLUS_HPP */

