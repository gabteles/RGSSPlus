#ifndef PLUS_FLASH_CONTROL_HPP
#define PLUS_FLASH_CONTROL_HPP

namespace Plus {
    class FlashControl {
        public:
            FlashControl();
            void start(const Plus::Color* color, unsigned int duration);
            void update();
            bool isFlashing();
            Plus::Color getColor();

        private:
            bool flashing;
            unsigned int counter;
            unsigned int duration;
            Plus::Color color;
            float flashAlpha;
    };
};

#endif  /* PLUS_FLASH_CONTROL_HPP */

