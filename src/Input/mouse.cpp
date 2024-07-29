#include <Input.hpp>

namespace Game {
  namespace Mouse {
    Point position(Window* window) {
      Vector<int> pos = sf::Mouse::getPosition();

      if(window != nullptr) {
        pos = sf::Mouse::getPosition(*window);
      };

      return Point(pos.x, pos.y);
    };

    bool left() {
      return sf::Mouse::isButtonPressed(sf::Mouse::Left);
    };

    bool right(){
      return sf::Mouse::isButtonPressed(sf::Mouse::Right);
    };

    bool middle() {
      return sf::Mouse::isButtonPressed(sf::Mouse::Middle);
    };

    bool extra1(){
      return sf::Mouse::isButtonPressed(sf::Mouse::XButton1);
    };

    bool extra2() {
      return sf::Mouse::isButtonPressed(sf::Mouse::XButton2);
    };
  };
};