#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
  GameProcess gp;
  
  Music music("default.ogg");
  music.setVolume(30);
  music.play();

  Text::create(&gp, Vector<float>(300.f, 250.f), "Exemplo");

  Example* example = Example::create(&gp, "ball.png", Box(8, 8, 16, 16));
  example->setCircle(36);
  example->scale(4);
  example->position = Vector<float>(500.f, 400.f);

  Example* example_two = Example::create(&gp, "ball.png", Box(8, 8, 16, 16));
  example_two->setRectangle(60, 30);
  example_two->scale(4);
  example_two->position = Vector<float>(100.f, 500.f);

  Player* player = Player::create(&gp);
  player->scale(4);
  player->animate(8, 1, false);

  Enemy* enemy = Enemy::create(&gp, player, example_two);
  enemy->scale(2);
  enemy->animate(8, 0, false);
  
  // Essa colisão poderia ser criada no Player::create, 
  // mas aqui temos apenas um exemplo
  Collision::create(&gp, player, "Example");
  //Collision::create(&gp, example_two, "Bullet");
  Collision::create(&gp, enemy, "Bullet");
  Collision::create(&gp, player, "Bullet");
  
  gp.execute();

  return EXIT_SUCCESS;
}