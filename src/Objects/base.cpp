#include <Objects/base.hpp>
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
    this->hud->setPosition(Vector<float>(632 - (content.length() * 8), 400));
  };

  Base::~Base() {
    this->hud->setText("0");
    for(unsigned int i = 0; i < this->parts.length(); i++) {
      Object2D* part = this->parts.get(i);
      string type = part->type();
      if(type == "Wall") {
        Wall* wall = (Wall*) part;
        wall->energized = false;
      } else if(type == "Tower") {
        Tower* tower = (Tower*) part;
        tower->energized = false;
      };
    };
  };

  Base* Base::create(GameProcess* gp) {
    Base* base = new Base();
    base->depth = -50;
    base->position = CENTER;
    base->setRectangle(BASE_SIZE.x, BASE_SIZE.y);
    base->gp = gp;

    Tower* tower_one = Tower::create(gp, base);
    tower_one->position = TOP_LEFT_TOWER_POSITION;
    tower_one->setRectangle(TOWER_SIZE, TOWER_SIZE);
    Tower* tower_two = Tower::create(gp, base);
    tower_two->position = BOTTOM_LEFT_TOWER_POSITION;
    tower_two->setRectangle(TOWER_SIZE, TOWER_SIZE);
    Tower* tower_three = Tower::create(gp, base);
    tower_three->position = TOP_RIGHT_TOWER_POSITION;
    tower_three->setRectangle(TOWER_SIZE, TOWER_SIZE);
    Tower* tower_four = Tower::create(gp, base);
    tower_four->position = BOTTOM_RIGHT_TOWER_POSITION;
    tower_four->setRectangle(TOWER_SIZE, TOWER_SIZE);

    base->parts.add(tower_one);
    base->parts.add(tower_two);
    base->parts.add(tower_three);
    base->parts.add(tower_four);
    base->parts.add(Wall::create(gp, base, 0));
    base->parts.add(Wall::create(gp, base, 1));
    base->parts.add(Wall::create(gp, base, 2));
    base->parts.add(Wall::create(gp, base, 3));

    Text* hud = Text::create(gp, Vector<float>(640, 400), to_string(base->health.get()));
    base->hud = hud;
    gp->objects.add(base);

    return base;
  };
};