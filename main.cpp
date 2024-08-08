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
  Base::create();
  Player::create();

  gp.execute();

  return EXIT_SUCCESS;
};
