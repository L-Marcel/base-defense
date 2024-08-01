#include <Input.hpp>
#include <Engine/process.hpp>

namespace Game {
  vector<Key> Input::down;
  vector<Key> Input::pressed;
  vector<Key> Input::released;

  void Input::update() {
    Input::pressed.clear();
    Input::released.clear();
  };

  void Input::press(Key key) {
    if(!Input::isDown(key) && GameProcess::getWindow().hasFocus()) {
      Input::pressed.push_back(key);
      Input::down.push_back(key);
    };
  };

  void Input::release(Key key) {
    for(unsigned short int i = 0; i < Input::down.size(); i++) {
      if(Input::down.at(i) == key) {
        Input::down.erase(Input::down.begin() + i);
        Input::released.push_back(key);
        break;
      };
    };
  };

  bool Input::isDown(Key key) {
    for(unsigned short int i = 0; i < Input::down.size(); i++) {
      if(Input::down.at(i) == key) {
        return true;
      };
    };
    return false;
  };

  bool Input::isPressed(Key key) {
    for(unsigned short int i = 0; i < Input::pressed.size(); i++) {
      if(Input::pressed.at(i) == key) {
        return true;
      };
    };
    return false;
  };

  bool Input::isReleased(Key key) {
    for(unsigned short int i = 0; i < Input::released.size(); i++) {
      if(Input::released.at(i) == key) {
        return true;
      };
    };
    return false;
  };
};