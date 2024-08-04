#include <Objects.hpp>
#include <Objects/player.hpp>

namespace Game {
  class PlayerLifeBar : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~PlayerLifeBar();
      
      /// @brief Cria uma instância da barra de vida do jogador
      static PlayerLifeBar* create();
    protected:
      using Object2D::Object2D;
      const Player* player = Player::get();
      float lifePercent = 1;
      Text* hud;
  };
};
