#include <Engine.hpp>
#define PI 3.14159265359

namespace Game {
  namespace Math {
    Point pointInRadius(double radius, double angle) {
      float rad = angle * (PI / 180);
      float y = sinf(rad) * radius;
      float x = cosf(rad) * radius;
      return Point(x, y);
    };

    double pointDirection(float x, float y) {
      double rad = atan2(y, x);
      double result = fmod((rad * (180.0/PI)), 360);
      
      if(result < 0) {
        result += 360.0;
      };

      return result;
    };

    double pointDirection(Point point) {
      return pointDirection(point.x, point.y);
    };

    double pointDistance(Point a, Point b) {
      Point difference = a - b;
      return sqrt((difference.x * difference.x) + (difference.y * difference.y));
    };

    Segment move(Point from, Point to, float speed) {
      Segment path(from, to);

      path.end = path.start + Math::pointInRadius(
        min(double(speed), path.length()), 
        path.angle()
      );
      
      return path;
    };
  };
};