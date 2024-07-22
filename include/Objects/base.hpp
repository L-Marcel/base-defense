#include <Character.hpp>
#include <Sound.hpp>
#include <Input.hpp>
#include <Objects/tower.hpp>
#include <Objects/wall.hpp>
#include <Objects/base_wall.hpp>

namespace Game {
  class Base : public Character {
    public:
      virtual string type();
      virtual void step();
      using Character::collision;
      using Character::draw;
      using Character::free;
      virtual ~Base();

      /// @brief Cria uma instância da base
      /// @param gp pornteiro do processo do jogo
      static Base* create(GameProcess* gp);
    protected:
      using Character::Character;
  };
};