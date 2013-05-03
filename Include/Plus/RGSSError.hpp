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
                string getMessage();
                void setMessage(string message);
                ~RGSSError();
        private:
                string message;
        };
};

#endif	/* RGSSERROR_HPP */

