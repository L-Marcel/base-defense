#include "../../include/Input.hpp"

namespace lm {
  namespace Input {
    Coord keyboard(
      Keyboard::Key left,
      Keyboard::Key top,
      Keyboard::Key right,
      Keyboard::Key down,
      float speed
    ) {
      bool leftPressed = Keyboard::isKeyPressed(left);
      bool topPressed = Keyboard::isKeyPressed(top);
      bool rightPressed = Keyboard::isKeyPressed(right);
      bool downPressed = Keyboard::isKeyPressed(down);

      short int horizontal = rightPressed - leftPressed;
      short int vertical = downPressed - topPressed;

      if(horizontal != 0 || vertical != 0) {
        return Coord(
          horizontal * speed,
          vertical * speed
        );
      };

      return Coord(0,0);
    };
  };
};