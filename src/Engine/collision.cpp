#include <Engine.hpp>

namespace Game{
    Collision::Collision() {};

    void Collision::destroy() {
        if(this->object) {
            this->object->collisions.remove(this);
        };
        
        delete this;
    };
    
    Collision* Collision::create(GameProcess* gp, Object2D* object, string collider) {
        Collision* collision = new Collision();
        collision->object = object;
        collision->collider = collider;
        collision->gp = gp;
        object->collisions.add(collision);
        return collision;
    };

    void Collision::step() {
        this->object->colliders.clear();

        for(unsigned int i = 0; i < this->gp->objects.length(); i++){
            Object* candidate = this->gp->objects.get(i);
            if(candidate->type() == this->collider && this->object != candidate) {
                Object2D* collider = (Object2D*) candidate;
                if(
                    CCcollision(this->object, collider) || 
                    CRcollision(this->object, collider) ||
                    CRcollision(collider, this->object) || 
                    RRcollision(this->object, collider)
                ) {
                    this->object->colliders.add(collider);
                };
            };
        };
    };

    bool Collision::CCcollision(Object2D* first, Object2D* second) {
        if(!first->hasCircle || !second->hasCircle) return false;
        float xx = first->circle.getPosition().x - second->circle.getPosition().x;
        float yy = first->circle.getPosition().y - second->circle.getPosition().y;
        float dist = sqrt((xx*xx) + (yy*yy));
        return dist < (first->circle.getRadius() + second->circle.getRadius());
    };

    bool Collision::CRcollision(Object2D* objCirc, Object2D* objRect) {
        if(!objCirc->hasCircle || !objRect->hasRectangle) return false;

        float Cx = objCirc->circle.getPosition().x;
        float Cy = objCirc->circle.getPosition().y;
        float Rx = objRect->rectangle.getPosition().x;
        float Ry = objRect->rectangle.getPosition().y;
        
        float xx = abs(objCirc->circle.getPosition().x - objRect->rectangle.getPosition().x);   
        float yy = abs(objCirc->circle.getPosition().y - objRect->rectangle.getPosition().y);

        float dist;
        float rectHeight = objRect->rectangle.getSize().y;
        float rectWidth = objRect->rectangle.getSize().x;

        if(((Cx > Rx-rectWidth/2 && Cx < Rx+rectWidth/2) && Cy > Ry+rectHeight/2) || ((Cx > Rx-rectWidth/2 && Cx < Rx+rectWidth/2) && Cy < Ry-rectHeight/2)){
            rectRegion = 1;
            dist = yy;
        };
        
        if(((Cy > Ry-rectHeight/2 && Cy < Ry+rectHeight/2) && Cx > Rx+rectWidth/2) || ((Cy > Ry-rectHeight/2 && Cy < Ry+rectHeight/2) && Cx < Rx-rectWidth/2)){
            rectRegion = 2;
            dist = xx;
        };

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
            };
        };

        switch(rectRegion){
            case 1:
                return dist < objCirc->circle.getRadius() + rectHeight/2;
            case 2:
                return dist < objCirc->circle.getRadius() + rectWidth/2;
            case 3:
                return dist < objCirc->circle.getRadius() + sqrt((rectHeight/2 * rectHeight/2) + (rectWidth/2 * rectWidth/2));
            default:
                return false;
        };
    };

    bool Collision::RRcollision(Object2D* first, Object2D* second) {
        if(!first->hasCircle || !second->hasCircle) return false;

        float R1x = first->rectangle.getPosition().x;
        float R1y = first->rectangle.getPosition().y;
        float R2x = second->rectangle.getPosition().x;
        float R2y = second->rectangle.getPosition().y;
        
        float xx = abs(R2x - R1x);
        float yy = abs(R1y - R2y);

        float dist;
        float R1Height = first->rectangle.getSize().y;
        float R1Width = first->rectangle.getSize().x;
        float R2Height = second->rectangle.getSize().y;
        float R2Width = second->rectangle.getSize().x;

        if(((R1x >= R2x-R2Width/2 && R1x <= R2x+R2Width/2) && R1y >= R2y+R2Height/2) || ((R1x >= R2x-R2Width/2 && R1x <= R2x+R2Width/2) && R1y <= R2y-R2Height/2)){
            rectRegion = 1;
            dist = yy;
        };

        if(((R1y >= R2y-R2Height/2 && R1y <= R2y+R2Height/2) && R1x >= R2x+R2Width/2) || ((R1y >= R2y-R2Height/2 && R1y <= R2y+R2Height/2) && R1x <= R2x-R2Width/2)){
            rectRegion = 2;
            dist = xx;
        };

        if((R1x < R2x-R2Width/2 && R1y < R2y-R2Height/2) || (R1x > R2x+R2Width/2 && R1y < R2y-R2Height/2) || (R1x < R2x-R2Width/2 && R1y > R2y+R2Height/2) || (R1x > R2x+R2Width/2 && R1y > R2y+R2Height/2)){
            rectRegion = 3;
        };

        switch(rectRegion){
            case 1:
                return dist < ((R1Height/2) + (R2Height/2));
            case 2:
                return dist < (R1Width/2 + R2Width/2);
            case 3:
                return xx < (R1Width/2 + R2Width/2) && yy < (R1Height/2 + R2Height/2);
            default:
                return false;
        };
    };
};