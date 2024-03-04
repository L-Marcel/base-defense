#include "../../include/Engine.hpp"
#define PI 3.14159265359

namespace lm {
  Vector<float> pointInRadious(double radious, double angle) {
    float rad = angle * (PI / 180);
    float y = sinf(rad) * radious;
    float x = cosf(rad) * radious;

    return Vector<float>(x, y);
  };

  double pointDirection(float x, float y) {
    double rad = atan2(y, x);
    return fmod((rad * (180/PI)), 360);
  };
};