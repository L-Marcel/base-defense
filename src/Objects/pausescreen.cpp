#include <Objects/pausescreen.hpp>

namespace Game{
  string PauseScreen::type(){
    return "PauseScreen";
  }

  PauseScreen::~PauseScreen(){};

  PauseScreen::PauseScreen(string spriteSheet, Box box) 
  : Object2D(spriteSheet, box) {};

  PauseScreen* PauseScreen::create(GameProcess* gp){
    PauseScreen* pausescreen = new PauseScreen("pause_screen.png", Box(0, 0, 1280, 720));
    pausescreen->pausable = false;
    pausescreen->position.x = 0;
    pausescreen->position.y = 0;
    pausescreen->depth = 20;
    pausescreen->gp = gp;
    gp->objects.add(pausescreen);
    return pausescreen;
  }
}