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
        string getMessage();
        void setMessage(string);
        ~RGSSReset();
    private:
        string message;
    };
};

#endif	/* RGSSRESET_HPP */

