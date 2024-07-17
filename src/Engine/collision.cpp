#include <Engine.hpp>

namespace Game{
    void Collision::step(GameProcess *gp){
        if(this->type1 == "none" || this->type2 == "none") return;
        unsigned int size = gp->getOListSize();
        for(unsigned int i = 0; i < size; i++){
            if(gp->getObject(i)->type() == type1){
                Object* temp1 = gp->getObject(i);
                for(unsigned int j = 0; j < size; j++){
                    if(gp->getObject(i) == gp->getObject(j)) continue;
                    if(gp->getObject(j)->type() == type2){
                        Object* temp2 = gp->getObject(j);
                        float xx = temp1->circ_collision.getPosition().x - temp2->circ_collision.getPosition().x;
                        float yy = temp1->circ_collision.getPosition().y - temp2->circ_collision.getPosition().y;
                        float dist = sqrt((xx*xx) + (yy*yy));
                        cout << dist << endl;
                        if(dist < (temp1->circ_collision.getRadius() + temp2->circ_collision.getRadius())){
                            cout << "Está colidindo" << endl;
                        } else{
                            cout << "Não está colidindo" << endl;
                        }
                    }
                }
            }
        }
    }

    void Collision::meet(string obj_type1, string obj_type2){
        this->type1 = obj_type1;
        this->type2 = obj_type2;
    }

    string Collision::getType1(){
        return this->type1;
    }

    string Collision::getType2(){
        return this->type2;
    }
};