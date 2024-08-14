#include <Objects/ammo_display.hpp>

namespace Game {
  string AmmoDisplay::type() {
    return "AmmoDisplay";
  };

  void AmmoDisplay::step() {
    const Base* base = Base::get();
    const Player* player = Player::get();

    if(base == nullptr || player == nullptr) {
      this->hud->setText("0/0");
      this->hud->setAlignCenter();
      return;
    };

    string content = to_string(player->clip.get()) + "/" + to_string(base->clip.get());
    this->hud->setText(content);
    this->hud->setAlignCenter();
  };

  AmmoDisplay::~AmmoDisplay() {};

  AmmoDisplay* AmmoDisplay::create() {
    AmmoDisplay* ammo_display = new AmmoDisplay("ammo_display.png", Box(32.5, 12.5, 65, 25));
    ammo_display->scale(2);
    ammo_display->depth = 200;
    ammo_display->position = Point(72, 134);
    GameProcess::add(ammo_display);

    Text* hud = Text::create(Point(93, 135), "6/24", 18);
    hud->setAlignCenter();
    hud->depth = 300;
    ammo_display->hud = hud;
    return ammo_display;
  };
};