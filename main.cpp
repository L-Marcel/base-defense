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

  Text* text = Text::create(&gp, Vector<float>(584, 120), "Exemplo");
  text->depth = 20;

  Player* player = Player::create(&gp);
  player->scale(2);

  Base::create(&gp);
  
  gp.execute();

  return EXIT_SUCCESS;
}