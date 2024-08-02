#include <Character.hpp>

namespace Game {
  string Character::type() {
    return "Character";
  };

  Character::~Character() {};

  Character::Character() {
    this->health = Health(this, 100);
  };
  
  Character::Character(string spriteSheet, Box box, unsigned int base_ammo, float base_health) 
  : Object2D(spriteSheet, box) {
    this->health = Health(this, base_health);
    this->clip = Ammo(this, base_ammo);
  };

  Character* Character::create(string spriteSheet, Box box) {
    Character* instance = new Character(spriteSheet, box);
    GameProcess::add(instance);
    return instance;
  };
};