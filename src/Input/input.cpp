#include <Input.hpp>

namespace Game {
  namespace Input {
    Vector<float> keyboard(
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
        return Vector<float>(
          horizontal * speed,
          vertical * speed
        );
      };

      return Vector<float>(0,0);
    };
  }
};