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
    base->position = Vector<float>(640, 360);
    base->setRectangle(416, 288);
    base->gp = gp;

    Tower* tower_one = Tower::create(gp, base);
    tower_one->position = Vector<float>(448, 232);
    tower_one->setRectangle(32, 32);
    Tower* tower_two = Tower::create(gp, base);
    tower_two->position = Vector<float>(448, 488);
    tower_two->setRectangle(32, 32);
    Tower* tower_three = Tower::create(gp, base);
    tower_three->position = Vector<float>(832, 232);
    tower_three->setRectangle(32, 32);
    Tower* tower_four = Tower::create(gp, base);
    tower_four->position = Vector<float>(832, 488);
    tower_four->setRectangle(32, 32);

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