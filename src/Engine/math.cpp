#include "../../include/Engine.hpp"
#define PI 3.14159265359

namespace lm {
  Coord::Coord(float x, float y) : sf::Vector2f(x, y) {};

  Coord pointInRadious(double radious, double angle) {
    float rad = angle * (PI / 180);
    float y = sinf(rad) * radious;
    float x = cosf(rad) * radious;

    return Coord(x, y);
  };

  double pointDirection(float x, float y) {
    double rad = atan2(x, y);
    cout << "(" << x << ", " << y << ") -> " << rad << endl;
    return fmod((rad * (180/PI)), 360);
  };
};