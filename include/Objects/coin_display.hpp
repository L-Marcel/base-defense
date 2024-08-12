#include <Objects.hpp>

namespace Game {
  class CoinDisplay : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~CoinDisplay();

      /// @brief Cria uma instância do display das moedas
      static CoinDisplay* create();
    protected:
      using Object2D::Object2D;
      Text* hud;
  };
};