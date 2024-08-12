#include <Objects.hpp>
#include <Objects/base.hpp>
#include <Objects/player.hpp>

namespace Game {
  class AmmoDisplay : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~AmmoDisplay();

      /// @brief Cria uma instância do display da munição
      static AmmoDisplay* create();
    protected:
      using Object2D::Object2D;
      Text* hud;
  };
};