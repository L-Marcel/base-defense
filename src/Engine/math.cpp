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
      double result = fmod((rad * (180.0/PI)), 360);
      
      if(result < 0) {
        result += 360.0;
      };

      return result;
    };

    double pointDirection(Vector<float> point) {
      return pointDirection(point.x, point.y);
    };

    double pointDistance(Vector<float> a, Vector<float> b) {
      Vector<float> difference = a - b;
      return sqrt((difference.x * difference.x) + (difference.y * difference.y));
    };

    bool hasIntersection(Line a, Line b) {
      return 0 != (
        ((b.end.x - b.start.x) * (a.end.y - a.start.y)) - 
        ((b.end.y - b.start.y) * (a.end.x - a.start.x))
      );
    };
  }
};