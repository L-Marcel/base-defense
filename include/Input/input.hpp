#include "../Engine/math.hpp"

namespace lm {
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