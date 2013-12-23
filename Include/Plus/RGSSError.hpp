/* 
 * File:   RGSSError.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 01:42
 */

#ifndef RGSSERROR_HPP
#define	RGSSERROR_HPP

namespace Plus {
    class RGSSError {
    public:
        RGSSError();
        std::string getMessage();
        void setMessage(std::string message);
        ~RGSSError();
        
    private:
        std::string message;
    };
};

#endif	/* RGSSERROR_HPP */

