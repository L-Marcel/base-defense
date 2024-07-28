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

  //Example* example_t = Example::create(&gp, "ball.png", Box(8, 8, 16, 16));
  //example_t->position = Vector<float>(200, 300);
  //example_t->setRectangle(100, 50);
  //example_t->scale(2);

  Player* player = Player::create(&gp);
  player->scale(2);

  ResumeButton* resume = ResumeButton::create(&gp, "button_ex.png", Box(16, 16, 32, 32), true);
  resume->position.x = 100;
  resume->position.y = 100;
  
  ResolutionButton* res1 = ResolutionButton::create(&gp, "button_ex.png", Box(16, 16, 32, 32), true, 1280, 720);
  res1->position.x = 100;
  res1->position.y = 200;
  res1->scale(2);
  res1->setVisible(false);

  ResolutionButton* res2 = ResolutionButton::create(&gp, "button_ex.png", Box(16, 16, 32, 32), true, 1024, 576);
  res2->position.x = 200;
  res2->position.y = 200;
  res2->scale(2);
  res2->setVisible(false);

  ResolutionButton* res3 = ResolutionButton::create(&gp, "button_ex.png", Box(16, 16, 32, 32), true, 800, 600);
  res3->position.x = 300;
  res3->position.y = 200;
  res3->scale(2);
  res3->setVisible(false);

  BridgeButton* resButton = BridgeButton::create(&gp, "button_ex.png", Box(16, 16, 32, 32), true, "ResOpt");
  resButton->position.x = 200;
  resButton->position.y = 100;
  resButton->addType(res1->subType());

  BridgeButton* resExitButton = BridgeButton::create(&gp, "button_exit_ex.png", Box(16, 16, 32, 32), true, "BackOpt");
  resExitButton->position.x = 300;
  resExitButton->position.y = 100;
  resExitButton->addType(resume->subType());
  resExitButton->addType(resButton->subType());
  resExitButton->setVisible(false);

  resButton->addType(resExitButton->subType());

  Base::create(&gp);

  // Essa colisão poderia ser criada no Player::create, 
  // mas aqui temos apenas um exemplo
  Collision::create(&gp, player, "Example");
  Collision::create(&gp, example_two, "Bullet");
  
  gp.execute();

  return EXIT_SUCCESS;
}
