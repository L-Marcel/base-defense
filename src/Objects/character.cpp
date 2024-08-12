#include <Character.hpp>

namespace Game {
  string Character::type() {
    return "Character";
  };

  Character::~Character() {};

  Character::Character() {
    this->health = Health(this, 100);
  };
  
  Character::Character(string sprite_sheet, Box box, unsigned int base_ammo, float base_health) 
  : Object2D(sprite_sheet, box) {
    this->health = Health(this, base_health);
    this->clip = Ammo(this, base_ammo);
    this->attack_delay.start(0);
  };

  Character* Character::create(string sprite_sheet, Box box) {
    Character* instance = new Character(sprite_sheet, box);
    GameProcess::add(instance);
    return instance;
  };
};