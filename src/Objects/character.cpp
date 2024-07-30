#include <Character.hpp>

namespace Game {
  string Character::type() {
    return "Character";
  };

  Character::~Character() {};

  Character::Character() {
    this->health = Health(this, 100);
  };
  
  Character::Character(string spriteSheet, Box box, float base_health) 
  : Object2D(spriteSheet, box) {
    this->health = Health(this, base_health);
  };

  Character* Character::create(string spriteSheet, Box box) {
    Character* instance = new Character(spriteSheet, box);
    GameProcess::add(instance);
    return instance;
  };
};