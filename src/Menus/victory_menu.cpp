#include <Menus.hpp>

namespace Game {
  string VictoryMenu::type() {
    return "VictoryMenu";
  };

  VictoryMenu::~VictoryMenu() {};

  VictoryMenu::VictoryMenu(string sprite_sheet, Box box) 
  : Menu(sprite_sheet, box) {};

  VictoryMenu* VictoryMenu::create() {
    VictoryMenu* victory_menu = new VictoryMenu("victory_screen.png", Box(0, 0, 1280, 720));
    victory_menu->pausable = false;
    victory_menu->position.x = 0;
    victory_menu->position.y = 0;
    victory_menu->depth = 400;
    GameProcess::add(victory_menu);
    
    RestartButton* restart_button = RestartButton::create();
    restart_button->position = CENTER;
    restart_button->position.y += 100;
    victory_menu->objects.add(restart_button);

    return victory_menu;
  };
};