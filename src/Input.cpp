#include <Plus.hpp>

namespace Plus {

    /*
     * Update pressed keys
     *
     * @return void
     */
    void _MInput::update(){
        // TODO
    }

    /*
     * Verify if a key was pressed in the last update
     *
     * @param uchar Key's ASCII code
     *
     * @return bool Key state
     */
    bool _MInput::checkTrigger(unsigned char key){
        return false; // TODO
    }

    /*
     * Verify if a key is pressed
     *
     * @param uchar Key's ASCII code
     *
     * @return bool Key state
     */
    bool _MInput::checkPress(unsigned char key){
        return false; // TODO
    }

    /*
     * Verify if a key is pressed, returning alternate values.
     * Update 1    - True
     * Update 2~14 - False
     * Update 15+  - Letting n be the number of updates that the key
     *               remains pressed, function will return !(n % 2)
     *
     * @param uchar Key's ASCII code
     *
     * @return bool Key state
     */
    bool _MInput::checkRepeat(unsigned char key){
        return false; // TODO
    }

    /*
     * Check the direction wish the user is pressing
     * 0 - None
     * 2 - Down
     * 4 - Left
     * 6 - Right
     * 8 - Up
     *
     * @return uchar Pressing direction
     */
    unsigned char _MInput::dir4(){
        return 0; // TODO
    }

    /*
     * Check the direction that the user is pressing, but with 9
     * possibilities:
     *
     * 0 - None
     * 1 - Left-Down
     * 2 - Down
     * 3 - Right-Down
     * 4 - Left
     * 5 - Left-Up
     * 6 - Right
     * 7 - Right-Up
     * 8 - Up
     *
     * @return uchar Pressing direction
     */
    unsigned char _MInput::dir8(){
        return 0; // TODO
    }
};
