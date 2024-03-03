#include <iostream>
#include "include/Engine.hpp"
#include "include/Input.hpp"
#include "include/Mouse.hpp"

using namespace lm;
using namespace sf;

class Player : public Object {
    public:
        short unsigned int life = 10;
        using Object::Object;
};
 
int main() {
    GameProcess gp;
    Room room("Menu", 800, 600);
    Player player("assets/player.png", Box(12, 14, 24, 28));
    player.scale(4);
    player.animate(8, 1, false);
    
    player.step([](Object* self, Room* room, GameProcess* gp){
        Coord movement = Input::keyboard(
            Keyboard::A,
            Keyboard::W,
            Keyboard::D,
            Keyboard::S,
            2
        );
        
        self->x+=movement.x;
        self->y+=movement.y;
        Coord pos = lm::Mouse::position();
        self->sprite->rotate(pointDirection(pos.x - self->x, pos.y - self->y));
    });

    room.addObject(&player);

    gp.addRoom(&room);
    gp.step();

    return EXIT_SUCCESS;
}