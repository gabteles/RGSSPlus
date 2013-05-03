/* 
 * File:   Input.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 02:08
 */

#ifndef INPUT_HPP
#define	INPUT_HPP

namespace Plus {
        namespace Input {
                void update();
                bool trigger(unsigned char key);
                bool press(unsigned char key);
                bool repeat(unsigned char key);
                unsigned char dir4();
                unsigned char dir8();
        };
};

#endif	/* INPUT_HPP */

