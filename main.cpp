#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
  GameProcess gp;
  GameProcess::setResolution(R1280x720);
   
  Music music("default.ogg");
  music.setVolume(30);
  music.play();

  Background::create();
  Limit::create();

  Player* player = Player::create();
  player->scale(2);
  
  Base::create();
  
  Enemy* enemy = Enemy::create();
  enemy->scale(2);
  Collision::create(enemy, "Bullet");

  Text* text = Text::create(Point(572, 120), "Exemplo");
  text->depth = 20;

  // ResolutionButton* res1 = ResolutionButton::create(&gp, "button.png", Box(32, 16, 64, 32), true, 1280, 720);
  // res1->position.x = 420;
  // res1->position.y = 200;
  // res1->scale(3);
  // res1->setText("1280x720", 30);
  // res1->setVisible(false);

  // ResolutionButton* res2 = ResolutionButton::create(&gp, "button.png", Box(32, 16, 64, 32), true, 1024, 576);
  // res2->position.x = 640;
  // res2->position.y = 200;
  // res2->scale(3);
  // res2->setText("1024x576", 30);
  // res2->setVisible(false);

  // ResolutionButton* res3 = ResolutionButton::create(&gp, "button.png", Box(32, 16, 64, 32), true, 800, 600);
  // res3->position.x = 860;
  // res3->position.y = 200;
  // res3->scale(3);
  // res3->setText("800x600", 30);
  // res3->setVisible(false);

  gp.execute();

  return EXIT_SUCCESS;
}
