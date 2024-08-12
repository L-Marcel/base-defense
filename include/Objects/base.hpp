#pragma once
#include <Character.hpp>
#include <Sound.hpp>
#include <Input.hpp>
#include <Objects/text.hpp>
#include <Objects/tower.hpp>
#include <Objects/wall.hpp>
#include <Objects/sentry.hpp>
#include <Objects/bullet.hpp>

namespace Game {
  class Base : public Character {
    public:
      virtual string type();
      using Character::step;
      using Character::collision;
      using Character::draw;
      using Character::free;
      ~Base();

      /// @brief Cria uma instância da base
      static Base* create();

      /// @brief Retorna o ponteiro da base
      /// @return o ponteiro
      const static Base* get();

      static bool friendly_fire;
      static bool vengeful_bullets;
    protected:
      using Character::Character;
      static Base* base;
  };
};