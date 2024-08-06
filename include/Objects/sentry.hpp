#pragma once
#include <Objects.hpp>
#include <Misc/timer.hpp>

namespace Game {
  class Sentry : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~Sentry();

      /// @brief Cria uma instância da sentinela
      static Sentry* create();

      /// @brief Realiza um disparo
      void shoot();

      float damage = 50;
      bool energized = true;
      bool right = true;
      Timer attack_delay;
      float attack_speed = 1;

      Sound shoot_sound = Sound("shoot.mp3");
    protected:
      /// @brief Cria uma instância da sentinela
      /// @param spriteSheet página de textura do sprite da sentinela
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      Sentry(string spriteSheet, Box box);
  };
};