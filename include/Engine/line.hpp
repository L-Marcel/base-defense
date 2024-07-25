#pragma once
#include <Engine/defs.hpp>

namespace Game {
  class Line {
    public:
      Vector<float> start;
      Vector<float> end;
      Line(Vector<float> start, Vector<float> end);
  };
};