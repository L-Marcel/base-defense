#include <Engine.hpp>

namespace Game{
    void Collision::step(GameProcess *gp){
        if(this->type1 == "none" || this->type2 == "none") return;

        Object* temp1;
        Object* temp2;

        unsigned int size = gp->getOListSize();
        for(unsigned int i = 0; i < size; i++){
            if(gp->getObject(i)->type() == type1){
                temp1 = gp->getObject(i);
                for(unsigned int j = 0; j < size; j++){
                    if(gp->getObject(i) == gp->getObject(j)) continue;
                    if(gp->getObject(j)->type() == type2) temp2 = gp->getObject(j);
                }
            }
        }
        
        if(temp1->hasCCol == true && temp2->hasCCol == temp1->hasCCol){
            CCcollision(temp1, temp2);
        } else if((temp1->hasCCol == true || temp2->hasCCol == true) && (temp1->hasRCol == true || temp2->hasRCol == true)){
            CRcollision(temp1, temp2);
        } else if(temp1->hasRCol == true && temp2->hasRCol == temp1->hasRCol){
            RRcollision(temp1, temp2);
        }
    }

    void Collision::collision_between(string obj_type1, string obj_type2){
        this->type1 = obj_type1;
        this->type2 = obj_type2;
    }

    string Collision::getType1(){
        return this->type1;
    }

    string Collision::getType2(){
        return this->type2;
    }

    void Collision::CCcollision(Object* obj1, Object* obj2){
        float xx = obj1->circ_collision.getPosition().x - obj2->circ_collision.getPosition().x;
        float yy = obj1->circ_collision.getPosition().y - obj2->circ_collision.getPosition().y;
        float dist = sqrt((xx*xx) + (yy*yy));
        if(dist < (obj1->circ_collision.getRadius() + obj2->circ_collision.getRadius())){
            Colliding();
        } else{
            NoColliding();
        }
    }

    void Collision::CRcollision(Object* objCirc, Object* objRect){
        float Cx = objCirc->circ_collision.getPosition().x;
        float Cy = objCirc->circ_collision.getPosition().y;
        float Rx = objRect->rect_collision.getPosition().x;
        float Ry = objRect->rect_collision.getPosition().y;
        
        float xx = abs(objCirc->circ_collision.getPosition().x - objRect->rect_collision.getPosition().x);   
        float yy = abs(objCirc->circ_collision.getPosition().y - objRect->rect_collision.getPosition().y);

        float dist;
        float rectHeight = objRect->rect_collision.getSize().y;
        float rectWidth = objRect->rect_collision.getSize().x;
        if(((Cx > Rx-rectWidth/2 && Cx < Rx+rectWidth/2) && Cy > Ry+rectHeight/2) || ((Cx > Rx-rectWidth/2 && Cx < Rx+rectWidth/2) && Cy < Ry-rectHeight/2)){
            rectRegion = 1;
            dist = yy;
        }
        if(((Cy > Ry-rectHeight/2 && Cy < Ry+rectHeight/2) && Cx > Rx+rectWidth/2) || ((Cy > Ry-rectHeight/2 && Cy < Ry+rectHeight/2) && Cx < Rx-rectWidth/2)){
            rectRegion = 2;
            dist = xx;
        }
        if((Cx < Rx-rectWidth/2 && Cy < Ry-rectHeight/2) || (Cx > Rx+rectWidth/2 && Cy < Ry-rectHeight/2) || (Cx < Rx-rectWidth/2 && Cy > Ry+rectHeight/2) || (Cx > Rx+rectWidth/2 && Cy > Ry+rectHeight/2)){
            if(abs(xx - rectWidth/2) < 17 && abs(xx - rectWidth/2) > 4){
                rectRegion = 3;
                dist = (sqrt((xx*xx) + (yy*yy)))+6;
            } else if(abs(yy - rectHeight/2) < 10){
                rectRegion = 3;
                dist = (sqrt((xx*xx) + (yy*yy)))+2;
            } else if(abs(xx - rectWidth/2) <= 4){
                rectRegion = 3;
                dist = (sqrt((xx*xx) + (yy*yy)))+10;
            } else{
                rectRegion = 3;
                dist = sqrt((xx*xx) + (yy*yy));
            }
        }
        
        switch(rectRegion){
            case 1:
                if(dist < objCirc->circ_collision.getRadius() + rectHeight/2) Colliding();
                else NoColliding();
                break;
            case 2:
                if(dist < objCirc->circ_collision.getRadius() + rectWidth/2) Colliding();
                else NoColliding();
                break;
            case 3:
                if(dist < objCirc->circ_collision.getRadius() + sqrt((rectHeight/2 * rectHeight/2) + (rectWidth/2 * rectWidth/2))) Colliding();
                else NoColliding();
                break;
            default:
                break;
        }
    }

    void Collision::RRcollision(Object* obj1, Object* obj2){
        float R1x = obj1->rect_collision.getPosition().x;
        float R1y = obj1->rect_collision.getPosition().y;
        float R2x = obj2->rect_collision.getPosition().x;
        float R2y = obj2->rect_collision.getPosition().y;
        
        float xx = abs(R2x - R1x);
        float yy = abs(R1y - R2y);

        float dist;
        float R1Height = obj1->rect_collision.getSize().y;
        float R1Width = obj1->rect_collision.getSize().x;
        float R2Height = obj2->rect_collision.getSize().y;
        float R2Width = obj2->rect_collision.getSize().x;
        if(((R1x >= R2x-R2Width/2 && R1x <= R2x+R2Width/2) && R1y >= R2y+R2Height/2) || ((R1x >= R2x-R2Width/2 && R1x <= R2x+R2Width/2) && R1y <= R2y-R2Height/2)){
            rectRegion = 1;
            dist = yy;
        }
        if(((R1y >= R2y-R2Height/2 && R1y <= R2y+R2Height/2) && R1x >= R2x+R2Width/2) || ((R1y >= R2y-R2Height/2 && R1y <= R2y+R2Height/2) && R1x <= R2x-R2Width/2)){
            rectRegion = 2;
            dist = xx;
        }
        if((R1x < R2x-R2Width/2 && R1y < R2y-R2Height/2) || (R1x > R2x+R2Width/2 && R1y < R2y-R2Height/2) || (R1x < R2x-R2Width/2 && R1y > R2y+R2Height/2) || (R1x > R2x+R2Width/2 && R1y > R2y+R2Height/2)){
            rectRegion = 3;
        }

        switch(rectRegion){
            case 1:
                if(dist < ((R1Height/2) + (R2Height/2))) Colliding();
                else NoColliding();
                break;
            case 2:
                if(dist < (R1Width/2 + R2Width/2)) Colliding();
                else NoColliding();
                break;
            case 3:
                if(xx < (R1Width/2 + R2Width/2) && yy < (R1Height/2 + R2Height/2)) Colliding();
                else NoColliding();
            default:
                break;
        }
    }

    void Collision::Colliding(){
        this->isCol = true;
    }

    void Collision::NoColliding(){
        this->isCol = false;
    }

    bool Collision::isColliding(){
        return this->isCol;
    }
};