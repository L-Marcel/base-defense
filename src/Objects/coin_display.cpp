#include <Objects/coin_display.hpp>

namespace Game {
  string CoinDisplay::type() {
    return "CoinDisplay";
  };

  void CoinDisplay::step() {
    string content = to_string(GameProcess::money);
    this->hud->setText(content);
    if(GameProcess::in("ShopMenu")) {
      if(this->depth == 300) {
        this->depth = 500;
        this->scale(3);
        this->hud->depth = 500;
        this->hud->setSize(27);
        GameProcess::sort();
      };

      Size size = this->hud->getSize();
      float x = (66 + size.x) / 2.0;
      
      this->position = Point(CENTER.x - x + 25.5, CENTER.y + 100);
      this->hud->setPosition(Point(CENTER.x - x + 66, CENTER.y + 100));
      this->hud->setAlignLeft();
    } else {
      if(this->depth == 500) {
        this->depth = 300;
        this->scale(2);
        this->hud->depth = 300;
        this->hud->setSize(27);
        GameProcess::sort();
      };

      this->position = Point(1250, 30);
      this->hud->setPosition(Point(1220, 30));
      this->hud->setAlignRight();
    };
  };

  CoinDisplay::~CoinDisplay() {};

  CoinDisplay* CoinDisplay::create() {
    CoinDisplay* coin_display = new CoinDisplay("coin.png", Box(8.5, 8.5, 17, 17));
    coin_display->scale(2);
    coin_display->depth = 300;
    coin_display->position = Point(1190, 25);
    coin_display->pausable = false;
    GameProcess::add(coin_display);

    Text* hud = Text::create(Point(1240, 25), "0", 18);
    hud->setAlignCenter();
    hud->depth = 300;
    coin_display->hud = hud;
    return coin_display;
  };
};