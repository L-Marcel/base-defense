#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
    GameProcess gp;

    Player player("assets/player.png", Box(12, 14, 24, 28));
    player.scale(4);
    player.animate(8, 1, false);
    player.x = 400;
    player.y = 200;

    gp.addObject(&player);
    gp.execute();

    return EXIT_SUCCESS;
}