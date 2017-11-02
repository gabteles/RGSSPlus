#ifndef PLUS_RGSSRESET_HPP
#define	PLUS_RGSSRESET_HPP

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

#endif	/* PLUS_RGSSRESET_HPP */

