#include <Objects.hpp>
#include <Objects/player.hpp>

namespace Game {
  class PlayerLifeBar : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      virtual void draw();
      using Object2D::free;
      ~PlayerLifeBar();
      
      /// @brief Cria uma instância da barra de vida do jogador
      static PlayerLifeBar* create();
    protected:
      using Object2D::Object2D;
      float life_percent = 1;
      Text* hud;
  };
};
