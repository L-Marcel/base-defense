#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
  GameProcess gp;
  
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
  enemy->animate(8, 4, 0, false);
  Collision::create(enemy, "Bullet");

  Text* text = Text::create(Point(572, 120), "Exemplo");
  text->depth = 20;
  
  gp.execute();

  return EXIT_SUCCESS;
}