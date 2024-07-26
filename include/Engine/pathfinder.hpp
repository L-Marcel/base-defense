#pragma once
#include <Engine/math.hpp>
#include <stack>

#define TOWER_SIZE 32
#define TOP_LEFT_TOWER_POSITION Vector<float>(448, 232)
#define BOTTOM_LEFT_TOWER_POSITION Vector<float>(448, 488)
#define TOP_RIGHT_TOWER_POSITION Vector<float>(832, 232)
#define BOTTOM_RIGHT_TOWER_POSITION Vector<float>(832, 488)

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
  };
};