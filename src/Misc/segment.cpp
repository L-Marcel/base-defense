#include <Engine/math.hpp>

namespace Game {
  Segment::Segment() {};

  Segment::Segment(float start_x, float start_y, float end_x, float end_y) {
    this->empty = false;
    this->start.x = start_x;
    this->start.y = start_y;
    this->end.x = end_x;
    this->end.y = end_y;
  };

  Segment::Segment(Point start, Point end) {
    this->empty = false;
    this->start = start;
    this->end = end;
  };

  Segment::Segment(float x, float y) {
    this->empty = false;
    this->start.x = x;
    this->start.y = y;
    this->end = start;
  };

  Segment::Segment(Point point) {
    this->empty = false;
    this->start = point;
    this->end = point;
  };

  Segment Segment::create(Point from, Point to, float max_length) {
    Segment path(from, to);

    path.end = path.start + Math::pointInRadius(
      min(double(max_length), path.length()), 
      path.angle()
    );
    
    return path;
  };

  bool Segment::hasPoint(float x, float y) const {
    float dx = this->end.x - this->start.x;
    bool x_is_valid = false;
    float xx = 0;
    if(dx == 0) {
      x_is_valid = x == this->start.x;
    } else {
      xx = (x - this->start.x) / dx;
      x_is_valid = xx >= 0 && xx <= 1;
    };

    float dy = this->end.y - this->start.y;
    bool y_is_valid = false;
    float yy = 0;
    if(dy == 0) {
      y_is_valid = y == this->start.y;
    } else {
      yy = (y - this->start.y) / dy;
      y_is_valid = yy >= 0 && yy <= 1;
    };

    return x_is_valid && y_is_valid && (dx == 0 || dy == 0 || xx == yy);
  };

  bool Segment::hasPoint(Point point) const {
    return this->hasPoint(point.x, point.y);
  };

  double Segment::length() {
    return Math::pointDistance(this->start, this->end);
  };

  double Segment::angle() {
    return Math::pointDirection(this->end - this->start);
  };

  Point Segment::getNearestVertex(Point point) {
    double start_distance = Math::pointDistance(this->start, point);
    double end_distance = Math::pointDistance(this->end, point);
    if(start_distance > end_distance) {
      return this->end;
    } else {
      return this->start;
    };
  };

  bool Segment::operator==(const Segment& other) const {
    return this->empty == other.empty && (
      (other.start == this->start && other.end == this->end) || (other.start == this->end && other.end == this->start)
    );
  };

  bool Segment::operator!=(const Segment& other) const {
    return !(*this == other);
  };

  bool Segment::operator&(const Segment& other) const {
    float dya = this->end.y - this->start.y;
    float dyb = other.end.y - other.start.y;
    float dxa = this->end.x - this->start.x;
    float dxb = other.end.x - other.start.x;
    double det = (dxb * dya) - (dyb * dxa);

    if(det == 0) {
      return this->hasPoint(other.start) || this->hasPoint(other.end);
    } else {
      float s = ((other.start.y - this->start.y) * dxb - (other.start.x - this->start.x) * dyb) / det;
      float t = ((this->start.x - other.start.x) * dya - (this->start.y - other.start.y) * dxa) / det;
      return s >= 0 && s <= 1 && t >= 0 && t <= 1;
    };
  };

  Segment::operator bool() {
    return !this->empty;
  };
};