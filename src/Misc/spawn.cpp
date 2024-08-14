#include <Misc/spawn.hpp>
#include <Objects/enemy.hpp>
#include <cstdlib>

namespace Game {
  Timer Spawn::wave_delay;
  Timer Spawn::shop_delay;
  float Spawn::spawn_speed = 0.50;
  unsigned int Spawn::amount = 0;
  unsigned int Spawn::wave = 0;

  string Spawn::type() {
    return "Spawn";
  };

  void Spawn::step() {
    this->spawn_delay.tick();
    this->wave_delay.tick();

    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      collider->destroy();
    };
    
    if(
      this->spawn_delay.isFinished() && 
      this->wave_delay.isFinished() && 
      this->amount > 0
    ) {
      this->spawn();
      this->spawn_delay.start((1/this->spawn_speed) + (rand() % 8));
    } else if(
      this->amount == 0 && 
      Enemy::amount == 0 && 
      this->wave < FINAL_WAVE
    ) {
      int delay = 4 + (rand() % 3);
      this->shop_delay.start(delay * 4.0);
      this->wave_delay.start(delay * 8.0);
      this->wave = min(int(this->wave + 1), FINAL_WAVE);
      this->amount = floor((int(this->wave) - 1) * 0.85) + 5; 
      this->spawn_speed += 0.025;
      this->text->setText(to_string(this->wave) + "/" + to_string(FINAL_WAVE));
      this->text->setAlignCenter();
    } else if(
      this->amount == 0 && 
      Enemy::amount == 0 && 
      this->wave == FINAL_WAVE
    ) GameProcess::victory();

    if(!this->wave_delay.isFinished() && !this->shop_delay.isFinished()) {
      this->shop_delay.tick();
      if(this->wave > 1 && this->shop_delay.isFinished()) GameProcess::pause(true);
    };
  };

  Spawn::~Spawn() {};

  Spawn::Spawn() {};

  void Spawn::create() {
    Text* text = Text::create(CENTER, "1/15");
    text->setAlignCenter();
    text->depth = 1;

    Spawn* left = new Spawn();
    left->position = Point(-110, 360);
    left->setRectangle(200, 720);
    left->spawn_delay.start(4 + (rand() % 5));
    left->text = text;
    GameProcess::add(left);

    Spawn* right = new Spawn();
    right->position = Point(1380, 360);
    right->setRectangle(200, 720);
    right->spawn_delay.start(4 + (rand() % 5));
    right->text = text;
    GameProcess::add(right);

    Spawn* top = new Spawn();
    top->position = Point(640, -100);
    top->setRectangle(1280, 200);
    top->spawn_delay.start(4 + (rand() % 5));
    top->text = text;
    GameProcess::add(top);

    Spawn* bottom = new Spawn();
    bottom->position = Point(640, 820);
    bottom->setRectangle(1280, 200);
    bottom->spawn_delay.start(4 + (rand() % 5));
    bottom->text = text;
    GameProcess::add(bottom);

    Collision::create(left, "Bullet");
    Collision::create(right, "Bullet");
    Collision::create(top, "Bullet");
    Collision::create(bottom, "Bullet");
  };
  
  void Spawn::spawn() { 
    this->amount--;

    float x = this->position.x;
    float y = this->position.y;
    
    Size size = this->rectangle.getSize();

    float local = ((Math::randomChance() - 50.0) / 100.0) / 1.5;
    if(size.x > size.y) x += local * size.x;
    else y += local * size.y;
    
    Enemy::create(x, y);
  };
};

