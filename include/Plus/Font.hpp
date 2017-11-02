#ifndef PLUS_FONT_HPP
#define	PLUS_FONT_HPP

#include <Plus.hpp>


namespace Plus {
    class Font {
    public:
        static Font& Default(){
            static Font DefaultFont;
            return DefaultFont;
        }

        static bool exist(std::string name){
            return true;
        }

        Font();
        Font(std::string name);
        Font(std::string name, unsigned char size);
        std::string getName();
        void setName(std::string name);
        unsigned char getSize();
        void setSize(unsigned char size);
        Plus::Color* getColor();
        void setColor(Plus::Color* color);
        bool getBold();
        void setBold(bool bold);
        bool getItalic();
        void setItalic(bool italic);
        bool getShadow();
        void setShadow(bool shadow);
        bool getOutline();
        void setOutline(bool outline);
        Plus::Color* getOutColor();
        void setOutColor(Plus::Color* outColor);

        ~Font();

    private:
        std::string name;
        unsigned int size;
        Plus::Color* color;
        bool bold;
        bool italic;
        bool shadow;
        bool outline;
        Plus::Color* outColor;

    };
};

#endif	/* PLUS_FONT_HPP */

