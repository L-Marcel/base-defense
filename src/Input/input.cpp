#include <Input.hpp>

namespace Game {
  namespace Input {
    bool fire(
      Keyboard::Key key
    ) {
      return Keyboard::isKeyPressed(key);
    };
  }
};