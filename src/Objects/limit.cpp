#include <Objects/limit.hpp>

namespace Game {
  string Limit::type() {
    return "Limit";
  };

  void Limit::step() {
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      collider->destroy();
    };
  };

  void Limit::draw() {
    GameProcess::draw(this->rectangle);
  };

  Limit::~Limit() {};

  Limit::Limit() {};

  void Limit::create() {
    Limit* left = new Limit();
    left->position = Point(-110, 360);
    left->setRectangle(200, 720);
    GameProcess::add(left);

    Limit* right = new Limit();
    right->position = Point(1380, 360);
    right->setRectangle(200, 720);
    GameProcess::add(right);

    Limit* top = new Limit();
    top->position = Point(640, -100);
    top->setRectangle(1280, 200);
    GameProcess::add(top);

    Limit* bottom = new Limit();
    bottom->position = Point(640, 820);
    bottom->setRectangle(1280, 200);
    GameProcess::add(bottom);

    Collision::create(left, "Bullet");
    Collision::create(right, "Bullet");
    Collision::create(top, "Bullet");
    Collision::create(bottom, "Bullet");
  };
};