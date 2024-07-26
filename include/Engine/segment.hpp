#pragma once
#include <Engine/defs.hpp>

namespace Game {
  class Segment {
    public:
      Vector<float> start;
      Vector<float> end;
      Segment(float start_x, float start_y, float end_x, float end_y);
      Segment(Vector<float> start, Vector<float> end);
      bool hasPoint(Vector<float> point);
  };
};