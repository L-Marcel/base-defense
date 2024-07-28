#include <Input.hpp>

namespace Game {
  namespace Mouse {
    Vector<float> position(Window* window) {
      sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
      if(window != nullptr) {
        mousePosition = sf::Mouse::getPosition(*window);
      };

      sf::Vector2f worldPos = window->mapPixelToCoords(mousePosition);

      return Vector<float>(worldPos.x, worldPos.y);
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