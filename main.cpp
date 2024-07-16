#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
    GameProcess gp;

    Vector<float> mouse_pos = Mouse::position();

    Player player("assets/player.png", Box(12, 14, 24, 28));
    player.scale(4);
    player.animate(8, 1, false);
    player.x = gp.getWindowWidth()/2;
    player.y = gp.getWindowHeight()/2;
    /*
    Example example("assets/ball.png", Box(8, 0, 8, 8));
    example.scale(4);
    example.x = gp.getWindowWidth()/2;
    example.y = gp.getWindowHeight()/2;
    */    

    gp.addObject(&player);
    //gp.addObject(&example);
    gp.execute();

    return EXIT_SUCCESS;
}