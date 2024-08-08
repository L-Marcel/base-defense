#pragma once
#include <Objects/object_2d.hpp>

namespace Game{
  class Legs : public Object2D{
    public:
      virtual string type();
      using Object2D::step;
      using Object2D::draw;
      using Object2D::free;
      virtual ~Legs();

      static Legs* create(string spriteSheet, Box box);

    protected:
      using Object2D::Object2D;
  };
}