#include <Engine/pathfinder.hpp>

namespace Game {
  Pathfinder::Pathfinder() {};

  bool Pathfinder::isStopped() {
    return this->paths.empty();
  };

  void Pathfinder::setDestiny(Vector<float> position) {
    while(!this->paths.empty()) {
      this->paths.pop();
    };

    this->paths.push(position);
  };

  Vector3<double> Pathfinder::getDestiny(Vector<float> position, double direction, float speed) {
    if(this->paths.empty()) {
      return Vector3<double>(position.x, position.y, direction);
    };

    Vector<float> destiny = this->paths.top();
    if(destiny != position) {
      double distance = Math::pointDistance(destiny, position);
      Vector<float> difference = destiny - position;
      direction = Math::pointDirection(difference);
      Vector<float> destiny = position + Math::pointInRadius(
        min(double(speed), distance), 
        direction
      );

      Vector<float> towers_positions[3] = {
        BOTTOM_LEFT_TOWER_POSITION, 
        TOP_RIGHT_TOWER_POSITION, 
        BOTTOM_RIGHT_TOWER_POSITION
      };

      Vector<float> tower_position = TOP_LEFT_TOWER_POSITION;
      double distance_to_tower = Math::pointDistance(tower_position, position);
      for(unsigned short int i = 0; i < 3; i++) {
        double new_distance_to_tower = Math::pointDistance(towers_positions[i], position);
        if(new_distance_to_tower < distance_to_tower) {
          distance_to_tower = new_distance_to_tower;
          tower_position = towers_positions[i];
        };
      };

      float min_distance = (TOWER_SIZE/2.0) + 11;
      Line path(
        position,
        destiny
      );
      Line ab(
        tower_position + Vector<float>(-min_distance, -min_distance), 
        tower_position + Vector<float>(min_distance, -min_distance)
      );
      Line bc(
        tower_position + Vector<float>(min_distance, -min_distance), 
        tower_position + Vector<float>(min_distance, min_distance)
      );
      Line cd(
        tower_position + Vector<float>(min_distance, min_distance), 
        tower_position + Vector<float>(-min_distance, min_distance)
      );
      Line da(
        tower_position + Vector<float>(-min_distance, min_distance), 
        tower_position + Vector<float>(-min_distance, -min_distance)
      );

      if(
        Math::hasIntersection(ab, path) &&
        Math::pointDirection(ab.start - position) <= 135.0 &&
        Math::pointDirection(ab.start - position) >= 0 &&
        Math::pointDirection(position - ab.end) >= 45.0 &&
        Math::pointDirection(position - ab.end) <= 180.0
      ) {
        this->paths.push(ab.start);
        return this->getDestiny(position, direction, speed);
      };
      
      return Vector3<double>(destiny.x, destiny.y, direction);
    } else {
      this->paths.pop();
      return this->getDestiny(position, direction, speed);
    };
  };
};