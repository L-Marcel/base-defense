#include <Objects/player.hpp>

namespace Game {
    string Player::type() {
        return "Player";
    };
  
    void Player::step(GameProcess* gp) {
        Vector<float> movement = Input::keyboard(
            Keyboard::A,
            Keyboard::W,
            Keyboard::D,
            Keyboard::S,
            2
        );

        this->x+=movement.x;
        this->y+=movement.y;

        Vector<float> pos = Mouse::position(&gp->window);
        this->rotation = Math::pointDirection(pos.x - this->x, pos.y - this->y) - 90.0;

        if(this->animationFinished && Mouse::left()) {
            this->shot_sound.play();

            if(this->firstAttack) this->animate(8, 0, false);
            else this->animate(8, 1, false);

            this->firstAttack = !this->firstAttack;
        };
    };
    
    void Player::draw(GameProcess* gp) {
        gp->animateObject(this);
        gp->window.draw(*this->sprite);
    };
    
    Player* Player::create(GameProcess* gp, string spriteSheet, Box box) {
        Player* instance = new Player(spriteSheet, box);
        instance->_list = &gp->objects;
        gp->objects.add(instance);
        return instance;
    };

    Player::~Player() {};
};