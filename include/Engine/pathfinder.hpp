#pragma once
#include <Engine/math.hpp>
#include <stack>
namespace Game {
  class Pathfinder {
    public:
      Pathfinder();
      Segment getDestiny(Point position, float speed);
      Vector4<Segment> getNearestSegments(Point position);
      void setDestiny(Point position);
      bool isStopped();
    protected:
      stack<Point> paths;
      Segment current_segment;
  };
};