#include <Misc/timer.hpp>

namespace Game {
  void Timer::start(float duration) {
    this->duration = duration;
    this->time = 0;
  };

  void Timer::tick() {
    this->time = clamp(this->time + 1/60.f, 0.f, duration);
  };

  bool Timer::isFinished() {
    return this->time == this->duration;
  };
};