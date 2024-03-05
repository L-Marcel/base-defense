#include <iostream>
#include "include/Engine.hpp"
#include "include/Input.hpp"
#include "include/Mouse.hpp"

using namespace lm;

class Player : public Object {
    public:
        short unsigned int life = 10;
        using Object::Object;
        bool firstAttack = true;
};
 
int main() {
    GameProcess gp;
    Room room("Room 01", 800, 600);

    Player player("assets/player.png", Box(12, 14, 24, 28));

    player.scale(4);
    player.animate(8, 1, false);
    
    player.step = [&player](Room* room, GameProcess* gp) {
        Vector<float> movement = Input::keyboard(
            Keyboard::A,
            Keyboard::W,
            Keyboard::D,
            Keyboard::S,
            2
        );
        
        player.x+=movement.x;
        player.y+=movement.y;
        
        Vector<float> pos = Mouse::position(&gp->window);
        player.rotation = pointDirection(pos.x - player.x, pos.y - player.y) - 90;

        if(player.animationFinished) {
            if(Mouse::left()) {
                if(player.firstAttack) player.animate(8, 0, false);
                else player.animate(8, 1, false);

                player.firstAttack = !player.firstAttack;
            };
        };
    };

    room.addObject(&player);

    gp.addRoom(&room);
    
    gp.execute();

    return EXIT_SUCCESS;
}