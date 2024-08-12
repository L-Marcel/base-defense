#include <Menus.hpp>

namespace Game {
  string DefeatMenu::type() {
    return "DefeatMenu";
  };

  DefeatMenu::~DefeatMenu() {};

  DefeatMenu::DefeatMenu(string sprite_sheet, Box box) 
  : Menu(sprite_sheet, box) {};

  DefeatMenu* DefeatMenu::create() {
    DefeatMenu* defeat_menu = new DefeatMenu("defeat_screen.png", Box(0, 0, 1280, 720));
    defeat_menu->pausable = false;
    defeat_menu->position.x = 0;
    defeat_menu->position.y = 0;
    defeat_menu->depth = 400;
    GameProcess::add(defeat_menu);
    
    RestartButton* restart_button = RestartButton::create();
    restart_button->position = CENTER;
    restart_button->position.y += 100;
    defeat_menu->objects.add(restart_button);

    return defeat_menu;
  };
};