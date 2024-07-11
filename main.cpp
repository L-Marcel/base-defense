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
        string type() {
            return "Player";
        };
};
 
int main() {
    GameProcess gp;

    Player player("assets/player.png", Box(12, 14, 24, 28));
    player.scale(4);
    player.animate(8, 1, false);
    
    player.step = [&player](GameProcess* gp) {
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

        if(player.animationFinished && Mouse::left()) {
            if(player.firstAttack) player.animate(8, 0, false);
            else player.animate(8, 1, false);

            player.firstAttack = !player.firstAttack;
        };
    };

    gp.addObject(&player);
    gp.execute();

    return EXIT_SUCCESS;
}