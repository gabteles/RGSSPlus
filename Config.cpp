/* 
 * File:   Graphics.cpp
 * Author: Gab
 * 
 * Created on 05 de Maio de 2013, 14:02
 */

#include <Plus.hpp>

namespace Plus {
    namespace Config {
        /*
         * Initialize configuration parser
         * 
         * @return void
         */
        void initialize(){
            iniParser = new CSimpleIniA();
            iniParser->SetUnicode();
            iniParser->LoadFile(PLUS_CONFIG_FILE);
        }

        /*
         * Get game's title
         * 
         * @return std::string Title key on configuration file
         */
        std::string getTitle(){
            return iniParser->GetValue("Game", "Title", PLUS_DEFAULT_TITLE);
        }
    }
}