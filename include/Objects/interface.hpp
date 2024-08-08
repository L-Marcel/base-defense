#include <Objects.hpp>
#include <Objects/player_life_bar.hpp>

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
    protected:
      List<Object> parts;
  };
}