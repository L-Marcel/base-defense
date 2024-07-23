#include <Character.hpp>
#include <Sound.hpp>
#include <Input.hpp>
#include <Objects/text.hpp>
#include <Objects/tower.hpp>
#include <Objects/wall.hpp>
#include <Objects/bullet.hpp>

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

      List<Object2D> parts;
      Text* hud;
    protected:
      using Character::Character;
  };
};