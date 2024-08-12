#include <Objects.hpp>
#include <Objects/base.hpp>

namespace Game {
  class BaseLifeBar : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      virtual void draw();
      using Object2D::free;
      ~BaseLifeBar();

      /// @brief Cria uma instância da barra de vida da base
      static BaseLifeBar* create();
    protected:
      using Object2D::Object2D;
      float life_percent = 1;
      Text* hud;
  };
};