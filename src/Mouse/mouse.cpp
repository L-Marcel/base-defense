#include "../../include/Mouse.hpp"

namespace lm {
  namespace Mouse {
    Vector<float> position(Window* window) {
      Vector<int> pos = sf::Mouse::getPosition();

      if(window != nullptr) {
        pos = sf::Mouse::getPosition(*window);
      };

      return Vector<float>(pos.x, pos.y);
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