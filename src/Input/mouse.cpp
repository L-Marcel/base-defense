#include <Input.hpp>
#include <Engine/process.hpp>

namespace Game {
  namespace Mouse {
    Point position() {
      const Window& window = GameProcess::getWindow();
      return Point(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
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