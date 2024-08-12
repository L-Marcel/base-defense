#include <Objects/ammo_display.hpp>

namespace Game {
  string AmmoDisplay::type() {
    return "AmmoDisplay";
  };

  void AmmoDisplay::step() {
    const  Base* base = Base::get();
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
    AmmoDisplay* ammoDisplay = new AmmoDisplay("ammo_display.png", Box(32.5, 12.5, 65, 25));
    ammoDisplay->scale(2);
    ammoDisplay->depth = 200;
    ammoDisplay->position = Point(72, 134);
    GameProcess::add(ammoDisplay);

    Text* hud = Text::create(Point(93, 135), "6/24", 18);
    hud->setAlignCenter();
    hud->depth = 300;
    ammoDisplay->hud = hud;
    return ammoDisplay;
  };
};