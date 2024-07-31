#include <Objects/background.hpp>

namespace Game {
  string Background::type() {
    return "Background";
  };

  Background::~Background() {};

  Background::Background(string spriteSheet, Box box) 
  : Object2D(spriteSheet, box) {};

  Background* Background::create() {
    Background* background = new Background("background.png", Box(0, 0, 640, 360));
    background->depth = -100;
    background->scale(2);
    background->setRectangle(208 * 2, 144 * 2);
    GameProcess::add(background);
    return background;
  };
};