#include <Misc/timer.hpp>

namespace Game {
  void Timer::setDuration(float duration) {
    this->duration = duration;
  };

  void Timer::start() {
    if(!this->isFinished()) {
      this->time = clamp(this->time + 1/60.f, 0.f, duration);
    };
  };

  bool Timer::isFinished() {
    bool timeFinished = this->time == this->duration;
    return timeFinished;
  };
};