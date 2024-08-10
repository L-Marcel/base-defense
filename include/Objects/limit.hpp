#pragma once
#include <Objects.hpp>
#include <Misc/timer.hpp>

namespace Game {
  class Limit : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      virtual void draw();
      using Object2D::free;
      ~Limit();
      
      float spawn_speed = 1;
      mutable Timer spawn_delay;

      /// @brief Cria uma instância do limite do mapa
      static void create();
      
      
      void spawnEnemy();

    protected:
      /// @brief Cria uma instância do limite do mapa
      Limit();
  };
};