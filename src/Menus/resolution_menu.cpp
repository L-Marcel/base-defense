#include <Menus.hpp>

namespace Game {
  string ResolutionMenu::type() {
    return "ResolutionMenu";
  };

  ResolutionMenu::~ResolutionMenu() {};

  ResolutionMenu::ResolutionMenu(string spriteSheet, Box box) 
  : Menu(spriteSheet, box) {};

  ResolutionMenu* ResolutionMenu::create() {
    ResolutionMenu* resolutionMenu = new ResolutionMenu("pause_screen.png", Box(0, 0, 1280, 720));
    resolutionMenu->pausable = false;
    resolutionMenu->position.x = 0;
    resolutionMenu->position.y = 0;
    resolutionMenu->depth = 400;
    GameProcess::add(resolutionMenu);

    resolutionMenu->objects.add(FullscreenButton::create());
    resolutionMenu->objects.add(ResolutionButton::create(R1280x720));
    resolutionMenu->objects.add(ResolutionButton::create(R1024x576));
    resolutionMenu->objects.add(ResolutionButton::create(R800x600));
    resolutionMenu->objects.add(ReturnButton::create(PauseMenu::create));

    float y = 125;
    float gap = 50;
    for(unsigned int i = 0; i < resolutionMenu->objects.length(); i++) {
      Object2D* object = resolutionMenu->objects.get(i);
      object->position.y = y;

      unsigned int height = object->sprite->getTextureRect().height * object->sprite->getScale().y * 0.5;
      y += height + gap;
    };

    return resolutionMenu;
  };
}