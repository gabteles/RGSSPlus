#ifndef PLUS_INPUT_HPP
#define	PLUS_INPUT_HPP

namespace Plus {
    class _MInput {
        public:
            void update();
            bool checkTrigger(unsigned char key);
            bool checkPress(unsigned char key);
            bool checkRepeat(unsigned char key);
            unsigned char dir4();
            unsigned char dir8();
    };
};

#endif	/* PLUS_INPUT_HPP */

