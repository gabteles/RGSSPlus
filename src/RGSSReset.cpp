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
    std::string RGSSReset::getMessage(){
        return this->message;
    }

    /*
     * Stores a new message
     *
     * @param std::string New message
     * @return void
     */
    void RGSSReset::setMessage(std::string message){
        this->message = message;
    }

    /*
     * Destructor
     */
    RGSSReset::~RGSSReset() {
    }
};
