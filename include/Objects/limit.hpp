#include <Objects.hpp>

namespace Game {
  class Limit : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      virtual void draw();
      using Object2D::free;
      ~Limit();

      /// @brief Cria uma instância do limite do mapa
      /// @param gp pornteiro do processo do jogo
      static void create(GameProcess* gp);
    protected:
      /// @brief Cria uma instância do limite do mapa
      Limit();
  };
};