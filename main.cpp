#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
    GameProcess gp;
    Music music("default.ogg");
    music.setVolume(30);
    music.play();

    Player* player = Player::create(&gp, "player.png", Box(12, 14, 24, 28));
    player->scale(4);
    player->animate(8, 1, false);
    
    gp.execute();

    return EXIT_SUCCESS;
}