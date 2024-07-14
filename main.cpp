#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
    GameProcess gp;

    Player* player = Player::create(&gp, "assets/player.png", Box(12, 14, 24, 28));
    player->scale(4);
    player->animate(8, 1, false);

    gp.execute();

    return EXIT_SUCCESS;
}