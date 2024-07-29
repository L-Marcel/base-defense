#include <Engine/playerfinder.hpp>

namespace Game {
  Playerfinder::Playerfinder() {
    float ww = BASE_SIZE.x/2.0 + 33;
    float hh = BASE_SIZE.y/2.0 + 33;

    this->ab = Segment(CENTER + Point(-ww, -hh), CENTER + Point(ww, -hh));
    this->bc = Segment(CENTER + Point(ww, -hh), CENTER + Point(ww, hh));
    this->cd = Segment(CENTER + Point(ww, hh), CENTER + Point(-ww, hh));
    this->da = Segment(CENTER + Point(-ww, hh), CENTER + Point(-ww, -hh));

    float tt = TOWER_SIZE/2.0;
    this->rab = Segment(ab.start.x + tt, ab.start.y + tt, ab.end.x - tt, ab.end.y + tt);
    this->rbc = Segment(bc.start.x - tt, bc.start.y + tt, bc.end.x - tt, bc.end.y - tt);
    this->rcd = Segment(cd.start.x - tt, cd.start.y - tt, cd.end.x + tt, cd.end.y - tt);
    this->rda = Segment(da.start.x + tt, da.start.y - tt, da.end.x + tt, da.end.y + tt);
  };

  Playerfinder::Playerfinder(Player* player) {
    this->player = player;

    float ww = BASE_SIZE.x/2.0 + 33;
    float hh = BASE_SIZE.y/2.0 + 33;

    this->ab = Segment(CENTER + Point(-ww, -hh), CENTER + Point(ww, -hh));
    this->bc = Segment(CENTER + Point(ww, -hh), CENTER + Point(ww, hh));
    this->cd = Segment(CENTER + Point(ww, hh), CENTER + Point(-ww, hh));
    this->da = Segment(CENTER + Point(-ww, hh), CENTER + Point(-ww, -hh));

    float tt = TOWER_SIZE/2.0 + 33;
    this->rab = Segment(ab.start.x + tt, ab.start.y + tt, ab.end.x - tt, ab.end.y + tt);
    this->rbc = Segment(bc.start.x - tt, bc.start.y + tt, bc.end.x - tt, bc.end.y - tt);
    this->rcd = Segment(cd.start.x - tt, cd.start.y - tt, cd.end.x + tt, cd.end.y - tt);
    this->rda = Segment(da.start.x + tt, da.start.y - tt, da.end.x + tt, da.end.y + tt);
  };

  unsigned short int Playerfinder::getSector(Point position) {
    bool h_left = position.x <= rab.start.x;
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

  Segment Playerfinder::getDestiny(
    Point position,
    float speed,
    float range
  ) {
    if(this->player->safe) {
      this->path = Segment();
      range /= 1.5;

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
        
      Segment path = Math::move(position, target, speed);
      this->stopped = path.start == path.end;
      return path;
    } else {
      Point target = this->player->position;
      double distance = Math::pointDistance(target, position);
      bool facingThePlayer = this->isFacingPlayer(position);

      if(facingThePlayer && distance <= range) {
        this->stopped = true;
        this->path = Segment();
        return Segment(position);
      } else if(facingThePlayer) {
        this->stopped = false;
        this->path = Segment();
        return Math::move(position, target, speed);
      } else if(!this->path || this->path.getNearestVertex(target) == position) {
        this->stopped = false;
        Segment path = Math::move(position, target, speed);
        
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
        return Math::move(position, target, speed);
      };

      return Segment(position);
    };
  };

  bool Playerfinder::isStopped() {
    return this->stopped;
  };

  bool Playerfinder::isFacingPlayer(Point position) {
    Segment path(position, this->player->position);
    bool hasAnyIntersection =
      (this->ab & path && path.end.y > this->ab.start.y && this->ab != path) ||
      (this->bc & path && path.end.x < this->bc.start.x && this->bc != path) ||
      (this->cd & path && path.end.y < this->cd.start.y && this->cd != path) ||
      (this->da & path && path.end.x > this->da.start.x && this->da != path);
    return !hasAnyIntersection;
  };
};