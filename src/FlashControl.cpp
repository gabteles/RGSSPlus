#include <Plus.hpp>

namespace Plus {
  FlashControl::FlashControl() {
    this->flashing = false;
    this->color = Plus::Color();
  }

  void FlashControl::start(const Plus::Color *color, unsigned int duration) {
    if (duration < 1)
      return;

    if (!color)
      return;

    this->flashing = true;
    this->duration = duration;
    this->counter = 0;
    this->color = *color;
    this->flashAlpha = this->color.getAlpha();
  }

  void FlashControl::update() {
    if (!this->flashing)
      return;

    if (++counter > duration) {
      this->flashing = false;
      return;
    }

    float prog = (float) this->counter / this->duration;
    this->color.setAlpha(this->flashAlpha * (1 - prog));
  }

  bool FlashControl::isFlashing() {
    return this->flashing;
  }

  Plus::Color FlashControl::getColor() {
    return this->color;
  }
}
