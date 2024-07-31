#pragma once
#include <Character.hpp>
#include <Misc/playerfinder.hpp>
#include <Objects/base.hpp>
#include <Objects/bullet.hpp>
#include <Objects/medical_kit.hpp>
#include <Sound.hpp>

namespace Game {
  class Enemy : public Character {
    public:
      virtual string type();
      virtual void step();
      using Character::collision;
      using Character::draw;
      using Character::free;
      ~Enemy();

      /// @brief Cria uma instância do Enemy
      static Enemy* create();

      /// @brief Realiza um disparo
      void shoot();

      Sound shoot_sound = Sound("shoot.mp3");
      bool focusingBase = true;
      Playerfinder path;

      static Wall* wab;
      static Wall* wbc;
      static Wall* wcd;
      static Wall* wda;
    protected:
      using Character::Character;
      double range = 200.0;
  };
};