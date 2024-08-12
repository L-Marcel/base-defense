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

    void GameProcess::defeat() {
    GameProcess::gp->paused = true;
    GameProcess::navigate(DefeatMenu::create());
  };

  void GameProcess::victory() {
    GameProcess::gp->paused = true;
    GameProcess::navigate(VictoryMenu::create());
  };

  void GameProcess::resume() {
    GameProcess::gp->paused = false;
    GameProcess::navigate();
  };
  
  void GameProcess::navigate(Menu* menu) {
    Input::update();
    Mouse::update();
    if(GameProcess::gp->menu != nullptr) GameProcess::gp->menu->close();
    if(GameProcess::gp->menu == nullptr && menu != nullptr) GameProcess::open_sound.play();
    GameProcess::gp->menu = menu;
  };

  bool GameProcess::in(string menu) {
    if(GameProcess::gp == nullptr || GameProcess::gp->menu == nullptr) return false;
    return GameProcess::gp->menu->type() == menu;
  };
};