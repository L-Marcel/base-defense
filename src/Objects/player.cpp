#include <Objects/player.hpp>

namespace Game {
    Vector<float> click;
    bool iniPos = false;
//     void Player::step(GameProcess* gp) {
        
//         //APENAS PARA DEBUG.
//         /*
//         if(this->hasCCol == true){
//             gp->window.draw(this->circ_collision);
//         } else if(this->hasRCol == true){
//             gp->window.draw(this->rect_collision);
//         }
//         */
        
//         //OUTRO DEBUG (porém dá pra brincar mais)
//         Collision* Test = gp->getCollisionByType(this->type(), "Example");
//         if(Test->isColliding() == true){
//             cout << "Deu Certooo" << endl;
//         } else{
//             cout << "Parou" << endl;
//         }

//         if(iniPos == false){
//             click = this->getPos();
//             iniPos = true;
//         }

//         if(Mouse::right()){
//             click = Mouse::position(&gp->window);
//         }

//         if((click.x != this->x || click.y != this->y)){

//             if(click.x >= gp->getWindowWidth()) click.x = gp->getWindowWidth();
//             else if(click.x <= 0) click.x = 0;

//             if(click.y >= gp->getWindowHeight()) click.y = gp->getWindowHeight();
//             else if(click.y <= 0) click.y = 0;

//             float xx = 0.0;
//             float yy = 0.0;
//             float speed = 5.0;

//             xx = abs(this->x - click.x);
//             yy = abs(this->y - click.y);

//             if(xx > yy){
//                 float proporcao = yy/xx;
//                 xx = 1;
//                 yy = proporcao;
//             } else if(xx < yy){
//                 float proporcao = xx/yy;
//                 xx = proporcao;
//                 yy = 1;
//             } else{
//                 xx = 1;
//                 yy = 1;
//             }

//             if(this->x < click.x) this->x+=xx*speed;
//             if(this->y < click.y) this->y+=yy*speed;
//             if(this->x > click.x) this->x-=xx*speed;
//             if(this->y > click.y) this->y-=yy*speed;
//         }
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

        this->position+=movement;

        Vector<float> pos = Mouse::position(&gp->window);
        this->rotation = Math::pointDirection(pos.x - this->position.x, pos.y - this->position.y) - 90.0;

        if(this->animationFinished && Mouse::left()) {
            this->shot_sound.play();

            if(this->firstAttack) this->animate(8, 0, false);
            else this->animate(8, 1, false);

            this->firstAttack = !this->firstAttack;
        };
    };

    Player* Player::create(GameProcess* gp, string spriteSheet, Box box) {
        Player* instance = new Player(spriteSheet, box);
        instance->_list = &gp->objects;
        gp->objects.add(instance);
        return instance;
    };

    Player::~Player() {};
};