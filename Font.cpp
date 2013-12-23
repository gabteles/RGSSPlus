/* 
 * File:   Font.cpp
 * Author: Gab
 * 
 * Created on 24 de Janeiro de 2013, 01:38
 */

#include <Plus.hpp>

namespace Plus {    
    /*
     * Create a new font based on default attributes
     * 
     * @return Plus::Font New Font
     */
    Font::Font(){
        Font(Font::Default().getName(), Font::Default().getSize());
    }

    /*
     * Create new font with a different name
     * 
     * @param std::string Font name
     * @return Plus::Font New font
     */
    Font::Font(std::string name){
        Font(name, Font::Default().getSize());
    }

    /*
     * Create new font with different name and size
     * 
     * @param std::string Font name
     * @param uchar Font Size
     * @return New font
     */
    Font::Font(std::string name, unsigned char size){
        this->name     = name; // TODO: Check if font exist
        this->size     = size;
        this->color    = Font::Default().getColor();
        this->bold     = Font::Default().getBold();
        this->italic   = Font::Default().getItalic();
        this->outline  = Font::Default().getOutline();
        this->outColor = Font::Default().getOutColor();
    }

    /*
     * Get font name
     * 
     * @return std::string Font name
     */
    std::string Font::getName(){
        return this->name;
    }

    /*
     * Set font name
     * 
     * @param std::string New font name
     * @return void
     */
    void Font::setName(std::string name){
        this->name = name; // TODO: Check if font exist
    }

    /*
     * Get font size
     * 
     * @return uchar Font size
     */
    unsigned char Font::getSize(){
        return this->size;
    }

    /*
     * Set font size
     * 
     * @param uchar New font size
     * @return void
     */
    void Font::setSize(unsigned char size){
        this->size = size;
    }

    /*
     * Get font color
     * 
     * @return Plus::Color Font Color
     */
    Plus::Color* Font::getColor(){
        return this->color;
    }

    /*
     * Set font color
     * 
     * @param Plus::Color New font color
     * @return void
     */
    void Font::setColor(Plus::Color* color){
        this->color = color;
    }

    /*
     * Get font bold state
     * 
     * @return bool Font bold state
     */
    bool Font::getBold(){
        return this->bold;
    }

    /*
     * Set font bold state
     * 
     * @param bool New font bold state
     * @return void
     */
    void Font::setBold(bool bold){
        this->bold = bold;
    }

    /*
     * Get font italic state
     * 
     * @return bool Font italic state
     */
    bool Font::getItalic(){
        return this->italic;
    }

    /*
     * Set font italic state
     * 
     * @param bool New font italic state
     * @return void
     */
    void Font::setItalic(bool italic){
        this->italic = italic;
    }

    /*
     * Get font shadow state
     * 
     * @return bool Font shadow state
     */
    bool Font::getShadow(){
        return this->shadow;
    }

    /*
     * Set font shadow state
     * 
     * @param bool New font shadow state
     * @return void
     */
    void Font::setShadow(bool shadow){
        this->shadow = shadow;
    }

    /*
     * Get font outline state
     * 
     * @return bool Font outline state
     */
    bool Font::getOutline(){
        return this->outline;
    }

    /*
     * Set font outline state
     * 
     * @param bool New font outline state
     * @return void
     */
    void Font::setOutline(bool outline){
        this->outline = outline;
    }

    /*
     * Get font outline color
     * 
     * @return Plus::Color Font outline color
     */
    Plus::Color* Font::getOutColor(){
        return this->outColor;
    }

    /*
     * Set font outline color
     * 
     * @param Plus::Color New outline color
     * @return void 
     */
    void Font::setOutColor(Plus::Color* outColor){
        this->outColor = outColor;
    }

    /*
     * Destructor
     */
    Font::~Font() {

    }
};

