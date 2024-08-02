#pragma once
#include <Objects/object_2d.hpp>
#include <Misc/timer.hpp>
#include <Engine.hpp>

namespace Game {
  class MedicalKit : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      using Object2D::Object2D;
      virtual ~MedicalKit();

      /// @brief Cria uma instancia do MedicalKit
      /// @param position a posição do kit
      static MedicalKit* create(Point enemyPosition);
    protected:
      Timer timer;
  };
};