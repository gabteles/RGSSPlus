#include <Plus.hpp>

/*
 * Main function
 *
 * @param  int    argc Number of arguments passed
 * @param  char** argv Pointer to argument strings
 * @return int    Exit code
 */
int main(){
    Plus::Config.initialize();
    Plus::Graphics.initialize(544, 416);

    Plus::Sprite *sprite = new Plus::Sprite();
    sprite->setBitmap(new Plus::Bitmap("img.png"));
    sprite->setX((Plus::Graphics.getWidth() - sprite->bitmap->getWidth()) / 2);
    double k = 0.1;

    while (k += 0.000001){
        Plus::Graphics.update();
        sprite->setX(50 * cos(k) + ((Plus::Graphics.getWidth() - sprite->bitmap->getWidth()) / 2));
        sprite->setY(50 * sin(k));
    }

    return 0;
}
