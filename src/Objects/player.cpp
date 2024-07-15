#include <Objects/player.hpp>

namespace Game {

    Vector<float> click;
    void Player::step(GameProcess* gp) {

        if(Mouse::right()){
            click = Mouse::position(&gp->window);
        }

        if(click.x != this->x || click.y != this->y){
            float xx = 0.0;
            float yy = 0.0;
            float speed = 5.0;

            if(this->x > click.x){
                xx = this->x - click.x;
            } else if(this->x < click.x){
                xx = click.x - this->x;
            }

            if(this->y > click.y){
                yy = this->y - click.y;
            } else if(this->y < click.y){
                yy = click.y - this->y;
            }

            if(xx > yy){
                float proporcao = yy/xx;
                xx = 1;
                yy = proporcao;
            } else if(xx < yy){
                float proporcao = xx/yy;
                xx = proporcao;
                yy = 1;
            } else{
                xx = 1;
                yy = 1;
            }

            if(this->x < click.x) this->x+=xx*speed;
            if(this->y < click.y) this->y+=yy*speed;
            if(this->x > click.x) this->x-=xx*speed;
            if(this->y > click.y) this->y-=yy*speed;
        }

        Vector<float> pos = Mouse::position(&gp->window);
        this->rotation = Math::pointDirection(pos.x - this->x, pos.y - this->y) - 90.0;

        if(this->animationFinished && Mouse::left()) {
            if(this->firstAttack) this->animate(8, 0, false);
            else this->animate(8, 1, false);

            this->firstAttack = !this->firstAttack;
        };
    };

    string Player::type() {
        return "Player";
    };
};