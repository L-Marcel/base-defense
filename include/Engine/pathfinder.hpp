#pragma once
#include <Engine/math.hpp>
#include <stack>
namespace Game {
  class Pathfinder {
    public:
      Pathfinder();
      Vector3<double> getDestiny(Vector<float> position, double direction, float speed);
      Vector4<Segment> getNearestSegments(Vector<float> position);
      void setDestiny(Vector<float> position);
      bool isStopped();
    protected:
      stack<Vector<float>> paths;
      Segment current_segment;
  };
};