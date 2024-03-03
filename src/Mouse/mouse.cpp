#include "../../include/mouse.hpp"

namespace lm {
  namespace Mouse {
    Coord position() {
      Vector2i pos = sf::Mouse::getPosition();
      return Coord(pos.x, pos.y);
    };

    Coord position(RenderWindow* window) {
      Vector2i pos = sf::Mouse::getPosition(*window);
      return Coord(pos.x, pos.y);
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