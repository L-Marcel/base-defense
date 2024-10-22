#pragma once
#include <Misc/pathfinder.hpp>
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
      /// @param can_be_blocked se o disparo pode ser bloqueado
      void shoot(bool can_be_blocked = true);

      /// @brief Recarrega a munição
      void recharge();

      Pathfinder path;
      Sound shoot_sound = Sound("shoot.mp3");
      Sound empty_clip_sound = Sound("empty_clip.mp3");
      Sound recharge_sound = Sound("recharge.wav");
      Object2D* legs = nullptr;
      bool safe = true;
    protected:
      using Character::Character;
      static Player* player;
  };
};