#include <Objects/limit.hpp>
#include <Objects/enemy.hpp>
#include <cstdlib>

namespace Game {
  string Limit::type() {
    return "Limit";
  };

  void Limit::step() {
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      collider->destroy();
    };
    this->spawn_delay.tick();
    if (this->spawn_delay.isFinished())
    {
      this->spawnEnemy();
      this->spawn_delay.start(1/this->spawn_speed);
    }
    
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
    left->spawn_delay.start(rand() % 6 + ((rand() % 6) - 3));
    left->spawnEnemy();
    GameProcess::add(left);

    Limit* right = new Limit();
    right->position = Point(1380, 360);
    right->setRectangle(200, 720);
    right->spawn_delay.start(rand() % 6 + ((rand() % 6) - 3));
    GameProcess::add(right);

    Limit* top = new Limit();
    top->position = Point(640, -100);
    top->setRectangle(1280, 200);
    top->spawn_delay.start(rand() % 6 + ((rand() % 6) - 3));
    GameProcess::add(top);

    Limit* bottom = new Limit();
    bottom->position = Point(640, 820);
    bottom->setRectangle(1280, 200);
    bottom->spawn_delay.start(rand() % 6 + ((rand() % 6) - 3));
    GameProcess::add(bottom);

    Collision::create(left, "Bullet");
    Collision::create(right, "Bullet");
    Collision::create(top, "Bullet");
    Collision::create(bottom, "Bullet");
  };
  
  void Limit::spawnEnemy()
  { 
    float x = this->position.x;
    float y = this->position.y;
    sf::Vector2f size = this->rectangle.getSize();

    if (size.x > size.y) {
      // Top or Bottom limit
      x += static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / size.x));
    } else {
      // Left or Right limit
      y += static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / size.y));
    }

    if (GameProcess::current < GameProcess::max)
    {
      Enemy::create(x, y);
    }
    
    
  }
};

