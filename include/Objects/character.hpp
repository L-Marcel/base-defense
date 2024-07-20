#include <Objects.hpp>

namespace Game {
  class Character : public Object2D {
    public:
      using Object2D::type;
      using Object2D::step;
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~Character();

      /// @brief Cria uma instância de um personagem
      /// @param gp pornteiro do processo do jogo
      /// @param spriteSheet página de textura do sprite de um personagem
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      static Character* create(GameProcess* gp, string spriteSheet, Box box);

      Health health;
    protected:
      /// @brief Cria uma instância de um personagem
      /// @param spriteSheet página de textura do sprite do personagem
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      /// @param base_health o quantidade inicial de vida, também considerada o limite
      Character(string spriteSheet, Box box, float base_health = 100);
  };
};