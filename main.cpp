#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
  GameProcess gp;
  
  Music music("default.ogg");
  music.setVolume(30);
  music.play();

  Background::create(&gp);
  Limit::create(&gp);

  Player* player = Player::create(&gp);
  player->scale(2);
  
  Base* base = Base::create(&gp);
  
  Enemy* enemy = Enemy::create(&gp, player, base);
  enemy->scale(2);
  enemy->animate(8, 4, 0, false);
  Collision::create(&gp, enemy, "Bullet");

  Text* text = Text::create(&gp, Vector<float>(584, 120), "Exemplo");
  text->depth = 20;
  
  gp.execute();

  return EXIT_SUCCESS;
}