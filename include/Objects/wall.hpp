#include <Objects.hpp>

namespace Game {
  class Wall : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~Wall();

      /// @brief Cria uma instância da parede
      /// @param gp pornteiro do processo do jogo
      /// @param size diz qual é a parede
      static Wall* create(GameProcess* gp, unsigned short int size);
    protected:
      bool enabled = true;
      unsigned short int side = 0;
      
      /// @brief Cria uma instância da parede
      /// @param spriteSheet página de textura do sprite da parede
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      Wall(string spriteSheet, Box box);
  };
};