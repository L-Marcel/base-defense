#include <Objects/player_life_bar.hpp>

namespace Game {
  string PlayerLifeBar::type() {
    return "PlayerLifeBar";
  };

  void PlayerLifeBar::step() {
    GameProcess::draw(this->rectangle);

    if(this->lifePercent > this->player->health.percent()) {
      this->lifePercent = max(this->lifePercent - 0.015f, this->player->health.percent());
    } else {
      this->lifePercent = min(this->lifePercent + 0.015f, this->player->health.percent());
    };
    this->rectangle.setSize(Point(this->lifePercent * 230, 20));

    stringstream stream;
    stream << fixed << setprecision(2) << this->player->health.get();
    string content = stream.str();
    this->hud->setText(content);

    if(content.length() == 6) {
      this->hud->setPosition(Point(142, 29));
    } else if(content.length() == 5) {
      this->hud->setPosition(Point(144, 29));
    } else if(content.length() == 4) {
      this->hud->setPosition(Point(150, 29));
    };
  };

  PlayerLifeBar::~PlayerLifeBar() {};
  
  PlayerLifeBar* PlayerLifeBar::create() {
    PlayerLifeBar* playerLB = new PlayerLifeBar();
    playerLB->depth = 500;
    playerLB->position = Point(140, 30);
    playerLB->setRectangle(230,20);
    playerLB->rectangle.setFillColor(Color::Red);
    GameProcess::add(playerLB);

    stringstream stream;
    stream << fixed << setprecision(2) << playerLB->player->health.get();
    string content = stream.str();

    Text* hud = Text::create(Point(142, 29), content, 18);
    hud->depth = 600;
    playerLB->hud = hud;
    return playerLB;
  };
};