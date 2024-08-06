#include <Menus.hpp>

namespace Game {
  string PauseMenu::type() {
    return "PauseMenu";
  };

  PauseMenu::~PauseMenu() {};

  PauseMenu::PauseMenu(string spriteSheet, Box box) 
  : Menu(spriteSheet, box) {};

  PauseMenu* PauseMenu::create() {
    PauseMenu* pauseMenu = new PauseMenu("pause_screen.png", Box(0, 0, 1280, 720));
    pauseMenu->pausable = false;
    pauseMenu->position.x = 0;
    pauseMenu->position.y = 0;
    pauseMenu->depth = 400;
    GameProcess::add(pauseMenu);

    pauseMenu->objects.add(ResumeButton::create());
    pauseMenu->objects.add(OptionsButton::create());
    pauseMenu->objects.add(CloseButton::create());

    float y = 125;
    float gap = 50;
    for(unsigned int i = 0; i < pauseMenu->objects.length(); i++) {
      Object2D* object = pauseMenu->objects.get(i);
      object->position.y = y;

      unsigned int height = object->sprite->getTextureRect().height * object->sprite->getScale().y * 0.5;
      y += height + gap;
    };

    return pauseMenu;
  };
};