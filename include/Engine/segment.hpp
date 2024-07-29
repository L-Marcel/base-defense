#pragma once
#include <Engine/defs.hpp>

namespace Game {
  class Segment {
    public:
      Point start;
      Point end;

      Segment();
      Segment(float start_x, float start_y, float end_x, float end_y);
      Segment(Point start, Point end);
      Segment(float x, float y);
      Segment(Point point);

      bool hasPoint(float x, float y);
      bool hasPoint(Point point);
      double length();
      double angle();

      Point getNearestVertex(Point point);

      void operator=(Segment other);
      bool operator==(Segment other);
      bool operator!=(Segment other);
      bool operator&(Segment other);
      operator bool();
    private:
      bool empty = true;
  };
};