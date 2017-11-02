#ifndef PLUS_RGSSERROR_HPP
#define	PLUS_RGSSERROR_HPP

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

#endif	/* PLUS_RGSSERROR_HPP */

