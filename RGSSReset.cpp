/* 
 * File:   RGSSReset.cpp
 * Author: Gab
 * 
 * Created on 24 de Janeiro de 2013, 01:51
 */

#include <Plus.hpp>

namespace Plus {
        /*
         * Constructor
         */
        RGSSReset::RGSSReset() {
        }

        /*
         * Gets the message stored
         * 
         * @return std::string Message
         */
        string RGSSReset::getMessage(){
            return this->message;
        }
        
        /*
         * Stores a new message
         * 
         * @param std::string New message
         * @return void
         */
        void RGSSReset::setMessage(string message){
            this->message = message;
        }
        
        /*
         * Destructor
         */
        RGSSReset::~RGSSReset() {
        }
};
