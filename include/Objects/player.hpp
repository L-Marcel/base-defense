#pragma once
#include <Character.hpp>
#include <Sound.hpp>
#include <Input.hpp>

namespace Game {
  class Player : public Character {
    public:
      virtual string type();
      virtual void step();
      using Character::collision;
      using Character::draw;
      using Character::free;
      virtual ~Player();

      /// @brief Cria uma instância do player
      /// @param gp ponteiro do processo do jogo
      static Player* create(GameProcess* gp);

      /// @brief Realiza um disparo
      void shoot();

      Vector<float> targetPosition;
      short unsigned int life = 10;
      bool firstAttack = true;
      Sound shoot_sound = Sound("shoot.mp3");
    protected:
      using Character::Character;
  };
};