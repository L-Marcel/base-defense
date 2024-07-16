#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
    GameProcess gp;

    Player player("assets/player.png", Box(12, 14, 24, 28));
    player.scale(4);
    player.animate(8, 1, false);    

    Text texto;
    texto.setText("Texto Exemplo");
    texto.setTextPosition(300.f,250.f);
    
    gp.addObject(&player);
    gp.addObject(&texto);
    gp.execute();

    return EXIT_SUCCESS;
}