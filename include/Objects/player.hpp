#include <Objects.hpp>
#include <Sound.hpp>
#include <Input.hpp>

namespace Game {
  class Player : public Object2D {
    public:
      virtual string type();
      virtual void step(GameProcess* gp);
      using Object2D::draw;
      using Object2D::destroy;
      ~Player();

      /// @brief Cria uma instância do player
      /// @param gp pornteiro do processo do jogo
      /// @param spriteSheet página de textura do sprite do player
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      static Player* create(GameProcess* gp, string spriteSheet, Box box);

      short unsigned int life = 10;
      bool firstAttack = true;
      Sound shot_sound = Sound("shot.mp3");
    protected:
      using Object2D::Object2D;
  };
};