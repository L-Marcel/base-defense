#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
  GameProcess gp;
  GameProcess::setResolution(R1280x720);

  Background::create();
  Limit::create();
  Base::create();
  Player::create();
  Enemy::create();
  Interface::create();

  gp.execute();

  return EXIT_SUCCESS;
};
