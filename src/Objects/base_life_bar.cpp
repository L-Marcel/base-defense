#include <Objects/base_life_bar.hpp>

namespace Game {
  string BaseLifeBar::type() {
    return "BaseLifeBar";
  };

  void BaseLifeBar::step() {
    const  Base* base = Base::get();

    if(base == nullptr) {
      this->hud->setText("0.00");
      this->hud->setAlignCenter();
      this->rectangle.setSize(Point(0, 20));
      return;
    };

    if(this->lifePercent > base->health.percent()) {
      this->lifePercent = max(this->lifePercent - 0.015f, base->health.percent());
    } else {
      this->lifePercent = min(this->lifePercent + 0.015f, base->health.percent());
    };
    this->rectangle.setSize(Point(this->lifePercent * 230, 26));

    stringstream stream;
    stream << fixed << setprecision(2) << base->health.get();
    string content = stream.str();
    this->hud->setText(content);
    this->hud->setAlignCenter();
  };

  void BaseLifeBar::draw() {
    this->rectangle.setPosition(Point(173,83));
    GameProcess::animate(this);
    GameProcess::draw(*this->sprite);
    GameProcess::draw(this->rectangle);
  };

  BaseLifeBar::~BaseLifeBar() {};

  BaseLifeBar* BaseLifeBar::create() {
    BaseLifeBar* lifeBar = new BaseLifeBar("base_life_bar.png",Box(72.5, 12.5, 145, 25));
    lifeBar->scale(2);
    lifeBar->depth = 200;
    lifeBar->position = Point(152, 82);
    lifeBar->setRectangle(230,26);
    lifeBar->rectangle.setFillColor(Color(72, 74, 119, 255));
    GameProcess::add(lifeBar);

    Text* hud = Text::create(Point(174, 83), "100.00", 18);
    hud->setAlignCenter();
    hud->depth = 300;
    lifeBar->hud = hud;
    return lifeBar;
  };
};