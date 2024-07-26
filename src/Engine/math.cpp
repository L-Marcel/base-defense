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

    bool hasIntersection(Segment a, Segment b) {
      float dya = a.end.y - a.start.y;
      float dyb = b.end.y - b.start.y;
      float dxa = a.end.x - a.start.x;
      float dxb = b.end.x - b.start.x;
      double det = (dxb * dya) - (dyb * dxa);

      if(det == 0) {
        return a.hasPoint(b.start) || a.hasPoint(b.end);
      } else {
        float s = ((b.start.y - a.start.y) * dxb - (b.start.x - a.start.x) * dyb) / det;
        float t = ((a.start.x - b.start.x) * dya - (a.start.y - b.start.y) * dxa) / det;
        return s >= 0 && s <= 1 && t >= 0 && t <= 1;
      };
    };
  }
};