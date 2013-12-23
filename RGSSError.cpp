/* 
 * File:   RGSSError.cpp
 * Author: Gab
 * 
 * Created on 24 de Janeiro de 2013, 01:42
 */

#include <Plus.hpp>

namespace Plus {
    /*
     * Constructor
     */
    RGSSError::RGSSError() {
    }

    /*
     * Gets the message stored
     * 
     * @return std::string Message
     */
    std::string RGSSError::getMessage(){
        return this->message;
    }

    /*
     * Stores a new message
     * 
     * @param std::string New message
     * @return void
     */
    void RGSSError::setMessage(std::string message){
        this->message = message;
    }

    /*
     * Destructor
     */
    RGSSError::~RGSSError() {
    }
};


