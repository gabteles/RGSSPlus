/* 
 * File:   Graphics.cpp
 * Author: Gab
 * 
 * Created on 05 de Maio de 2013, 14:02
 */

#include <Plus.hpp>

namespace Plus {
    _MConfig Config;
    
    /*
     * Initialize configuration parser
     * 
     * @return void
     */
    void _MConfig::initialize(){
        this->iniParser = new CSimpleIniA();
        this->iniParser->SetUnicode();
        this->iniParser->LoadFile(PLUS_CONFIG_FILE);
    }

    /*
     * Get game's title
     * 
     * @return std::string Title key on configuration file
     */
    std::string _MConfig::getTitle(){
        return this->iniParser->GetValue("Game", "Title", PLUS_DEFAULT_TITLE);
    }
}