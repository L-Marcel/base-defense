#include <Objects.hpp>

namespace Game{
  class PauseScreen : public Object2D{
    public:
      virtual string type();
      using Object2D::step;
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~PauseScreen();

      /// @brief Cria uma instância do plano de fundo do jogo
      /// @param gp pornteiro do processo do jogo
      static PauseScreen* create(GameProcess* gp);
    protected:
      /// @brief Cria uma instância do plano de fundo
      /// @param spriteSheet página de textura do sprite do plano de fundo
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      PauseScreen(string spriteSheet, Box box);
  };
}