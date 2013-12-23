/* 
 * File:   RGSSReset.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 01:51
 */

#ifndef RGSSRESET_HPP
#define	RGSSRESET_HPP

namespace Plus {
    class RGSSReset {
    public:
        RGSSReset();
        std::string getMessage();
        void setMessage(std::string message);
        ~RGSSReset();
    private:
        std::string message;
    };
};

#endif	/* RGSSRESET_HPP */

