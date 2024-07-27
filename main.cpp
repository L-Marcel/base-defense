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

  Example* example = Example::create(&gp, "ball.png", Box(8, 8, 16, 16));
  example->position = Vector<float>(500, 400);
  example->setCircle(36);
  example->scale(2);

  Example* example_two = Example::create(&gp, "ball.png", Box(8, 8, 16, 16));
  example_two->position = Vector<float>(200, 300);
  example_two->setRectangle(100, 50);
  example_two->scale(2);

  Player* player = Player::create(&gp);
  player->scale(2);

  Base::create(&gp);

  ResumeButton* resumeButton = ResumeButton::create(&gp, "button_ex.png", Box(16, 16, 32, 32), true);
  resumeButton->position.x = 100;
  resumeButton->position.y = 100;
  resumeButton->scale(2);

  ResolutionButton* resolButton = ResolutionButton::create(&gp, "button_ex.png", Box(16, 16, 32, 32), true, 1024, 576);
  resolButton->position.x = 200;
  resolButton->position.y = 100;
  resolButton->scale(2);

  // Essa colisão poderia ser criada no Player::create, 
  // mas aqui temos apenas um exemplo
  Collision::create(&gp, player, "Example");
  Collision::create(&gp, example_two, "Bullet");
  
  gp.execute();

  return EXIT_SUCCESS;
}
