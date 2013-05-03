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
#define PLUS_TABLE_ENABLE_DIM_CHECK 1 /* Enable dimension checking on get/set
                                       * of elements on Plus::Table. It'll 
                                       * prevent erroneous acesses, but disabling
                                       * it can save a little bit (really little) 
                                       * of processing on various gets/sets seqs.
                                       */                                      

/* Standard Includes */
#include <iostream>
#include <string>

/* Plus Namespace definition */
namespace Plus {
        using std::string;

        class Drawable;
        
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

        namespace Audio{};
        namespace Input{};
        namespace Graphics{};
};

/* Plus Includes */
#include <Plus/RGSSError.hpp> // =
#include <Plus/RGSSReset.hpp> // |
#include <Plus/Table.hpp>     // |
#include <Plus/Color.hpp>     // |
#include <Plus/Tone.hpp>      // |
#include <Plus/Font.hpp>      // |
#include <Plus/Rect.hpp>      // |
#include <Plus/Bitmap.hpp>    // | Classes
#include <Plus/Viewport.hpp>  // |
#include <Plus/Drawable.hpp>  // |
#include <Plus/Plane.hpp>     // |
#include <Plus/Sprite.hpp>    // =
#include <Plus/Audio.hpp>     // =
#include <Plus/Graphics.hpp>  // | Modules
#include <Plus/Input.hpp>     // =

#endif	/* PLUS_HPP */

