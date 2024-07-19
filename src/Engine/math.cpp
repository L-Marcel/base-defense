#include <Engine.hpp>
#define PI 3.14159265359

namespace Game {
  namespace Math {
    Vector<float> pointInRadius(double radius, double angle) {
      float rad = angle * (PI / 180);
      float y = sinf(rad) * radius;
      float x = cosf(rad) * radius;

      return Vector<float>(x, y);
    };

    double pointDirection(float x, float y) {
      double rad = atan2(y, x);
      return fmod((rad * (180/PI)), 360);
    };

    double pointDirection(Vector<float> point) {
      double rad = atan2(point.y, point.x);
      return fmod((rad * (180/PI)), 360);
    };

    double pointDistance(Vector<float> a, Vector<float> b) {
      Vector<float> difference = a - b;
      return sqrt((difference.x * difference.x) + (difference.y * difference.y));
    };
  }
};