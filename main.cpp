#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
    GameProcess gp;
    
    Music music("default.ogg");
    music.setVolume(30);
    music.play();

    Text::create(&gp, Vector<float>(300.f, 250.f), "Exemplo");
    Example::create(&gp, "ball.png", Box(8, 8, 16, 16));
    Player* player = Player::create(&gp, "player.png", Box(12, 14, 24, 28));

    player->scale(4);
    player->animate(8, 1, false);
    
    // Essa colisão poderia ser criada no Player::create, mas aqui
    // é apenas um exemplo
    Collision::create(&gp, player, "Example");
    
    gp.execute();

    return EXIT_SUCCESS;
}