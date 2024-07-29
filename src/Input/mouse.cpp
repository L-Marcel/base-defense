#include <Input.hpp>

namespace Game {
  namespace Mouse {
    Window* window = nullptr;

    void setWindow(Window* win) {
      window = win;
    }

    Vector<float> position(Window* window) {
      Vector<int> pos = sf::Mouse::getPosition();

      if(window != nullptr && window->hasFocus()) {
        pos = sf::Mouse::getPosition(*window);
      };

      return Vector<float>(pos.x, pos.y);
    };

    bool left() {
      return (window != nullptr && window->hasFocus()) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
    };

    bool right(){
      return (window != nullptr && window->hasFocus()) && sf::Mouse::isButtonPressed(sf::Mouse::Right);
    };

    bool middle() {
      return (window != nullptr && window->hasFocus()) && sf::Mouse::isButtonPressed(sf::Mouse::Middle);
    };

    bool extra1(){
      return (window != nullptr && window->hasFocus()) && sf::Mouse::isButtonPressed(sf::Mouse::XButton1);
    };

    bool extra2() {
      return (window != nullptr && window->hasFocus()) && sf::Mouse::isButtonPressed(sf::Mouse::XButton2);
    };
  };
};