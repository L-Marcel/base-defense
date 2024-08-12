#include <Misc/playerfinder.hpp>

namespace Game {
  float ww = BASE_SIZE.x/2.0 + 33;
  float hh = BASE_SIZE.y/2.0 + 33;

  const Segment Playerfinder::ab = Segment(CENTER + Point(-ww, -hh), CENTER + Point(ww, -hh));
  const Segment Playerfinder::bc = Segment(CENTER + Point(ww, -hh), CENTER + Point(ww, hh));
  const Segment Playerfinder::cd = Segment(CENTER + Point(ww, hh), CENTER + Point(-ww, hh));
  const Segment Playerfinder::da = Segment(CENTER + Point(-ww, hh), CENTER + Point(-ww, -hh));

  float tt = TOWER_SIZE/2.0 + 33;
  const Segment Playerfinder::rab = Segment(Playerfinder::ab.start.x + tt, Playerfinder::ab.start.y + tt, Playerfinder::ab.end.x - tt, Playerfinder::ab.end.y + tt);
  const Segment Playerfinder::rbc = Segment(Playerfinder::bc.start.x - tt, Playerfinder::bc.start.y + tt, Playerfinder::bc.end.x - tt, Playerfinder::bc.end.y - tt);
  const Segment Playerfinder::rcd = Segment(Playerfinder::cd.start.x - tt, Playerfinder::cd.start.y - tt, Playerfinder::cd.end.x + tt, Playerfinder::cd.end.y - tt);
  const Segment Playerfinder::rda = Segment(Playerfinder::da.start.x + tt, Playerfinder::da.start.y - tt, Playerfinder::da.end.x + tt, Playerfinder::da.end.y + tt);

  Playerfinder::Playerfinder() {};

  unsigned short int Playerfinder::getSector(Point position) {
    bool h_left = position.x <= this->rab.start.x;
    if(h_left && position.y <= this->rab.start.y) {
      return 0;
    } else if(h_left && position.y >= this->rda.start.y) {
      return 6;
    } else if(h_left) {
      return 3;
    };

    bool h_center = position.x > this->rab.start.x && position.x < this->rab.end.x;
    if(h_center && position.y <= this->rab.start.y) {
      return 1;
    } else if(h_center && position.y >= this->rcd.start.y) {
      return 7;
    } else if(h_center) {
      return 4;
    };

    if(position.y <= this->rab.start.y) {
      return 2;
    } else if(position.y >= this->rda.start.y) {
      return 8;
    } else {
      return 5;
    };
  };

  Segment Playerfinder::getPath(
    Point position,
    float speed,
    float range
  ) {
    const Player* player = Player::get();

    if(player->safe) {
      this->path = Segment();
      range /= 1.25;

      Point target = position;
      unsigned short int sector = this->getSector(position);
    
      Segment rab(this->rab.start, position);
      Segment rbc(this->rbc.start, position);
      Segment rcd(this->rcd.start, position);
      Segment rda(this->rda.start, position);

      switch(sector) {
        case 0:
          target = this->rab.start + Math::pointInRadius(range, rab.angle());
          break;
        case 1:
          target = Point(position.x, this->rab.start.y - range + 33);
          break;
        case 2:
          target = this->rbc.start + Math::pointInRadius(range, rbc.angle());
          break;
        case 3:
          target = Point(this->rab.start.x - range + 33, position.y);
          break;
        case 5:
          target = Point(this->rbc.start.x + range - 33, position.y);
          break;
        case 6:
          target = this->rda.start + Math::pointInRadius(range, rda.angle());
          break;
        case 7:
          target = Point(position.x, this->rcd.start.y + range - 33);
          break;
        case 8:
          target = this->rcd.start + Math::pointInRadius(range, rcd.angle());
          break;
        default:
          break;
      };
        
      Segment path = Segment::create(position, target, speed);
      this->stopped = path.start == path.end;
      return path;
    } else {
      Point target = player->position;
      double distance = Math::pointDistance(target, position);
      bool facingThePlayer = this->isFacingPlayer(position);

      if(facingThePlayer && distance <= range) {
        this->stopped = true;
        this->path = Segment();
        return Segment(position);
      } else if(facingThePlayer) {
        this->stopped = false;
        this->path = Segment();
        return Segment::create(position, target, speed);
      } else if(!this->path || this->path.getNearestVertex(target) == position) {
        this->stopped = false;
        Segment path = Segment::create(position, target, speed);
        
        if(this->ab & path && path.end.y > this->ab.start.y && this->ab != this->path) {
          this->path = this->ab;
        } else if(this->bc & path && path.end.x < this->bc.start.x && this->bc != this->path) {
          this->path = this->bc;
        } else if(this->cd & path && path.end.y < this->cd.start.y && this->cd != this->path) {
          this->path = this->cd;
        } else if(this->da & path && path.end.x > this->da.start.x && this->da != this->path) {
          this->path = this->da;
        } else {
          return path;
        };
      };

      target = this->path.getNearestVertex(target);
      if(target != position) {
        return Segment::create(position, target, speed);
      };

      return Segment(position);
    };
  };

  bool Playerfinder::isStopped() {
    return this->stopped;
  };

  bool Playerfinder::isFacingPlayer(Point position) {
    Segment path(position, Player::get()->position);
    bool has_any_intersection =
      (this->ab & path && path.end.y > this->ab.start.y && this->ab != path) ||
      (this->bc & path && path.end.x < this->bc.start.x && this->bc != path) ||
      (this->cd & path && path.end.y < this->cd.start.y && this->cd != path) ||
      (this->da & path && path.end.x > this->da.start.x && this->da != path);
    return !has_any_intersection;
  };
};