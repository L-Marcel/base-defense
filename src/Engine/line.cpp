#include <Engine/line.hpp>

namespace Game {
  Line::Line(Vector<float> start, Vector<float> end) {
    this->start = start;
    this->end = end;
  };
};