#include <Input.hpp>
#include <Engine/process.hpp>

namespace Game {
  vector<MouseButton> Mouse::down;
  vector<MouseButton> Mouse::pressed;
  vector<MouseButton> Mouse::released;

  void Mouse::update() {
    Mouse::pressed.clear();
    Mouse::released.clear();
  };

  Point Mouse::position() {
    const Window& window = GameProcess::getWindow();
    return Point(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
  };

  void Mouse::press(MouseButton button) {
    if(!Mouse::isDown(button) && GameProcess::getWindow().hasFocus()) {
      Mouse::pressed.push_back(button);
      Mouse::down.push_back(button);
    };
  };

  void Mouse::release(MouseButton button) {
    for(unsigned short int i = 0; i < Mouse::down.size(); i++) {
      if(Mouse::down.at(i) == button) {
        Mouse::down.erase(Mouse::down.begin() + i);
        Mouse::released.push_back(button);
        break;
      };
    };
  };

  bool Mouse::isDown(MouseButton button) {
    for(unsigned short int i = 0; i < Mouse::down.size(); i++) {
      if(Mouse::down.at(i) == button) {
        return true;
      };
    };
    return false;
  };

  bool Mouse::isPressed(MouseButton button) {
    for(unsigned short int i = 0; i < Mouse::pressed.size(); i++) {
      if(Mouse::pressed.at(i) == button) {
        return true;
      };
    };
    return false;
  };

  bool Mouse::isReleased(MouseButton button) {
    for(unsigned short int i = 0; i < Mouse::released.size(); i++) {
      if(Mouse::released.at(i) == button) {
        return true;
      };
    };
    return false;
  };

  bool Mouse::isLeftPressed() {
    return Mouse::isPressed(MouseButton::Left);
  };

  bool Mouse::isLeftReleased() {
    return Mouse::isReleased(MouseButton::Left);
  };

  bool Mouse::isLeftDown() {
    return Mouse::isDown(MouseButton::Left);
  };

  bool Mouse::isRightPressed() {
    return Mouse::isPressed(MouseButton::Right);
  };

  bool Mouse::isRightReleased() {
    return Mouse::isReleased(MouseButton::Right);
  };

  bool Mouse::isRightDown() {
    return Mouse::isDown(MouseButton::Right);
  };
};