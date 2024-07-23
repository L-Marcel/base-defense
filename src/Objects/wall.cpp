#include <Objects/wall.hpp>
#include <Objects/bullet.hpp>

namespace Game {
  string Wall::type() {
    return "Wall";
  };

  void Wall::step() {
    // if(this->hasCircle){
    //   this->gp->window.draw(this->circle);
    // } else if(this->hasRectangle) {
    //   this->gp->window.draw(this->rectangle);
    // };
    
    bool wasEnabled = this->enabled;
    this->enabled = true;
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      string type = collider->type();
      if(type == "Player") {
        this->enabled = false;
      } else if(type == "Bullet") {
        Bullet* bullet = (Bullet*) collider;
        if(bullet->canBeBlocked && this->enabled) {
          switch(this->side) {
            case 2:
              bullet->direction = -(bullet->direction - 360);
              bullet->position.y = this->position.y - 2;
              break;
            default:
              collider->destroy();
              break;
          };
        };

        bullet->canBeBlocked = false;
      };
    };

    bool changed = wasEnabled != this->enabled;
    if(changed && this->enabled) {
      this->animate(8, 4, 0, true);
    } else if(changed) {
      this->animate(0, 1, 1, false);
    };
  };

  Wall::~Wall() {};

  Wall::Wall(string spriteSheet, Box box) 
  : Object2D(spriteSheet, box) {};

  Wall* Wall::create(GameProcess* gp, unsigned short int side) {
    Wall* wall;

    switch (side) {
      case 0:
        wall = new Wall("short_wall.png", Box(58, 2, 116, 4));
        wall->rotation = 270;
        wall->position = Vector<float>(436, 360);
        wall->setRectangle(8, 232);
        break;
      case 1:
        wall = new Wall("short_wall.png", Box(58, 2, 116, 4));
        wall->rotation = 90;
        wall->position = Vector<float>(844, 360);
        wall->setRectangle(8, 232);
        break;
      case 2:
        wall = new Wall("long_wall.png", Box(90, 2, 180, 4));
        wall->position = Vector<float>(640, 220);
        wall->setRectangle(360, 8);
        break;
      default:
        wall = new Wall("long_wall.png", Box(90, 2, 180, 4));
        wall->rotation = 180;
        wall->position = Vector<float>(640, 500);
        wall->setRectangle(360, 8);
        break;
    }

    wall->side = side;
    wall->depth = 200;
    wall->scale(2);
    wall->animate(8, 4, 0, true);
    wall->gp = gp;
    gp->objects.add(wall);

    Collision::create(gp, wall, "Player");
    Collision::create(gp, wall, "Bullet");

    return wall;
  };
};