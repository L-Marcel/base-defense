#include <Menus.hpp>

namespace Game {
  string PauseMenu::type() {
    return "PauseMenu";
  };

  PauseMenu::~PauseMenu() {};

  PauseMenu::PauseMenu(string sprite_sheet, Box box) 
  : Menu(sprite_sheet, box) {};

  PauseMenu* PauseMenu::create() {
    PauseMenu* pause_menu = new PauseMenu("pause_screen.png", Box(0, 0, 1280, 720));
    pause_menu->pausable = false;
    pause_menu->position.x = 0;
    pause_menu->position.y = 0;
    pause_menu->depth = 400;
    GameProcess::add(pause_menu);

    pause_menu->objects.add(ResumeButton::create());
    pause_menu->objects.add(OptionsButton::create());
    pause_menu->objects.add(RestartButton::create());
    pause_menu->objects.add(CloseButton::create());

    float y = 125;
    float gap = 50;
    for(unsigned int i = 0; i < pause_menu->objects.length(); i++) {
      Object2D* object = pause_menu->objects.get(i);
      object->position.y = y;

      unsigned int height = object->sprite->getTextureRect().height * object->sprite->getScale().y * 0.5;
      y += height + gap;
    };

    return pause_menu;
  };
};