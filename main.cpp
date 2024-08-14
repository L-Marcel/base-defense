#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
  GameProcess gp;
  GameProcess::setResolution(R1280x720);

  gp.execute();

  return EXIT_SUCCESS;
};
