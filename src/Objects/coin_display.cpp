#include <Objects/coin_display.hpp>

namespace Game {
  string CoinDisplay::type() {
    return "CoinDisplay";
  };

  void CoinDisplay::step() {
    string content = to_string(GameProcess::money);
    this->hud->setText(content);

    if(content.length() < 3){
      this->position = Point(1210, 25);
      this->hud->setPosition(Point(1250, 25));
    };
    this->hud->setAlignCenter();
  };

  CoinDisplay::~CoinDisplay() {};

  CoinDisplay* CoinDisplay::create() {
    CoinDisplay* coinDisplay = new CoinDisplay("coin.png", Box(8.5, 8.5, 17, 17));
    coinDisplay->scale(2);
    coinDisplay->depth = 400;
    coinDisplay->position = Point(1190, 25);
    GameProcess::add(coinDisplay);

    Text* hud = Text::create(Point(1240, 25), "0", 18);
    hud->setAlignCenter();
    hud->depth = 400;
    coinDisplay->hud = hud;
    return coinDisplay;
  };
};