#include <Objects/base.hpp>
#include <Objects/enemy.hpp>
#include <iomanip>
#include <sstream>

namespace Game {
  string Base::type() {
    return "Base";
  };

  void Base::step() {
    std::stringstream stream;
    stream << fixed << setprecision(2) << this->health.get();
    string content = stream.str();

    this->hud->setText(content);
    this->hud->setPosition(Point(632 - (content.length() * 8), 400));
  };

  Base::~Base() {
    this->hud->setText("0");
    for(unsigned int i = 0; i < this->parts.length(); i++) {
      Object2D* part = this->parts.get(i);
      string type = part->type();
      if(type == "Wall") {
        Wall* wall = (Wall*) part;
        wall->energized = false;
        wall->base = nullptr;
      } else if(type == "Tower") {
        Tower* tower = (Tower*) part;
        tower->energized = false;
        tower->base = nullptr;
      };
    };
  };

  Base* Base::create() {
    Base* base = new Base();
    base->depth = -50;
    base->position = CENTER;
    base->setRectangle(BASE_SIZE.x, BASE_SIZE.y);
    GameProcess::add(base);

    Tower* tower_one = Tower::create(base);
    tower_one->position = TOP_LEFT_TOWER_POSITION;
    tower_one->setRectangle(TOWER_SIZE, TOWER_SIZE);
    Tower* tower_two = Tower::create(base);
    tower_two->position = BOTTOM_LEFT_TOWER_POSITION;
    tower_two->setRectangle(TOWER_SIZE, TOWER_SIZE);
    Tower* tower_three = Tower::create(base);
    tower_three->position = TOP_RIGHT_TOWER_POSITION;
    tower_three->setRectangle(TOWER_SIZE, TOWER_SIZE);
    Tower* tower_four = Tower::create(base);
    tower_four->position = BOTTOM_RIGHT_TOWER_POSITION;
    tower_four->setRectangle(TOWER_SIZE, TOWER_SIZE);

    Enemy::wab = Wall::create(base, 2);
    Enemy::wbc = Wall::create(base, 1);
    Enemy::wcd = Wall::create(base, 3);
    Enemy::wda = Wall::create(base, 0);

    base->parts.add(tower_one);
    base->parts.add(tower_two);
    base->parts.add(tower_three);
    base->parts.add(tower_four);
    base->parts.add(Enemy::wab);
    base->parts.add(Enemy::wbc);
    base->parts.add(Enemy::wcd);
    base->parts.add(Enemy::wda);

    Text* hud = Text::create(Point(640, 400), to_string(base->health.get()));
    base->hud = hud;

    return base;
  };
};