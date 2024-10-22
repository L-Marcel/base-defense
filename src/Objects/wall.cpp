#include <Objects/base.hpp>
namespace Game {
  string Wall::type() {
    return "Wall";
  };

  void Wall::step() { 
    this->energized = Base::get() != nullptr;
    bool was_enabled = this->enabled;
    this->enabled = this->energized;
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      string type = collider->type();
      if(type == "Player") {
        this->enabled = false;
      } else if(type == "Bullet" && collider->depth <= this->depth) {
        Bullet* bullet = (Bullet*) collider;

        if(bullet->can_be_blocked && this->enabled && !collider->destroyed()) {
          bullet->bounce_sound.play();
          bullet->bounce_sound.setVolume(50);
  
          if(Base::friendly_fire || !bullet->is_ally) {
            if(bullet->is_ally) Base::get()->health.damage(bullet->damage / 10.0);
            else Base::get()->health.damage(bullet->damage / 2.5);
          };
            
          if(Base::vengeful_bullets) bullet->is_ally = true;

          switch(this->side) {
            case 0:
              bullet->direction = (180 - bullet->direction);
              bullet->position.x = this->position.x - 2;
              break;
            case 1:
              bullet->direction = (180 - bullet->direction);
              bullet->position.x = this->position.x + 2;
              break;
            case 2:
              bullet->direction = -(bullet->direction - 360);
              bullet->position.y = this->position.y - 2;
              break;
            case 3:
              bullet->direction = 360 - bullet->direction;
              bullet->position.y = this->position.y + 2;
              break;
            default:
              collider->destroy();
              break;
          };
        };

        bullet->can_be_blocked = false;
      };
    };

    bool changed = was_enabled != this->enabled;
    if(changed && this->enabled) {
      this->on_sound.play();
      this->animate(8, 4, 0, true);
    } else if(changed) {
      this->off_sound.play();
      this->animate(0, 1, 1, false);
    };
  };

  Wall::~Wall() {};

  Wall::Wall(string sprite_sheet, Box box) 
  : Object2D(sprite_sheet, box) {};

  Wall* Wall::create(unsigned short int side) {
    Wall* wall;

    switch (side) {
      case 0:
        wall = new Wall("short_wall.png", Box(58, 3, 116, 4));
        wall->rotation = 270;
        wall->position = Point(438, 360);
        wall->setRectangle(10, 232);
        break;
      case 1:
        wall = new Wall("short_wall.png", Box(58, 3, 116, 4));
        wall->rotation = 90;
        wall->position = Point(842, 360);
        wall->setRectangle(10, 232);
        break;
      case 2:
        wall = new Wall("long_wall.png", Box(90, 3, 180, 4));
        wall->position = Point(640, 222);
        wall->setRectangle(360, 10);
        break;
      default:
        wall = new Wall("long_wall.png", Box(90, 3, 180, 4));
        wall->rotation = 180;
        wall->position = Point(640, 498);
        wall->setRectangle(360, 10);
        break;
    };

    wall->side = side;
    wall->depth = 200;
    wall->scale(2);
    wall->animate(8, 4, 0, true);
    GameProcess::add(wall);

    Collision::create(wall, "Player");
    Collision::create(wall, "Bullet");

    return wall;
  };
};