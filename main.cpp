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
    example_two->setRectangle(100, 50);
    example_two->scale(4);
    example_two->position = Vector<float>(200.f, 300.f);

    Player* player = Player::create(&gp, "player.png", Box(12, 14, 24, 28));

    player->scale(4);
    player->animate(8, 1, false);
    
    // Essa colisão poderia ser criada no Player::create, 
    // mas aqui temos apenas um exemplo
    Collision::create(&gp, player, "Example");
    
    gp.execute();

    return EXIT_SUCCESS;
}