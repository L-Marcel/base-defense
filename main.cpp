#include <iostream>
#include "include/lm.h"

using namespace lm;
using namespace sf;
 
int main() {
    GameProcess gp;

    Room room("Menu", 800, 600);
    Object player("assets/player.png", Box(0, 0, 48, 48));
    player.animate(8, 0);
    player.step([](Object* self, Room* room, GameProcess* gp){
        self->x+=0.1;
    });

    room.addObject(&player);

    gp.addRoom(&room);
    gp.step();

    return EXIT_SUCCESS;
}