#ifndef PLUS_CONFIG_HPP
#define	PLUS_CONFIG_HPP

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

#endif	/* PLUS_CONFIG_HPP */

