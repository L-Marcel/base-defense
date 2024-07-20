#include <Character.hpp>
#include <Input.hpp>

namespace Game{
  class Example : public Character {
    public:
      virtual string type();
      virtual void step();
      using Character::collision;
      virtual void draw();
      using Character::free;
      virtual ~Example();

      /// @brief Cria uma instância do exemplo
      /// @param gp pornteiro do processo do jogo
      /// @param spriteSheet página de textura do sprite do exemplo
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      static Example* create(GameProcess* gp, string spriteSheet, Box box);
    protected:
      using Character::Character;
  };
};