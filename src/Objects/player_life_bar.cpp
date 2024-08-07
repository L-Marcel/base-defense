#include <Objects/player_life_bar.hpp>

namespace Game {
  string PlayerLifeBar::type() {
    return "PlayerLifeBar";
  };

  void PlayerLifeBar::step() {
    GameProcess::draw(this->rectangle);
    const Player* player = Player::get();

    if(player == nullptr) {
      this->hud->setText("0.00");
      this->hud->setAlignCenter();
      this->rectangle.setSize(Point(0, 20));
      return;
    };

    if(this->lifePercent > player->health.percent()) {
      this->lifePercent = max(this->lifePercent - 0.015f, player->health.percent());
    } else {
      this->lifePercent = min(this->lifePercent + 0.015f, player->health.percent());
    };
    this->rectangle.setSize(Point(this->lifePercent * 230, 26));

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
    PlayerLifeBar* lifeBar = new PlayerLifeBar("player_life_bar.png", Box(72.5,12.5, 145, 25));;
    lifeBar->scale(2);
    lifeBar->depth = 200;
    lifeBar->position = Point(152, 30);
    lifeBar->setRectangle(230,26);
    lifeBar->rectangle.setFillColor(Color(232, 59, 59, 255));
    GameProcess::add(lifeBar);

    Text* hud = Text::create(Point(174, 32), "100.00", 18);
    hud->setAlignCenter();
    hud->depth = 300;
    lifeBar->hud = hud;
    return lifeBar;
  };
};