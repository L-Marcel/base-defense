#pragma once
#include <Engine/pathfinder.hpp>
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
      ~Player();

      /// @brief Cria uma instância do jogador
      static Player* create();

      /// @brief Retorna o ponteiro do jogador
      /// @return o ponteiro
      const static Player* get();

      /// @brief Realiza um disparo
      void shoot();

      Pathfinder path;
      Sound shoot_sound = Sound("shoot.mp3");
      bool safe = true;
    protected:
      using Character::Character;
      static Player* player;
  };
};