#include "../Engine/math.hpp"

namespace lm {
  class Keyboard : public sf::Keyboard {};

  namespace Input {
    Coord keyboard(
      Keyboard::Key left,
      Keyboard::Key top,
      Keyboard::Key right,
      Keyboard::Key down,
      float speed = 1
    );
  };
};