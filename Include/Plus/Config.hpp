/* 
 * File:   Config.hpp
 * Author: Gab
 *
 * Created on 5 de Maio de 2013, 13:35
 */

#ifndef CONFIG_HPP
#define	CONFIG_HPP

#include <Plus.hpp>

namespace Plus {
    class _MConfig {
        public:
            void initialize();
            std::string getTitle();
            
        private:
            CSimpleIni* iniParser;
    };
}

#endif	/* CONFIG_HPP */

