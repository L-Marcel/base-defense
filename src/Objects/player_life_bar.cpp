#include <Objects/player_life_bar.hpp>

namespace Game {
  string PlayerLifeBar::type() {
    return "PlayerLifeBar";
  };

  void PlayerLifeBar::step() {
    const Player* player = Player::get();

    if(player == nullptr) {
      this->hud->setText("0.00");
      this->hud->setAlignCenter();
      this->rectangle.setSize(Point(0, 20));
      return;
    };

    if(this->life_percent > player->health.percent()) {
      this->life_percent = max(this->life_percent - 0.015f, player->health.percent());
    } else {
      this->life_percent = min(this->life_percent + 0.015f, player->health.percent());
    };
    this->rectangle.setSize(Point(this->life_percent * 230, 26));

    stringstream stream;
    stream << fixed << setprecision(2) << player->health.get();
    string content = stream.str();
    this->hud->setText(content);
    this->hud->setAlignCenter();
  };

  void PlayerLifeBar::draw() {
    this->rectangle.setPosition(Point(173,31));
    GameProcess::animate(this);
    GameProcess::draw(*this->sprite);
    GameProcess::draw(this->rectangle);
  };

  PlayerLifeBar::~PlayerLifeBar() {};
  
  PlayerLifeBar* PlayerLifeBar::create() {
    PlayerLifeBar* life_bar = new PlayerLifeBar("player_life_bar.png", Box(72.5, 12.5, 145, 25));;
    life_bar->scale(2);
    life_bar->depth = 200;
    life_bar->position = Point(152, 30);
    life_bar->setRectangle(230,26);
    life_bar->rectangle.setFillColor(Color(232, 59, 59, 255));
    GameProcess::add(life_bar);

    Text* hud = Text::create(Point(174, 32), "100.00", 18);
    hud->setAlignCenter();
    hud->depth = 300;
    life_bar->hud = hud;
    return life_bar;
  };
};