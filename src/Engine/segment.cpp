#include <Engine/segment.hpp>

namespace Game {
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

  bool Segment::hasPoint(Vector<float> point) {
    float dx = this->end.x - this->start.x;
    bool xIsValid = false;
    float xx = 0;
    if(dx == 0) {
      xIsValid = point.x == this->start.x;
    } else {
      xx = (point.x - this->start.x) / dx;
      xIsValid = xx >= 0 && xx <= 1;
    };

    float dy = this->end.y - this->start.y;
    bool yIsValid = false;
    float yy = 0;
    if(dy == 0) {
      yIsValid = point.y == this->start.y;
    } else {
      yy = (point.y - this->start.y) / dy;
      yIsValid = yy >= 0 && yy <= 1;
    };

    return xIsValid && yIsValid && (dx == 0 || dy == 0 || xx == yy);
  };
};