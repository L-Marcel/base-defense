#include <Objects.hpp>

namespace Game {
  class Wall : public Object2D {
    public:
      virtual string type();
      using Object2D::step;
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~Wall();

      /// @brief Cria uma instância da parede
      /// @param gp pornteiro do processo do jogo
      /// @param big diz se a parede é a maior ou não
      static Wall* create(GameProcess* gp, bool big = true);
    protected:
      /// @brief Cria uma instância da parede
      /// @param spriteSheet página de textura do sprite da parede
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      Wall(string spriteSheet, Box box);
  };
};