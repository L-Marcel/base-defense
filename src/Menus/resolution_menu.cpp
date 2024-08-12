#include <Menus.hpp>

namespace Game {
  string ResolutionMenu::type() {
    return "ResolutionMenu";
  };

  ResolutionMenu::~ResolutionMenu() {};

  ResolutionMenu::ResolutionMenu(string sprite_sheet, Box box) 
  : Menu(sprite_sheet, box) {};

  ResolutionMenu* ResolutionMenu::create() {
    ResolutionMenu* resolution_menu = new ResolutionMenu("pause_screen.png", Box(0, 0, 1280, 720));
    resolution_menu->pausable = false;
    resolution_menu->position.x = 0;
    resolution_menu->position.y = 0;
    resolution_menu->depth = 400;
    GameProcess::add(resolution_menu);

    resolution_menu->objects.add(FullscreenButton::create());
    resolution_menu->objects.add(ResolutionButton::create(R1280x720));
    resolution_menu->objects.add(ResolutionButton::create(R1024x576));
    resolution_menu->objects.add(ResolutionButton::create(R800x600));
    resolution_menu->objects.add(ReturnButton::create(PauseMenu::create));

    float y = 125;
    float gap = 50;
    for(unsigned int i = 0; i < resolution_menu->objects.length(); i++) {
      Object2D* object = resolution_menu->objects.get(i);
      object->position.y = y;

      unsigned int height = object->sprite->getTextureRect().height * object->sprite->getScale().y * 0.5;
      y += height + gap;
    };

    return resolution_menu;
  };
};