#include <Objects/background.hpp>

namespace Game {
  string Background::type() {
    return "Background";
  };

  Background::~Background() {};

  Background::Background(string spriteSheet, Box box) 
  : Object2D(spriteSheet, box) {};

  Background* Background::create(GameProcess* gp) {
    Background* background = new Background("background.png", Box(0, 0, 640, 360));
    background->depth = -100;
    background->scale(2);
    background->gp = gp;
    gp->objects.add(background);
    return background;
  };
};