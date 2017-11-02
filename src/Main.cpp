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
    double k = 0.1;

    float baseX = Plus::Graphics.getWidth() / 2;
    float baseY = Plus::Graphics.getHeight() / 2;

    sprite->setX(baseX);
    sprite->setY(baseY);
    sprite->setOx(sprite->getWidth() / 2);
    sprite->setOy(sprite->getHeight() / 2);

    while (k += 0.000001){
        Plus::Graphics.update();
        sprite->setAngle(k*10);
        sprite->setX(baseX + 50 * cos(k) + ((Plus::Graphics.getWidth() - sprite->bitmap->getWidth()) / 2));
        sprite->setY(baseY + 50 * sin(k));
    }

    return 0;
}
