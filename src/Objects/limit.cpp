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
    gp->window.draw(this->rectangle);
  };

  Limit::~Limit() {};

  Limit::Limit() {};

  void Limit::create(GameProcess* gp) {
    Limit* left = new Limit();
    left->position = Point(-110, 360);
    left->setRectangle(200, 720);
    left->gp = gp;
    gp->objects.add(left);

    Limit* right = new Limit();
    right->position = Point(1380, 360);
    right->setRectangle(200, 720);
    right->gp = gp;
    gp->objects.add(right);

    Limit* top = new Limit();
    top->position = Point(640, -100);
    top->setRectangle(1280, 200);
    top->gp = gp;
    gp->objects.add(top);

    Limit* bottom = new Limit();
    bottom->position = Point(640, 820);
    bottom->setRectangle(1280, 200);
    bottom->gp = gp;
    gp->objects.add(bottom);

    Collision::create(gp, left, "Bullet");
    Collision::create(gp, right, "Bullet");
    Collision::create(gp, top, "Bullet");
    Collision::create(gp, bottom, "Bullet");
  };
};