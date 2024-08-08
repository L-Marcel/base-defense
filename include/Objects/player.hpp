#pragma once
#include <Misc/pathfinder.hpp>
#include <Objects/image.hpp>
#include <Character.hpp>
#include <Sound.hpp>
#include <Input.hpp>

namespace Game {
  class Image;
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
      /// @param canBeBlocked se o disparo pode ser bloqueado
      void shoot(bool canBeBlocked = true);

      /// @brief Recarrega a munição
      void recharge();

      Pathfinder path;
      Sound shoot_sound = Sound("shoot.mp3");
      Sound empty_clip_sound = Sound("empty_clip.mp3");
      Image* player_leg = nullptr;
      bool safe = true;
    protected:
      using Character::Character;
      static Player* player;
  };
};