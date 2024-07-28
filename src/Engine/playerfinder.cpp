#include <Engine/playerfinder.hpp>

namespace Game {
  Playerfinder::Playerfinder() {};

  Playerfinder::Playerfinder(Player* player) {
    this->player = player;
  };

  Vector3<double> Playerfinder::getDestiny(
    Vector<float> position,
    double direction, 
    float speed,
    float range
  ) {
    float ww = BASE_SIZE.x/2.0 + 33;
    float hh = BASE_SIZE.y/2.0 + 33;

    Segment ab(CENTER + Vector<float>(-ww, -hh), CENTER + Vector<float>(ww, -hh));
    Segment bc(CENTER + Vector<float>(ww, -hh), CENTER + Vector<float>(ww, hh));
    Segment cd(CENTER + Vector<float>(ww, hh), CENTER + Vector<float>(-ww, hh));
    Segment da(CENTER + Vector<float>(-ww, hh), CENTER + Vector<float>(-ww, -hh));

    if(this->player->safe) {
      this->stopped = false;
      while(!this->isFacingThePlayer()) {
        this->paths.pop();
      };

      // if(position.y < ab.start.y && position.x > ab.start.x && position.x < ab.end.x) {
      //   direction = 270; //+ (rand() % 45) - 22.5;
      // } else if(position.y < ab.start.y && position.x <= ab.start.x) {
      //   direction = 315; //+ (rand() % 45) - 22.5;
      // } else if(position.y < ab.start.y && position.x >= ab.end.x) {
      //   direction = 225; //+ (rand() % 45) - 22.5;
      // } else if(position.y > cd.start.y && position.x > cd.end.x && position.x < cd.start.x) {
      //   direction = 90; //+ (rand() % 45) - 22.5;
      // } else if(position.y < cd.start.y && position.x <= cd.end.x) {
      //   direction = 45; //+ (rand() % 45) - 22.5;
      // } else if(position.y < ab.start.y && position.x >= cd.start.x) {
      //   direction = 135; //+ (rand() % 45) - 22.5;
      // } else if(position.x < da.start.x && position.y <= da.start.y && position.y >= da.end.y) {
      //   direction = 0; //+ (rand() % 45) - 22.5;
      // } else if(position.x > bc.start.x && position.y <= bc.end.y && position.y >= bc.start.y) {
      //   direction = 180; //+ (rand() % 45) - 22.5;
      // };

      Vector<float> destiny = position + Math::pointInRadius(
        speed, 
        direction
      );

      Segment path(position, destiny);
      if(Math::hasIntersection(ab, path) && destiny.y > ab.start.y && ab != current_segment) {
        this->current_segment = ab;
        return Vector3<double>(destiny.x, ab.start.y, direction);
      } else if(Math::hasIntersection(bc, path) && destiny.x < bc.start.x && bc != current_segment) {
        this->current_segment = bc;
        return Vector3<double>(bc.start.x, destiny.y, direction);
      } else if(Math::hasIntersection(cd, path) && destiny.y < cd.start.y && cd != current_segment) {
        this->current_segment = cd;
        return Vector3<double>(destiny.x, cd.start.y, direction);
      } else if(Math::hasIntersection(da, path) && destiny.x > da.start.x && da != current_segment) {
        this->current_segment = da;
        return Vector3<double>(da.start.x, destiny.y, direction);
      } else if(Math::hasIntersection(this->current_segment, path)) {
        this->stopped = true;
        return Vector3<double>(position.x, position.y, direction);
      };
        
      return Vector3<double>(position.x, position.y, direction);
    } else {
      Vector<float> target = this->player->position;

      if(!this->isFacingThePlayer()) {
        target = this->paths.top();
      };
      
      if(target != position) {
        this->stopped = false;
        double distance = Math::pointDistance(target, position);

        if(distance <= range && this->isFacingThePlayer()) {
          this->stopped = true;
          direction = Math::pointDirection(target - position);
          return Vector3<double>(position.x, position.y, direction);
        };

        Vector<float> difference = target - position;
        direction = Math::pointDirection(difference);
        Vector<float> destiny = position + Math::pointInRadius(
          min(double(speed), distance), 
          direction
        );

        Segment path(position, destiny);

        if(Math::hasIntersection(ab, path) && destiny.y > ab.start.y && ab != current_segment) {
          this->current_segment = ab;
          this->paths.push(ab.getNearestVertex(target));
          return this->getDestiny(position, direction, speed, range);
        } else if(Math::hasIntersection(bc, path) && destiny.x < bc.start.x && bc != current_segment) {
          this->current_segment = bc;
          this->paths.push(bc.getNearestVertex(target));
          return this->getDestiny(position, direction, speed, range);
        } else if(Math::hasIntersection(cd, path) && destiny.y < cd.start.y && cd != current_segment) {
          this->current_segment = cd;
          this->paths.push(cd.getNearestVertex(target));
          return this->getDestiny(position, direction, speed, range);
        } else if(Math::hasIntersection(da, path) && destiny.x > da.start.x && da != current_segment) {
          this->current_segment = da;
          this->paths.push(da.getNearestVertex(target));
          return this->getDestiny(position, direction, speed, range);
        };
        
        return Vector3<double>(destiny.x, destiny.y, direction);
      } else {
        this->paths.pop();
        return this->getDestiny(position, direction, speed, range);
      };
    };
  };

  bool Playerfinder::isStopped() {
    return this->stopped;
  };

  bool Playerfinder::isFacingThePlayer() {
    return this->paths.empty();
  };
};