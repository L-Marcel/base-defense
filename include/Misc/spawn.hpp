#pragma once
#include <Objects.hpp>
#include <Misc/timer.hpp>

namespace Game {
  class Spawn : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~Spawn();
      
      Timer spawn_delay;

      /// @brief Cria uma instância do invocador do mapa
      static void create();
      
      /// @brief Invoca um inimigo
      void spawn();

      Text* text = nullptr;

      static float spawn_speed;
      static unsigned int amount;
      static unsigned int wave;
      static Timer wave_delay;
    protected:
      /// @brief Cria uma instância do invocador do mapa
      Spawn();
  };
};