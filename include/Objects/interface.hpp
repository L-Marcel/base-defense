#include <Objects.hpp>
#include <Objects/player_life_bar.hpp>
#include <Objects/base_life_bar.hpp>
#include <Objects/ammo_display.hpp>
#include <Objects/coin_display.hpp>

namespace Game {
  class Interface : public Object {
    public:
      virtual string type();
      using Object::step;
      using Object::collision;
      using Object::free;
      using Object::draw;
      ~Interface();

      /// @brief Cria uma instância da Interface
      static Interface* create();
  };
}