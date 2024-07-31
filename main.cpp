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
  Collision::create(enemy, "Bullet");

  Text* text = Text::create(Point(572, 120), "Exemplo");
  text->depth = 20;

  ResumeButton* resume = ResumeButton::create();

  // BridgeButton* optButton = BridgeButton::create(&gp, "button.png", Box(32, 16, 64, 32), true, "OptButton");
  // optButton->position.x = 640;
  // optButton->position.y = 300;
  // optButton->scale(4);
  // optButton->setText("Options", 40);

  // BridgeButton* optExitButton = BridgeButton::create(&gp, "back_button.png", Box(32, 16, 64, 32), true, "BackOpt");
  // optExitButton->position.x = 640;
  // optExitButton->position.y = 600;
  // optExitButton->scale(3);
  // optExitButton->addType(resume->subType());
  // optExitButton->addType(optButton->subType());
  // optExitButton->setText("Voltar", 30);
  // optExitButton->setVisible(false);

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

  // BridgeButton* resButton = BridgeButton::create(&gp, "res_button.png", Box(16, 16, 32, 32), true, "ResOpt");
  // resButton->position.x = 640;
  // resButton->position.y = 350;
  // resButton->scale(4);
  // resButton->addType(res1->subType());
  // resButton->setVisible(false);

  // BridgeButton* resExitButton = BridgeButton::create(&gp, "back_button.png", Box(32, 16, 64, 32), true, "BackRes");
  // resExitButton->position.x = 640;
  // resExitButton->position.y = 600;
  // resExitButton->scale(3);
  // resExitButton->setText("Voltar", 30);
  // resExitButton->addType(optExitButton->subType());
  // resExitButton->addType(resButton->subType());
  // resExitButton->setVisible(false);

  // resButton->addType(resExitButton->subType());

  // optButton->addType(resButton->subType());
  // optButton->addType(optExitButton->subType());
  ///

  PauseScreen::create();

  gp.execute();

  return EXIT_SUCCESS;
}
