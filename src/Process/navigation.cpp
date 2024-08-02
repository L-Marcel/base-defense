#include <Engine.hpp>
#include <Menus.hpp>

namespace Game {
  void GameProcess::close() {
    GameProcess::gp->window.close();
  };

  void GameProcess::pause(bool shop) {
    GameProcess::gp->paused = true;
    if(shop) GameProcess::navigate(ShopMenu::create());
    else GameProcess::navigate(PauseMenu::create());
  };

  void GameProcess::resume() {
    GameProcess::gp->paused = false;
    GameProcess::navigate();
  };
  
  void GameProcess::navigate(Menu* menu) {
    if(GameProcess::gp->menu != nullptr) GameProcess::gp->menu->close();
    GameProcess::gp->menu = menu;
  };
};