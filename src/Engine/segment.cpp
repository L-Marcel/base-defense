#include <Engine/math.hpp>

namespace Game {
  Segment::Segment() {};

  Segment::Segment(float start_x, float start_y, float end_x, float end_y) {
    this->start.x = start_x;
    this->start.y = start_y;
    this->end.x = end_x;
    this->end.y = end_y;
  };

  Segment::Segment(Vector<float> start, Vector<float> end) {
    this->start = start;
    this->end = end;
  };

  bool Segment::hasPoint(float x, float y) {
    float dx = this->end.x - this->start.x;
    bool xIsValid = false;
    float xx = 0;
    if(dx == 0) {
      xIsValid = x == this->start.x;
    } else {
      xx = (x - this->start.x) / dx;
      xIsValid = xx >= 0 && xx <= 1;
    };

    float dy = this->end.y - this->start.y;
    bool yIsValid = false;
    float yy = 0;
    if(dy == 0) {
      yIsValid = y == this->start.y;
    } else {
      yy = (y - this->start.y) / dy;
      yIsValid = yy >= 0 && yy <= 1;
    };

    return xIsValid && yIsValid && (dx == 0 || dy == 0 || xx == yy);
  };

  bool Segment::hasPoint(Vector<float> point) {
    return this->hasPoint(point.x, point.y);
  };

  Vector<float> Segment::getNearestVertex(Vector<float> point) {
    double start_distance = Math::pointDistance(this->start, point);
    double end_distance = Math::pointDistance(this->end, point);
    if(start_distance > end_distance) {
      return this->end;
    } else {
      return this->start;
    };
  };
};