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
    sprite->setBitmap(new Plus::Bitmap("img-thing.jpg"));
    double k = 0.1;

    float baseX = Plus::Graphics.getWidth() / 2;
    float baseY = Plus::Graphics.getHeight() / 2;

    sprite->setX(baseX + sprite->getWidth() / 2);
    sprite->setY(baseY);
    sprite->setOx(sprite->getWidth() / 2);
    sprite->setOy(sprite->getHeight() / 2);

    Plus::Rect *srcRect = new Plus::Rect(0, 0, 150, 150);
    sprite->setSrcRect(srcRect);

    sprite->setWaveSpeed(5);
    sprite->setWaveLength(75);
    sprite->setWavePhase(90);
    sprite->setWaveAmp(5);

    sprite->setColor(new Plus::Color(127, 0, 0, 100));
    sprite->setTone(new Plus::Tone(0, 0, 0, 0));

    sprite->setMirror(true);

    sprite->setBlendType(1);

    Plus::Sprite *sprite2 = new Plus::Sprite();
    sprite2->setBitmap(new Plus::Bitmap("img-thing.jpg"));
    sprite2->setX(baseX);
    sprite2->setY(baseY);
    sprite2->setOx(sprite2->getWidth() / 2);
    sprite2->setOy(sprite2->getHeight() / 2);

    while (true) {
        k += 1;
        Plus::Graphics.update();
        sprite->update();
        sprite->setAngle(2.5 * sin(4*k*M_PI/180.0));
        sprite->setOpacity(255 * abs(sin(k*M_PI/180.0)));
        sprite->setZoomX(1 + 0.03 * sin(k*M_PI/180.0));
        sprite->setZoomY(1 + 0.03 * sin(k*M_PI/180.0));
        //sprite->setX(baseX + 100 * sin(k*M_PI/180.0));
        //sprite->setY(baseY + 100 * cos(k*M_PI/180.0));

        bool isVisible = sprite->getOpacity() <= 200;
        //sprite->setVisible(isVisible);
    }

    return 0;
}
