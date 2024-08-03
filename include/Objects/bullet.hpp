#pragma once
#include <Objects.hpp>
#include <Sound.hpp>

namespace Game {
  class Bullet : public Object2D {
    public:
      virtual string type();
      void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~Bullet();

      /// @brief Cria uma instância de um projétil
      /// @param object o objeto que a disparou
      /// @param ally se o projétil é aliado ao jogador ou não
      static Bullet* create(Object2D* object, bool ally = false);

      bool isAlly = false;
      bool canBeBlocked = true;
      float damage = 10;
      Sound bounce_sound = Sound("bounce.wav");
    protected:
      using Object2D::Object2D;
     
  };
};