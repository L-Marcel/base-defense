#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
    GameProcess gp;

    Player player("assets/player.png", Box(12, 14, 24, 28));
    player.scale(4);
    player.animate(8, 1, false);

    gp.addObject(&player);
    gp.execute();

    return EXIT_SUCCESS;
}