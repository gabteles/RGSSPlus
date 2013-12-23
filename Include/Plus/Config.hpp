/* 
 * File:   Config.hpp
 * Author: Gab
 *
 * Created on 5 de Maio de 2013, 13:35
 */

#ifndef CONFIG_HPP

#include <Plus.hpp>

namespace Plus {
    namespace Config {
        static CSimpleIni* iniParser;

        void initialize();
        std::string getTitle();
    }
}
#define	CONFIG_HPP



#endif	/* CONFIG_HPP */

