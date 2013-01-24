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

/* Standard Includes */
#include <iostream>
#include <string>

/* Plus Namespace definition */
namespace Plus {
    using std::string;
    
    class Bitmap;
    class Color;
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
    namespace RPG{};
};

/* Plus Includes */
#include <Plus/Bitmap.hpp>    // =
#include <Plus/Color.hpp>     // |
#include <Plus/Font.hpp>      // |
#include <Plus/Plane.hpp>     // |
#include <Plus/RGSSError.hpp> // |
#include <Plus/RGSSReset.hpp> // | Classes
#include <Plus/Rect.hpp>      // |
#include <Plus/Sprite.hpp>    // |
#include <Plus/Table.hpp>     // |
#include <Plus/Tone.hpp>      // |
#include <Plus/Viewport.hpp>  // =

#include <Plus/Audio.hpp>     // =
#include <Plus/Graphics.hpp>  // | Modules
#include <Plus/Input.hpp>     // |
#include <Plus/RPG.hpp>       // =

#endif	/* PLUS_HPP */

