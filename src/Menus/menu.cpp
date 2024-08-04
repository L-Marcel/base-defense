#include <Engine.hpp>

namespace Game {
  string Menu::type() {
    return "Menu";
  };

  Menu::Menu(string spriteSheet, Box box) 
  : Object2D(spriteSheet, box) {};

  Menu::~Menu() {};

  void Menu::close() {
    for(unsigned int i = 0; i < this->objects.length(); i++) {
      this->objects.get(i)->destroy();
    };
    for(unsigned int i = 0; i < this->texts.length(); i++) {
      this->texts.get(i)->destroy();
    };
    this->destroy();
  };
};