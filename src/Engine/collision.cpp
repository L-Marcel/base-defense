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
        float dist = Math::pointDistance(first->circle.getPosition(), second->circle.getPosition());
        return dist < (first->circle.getRadius() + second->circle.getRadius());
    };

    bool Collision::CRcollision(Object2D* first, Object2D* second) {
        if(!first->hasCircle || !second->hasRectangle) return false;

        float Cx = first->circle.getPosition().x;
        float Cy = first->circle.getPosition().y;
        float Rx = second->rectangle.getPosition().x;
        float Ry = second->rectangle.getPosition().y;
        
        float xx = abs(first->circle.getPosition().x - second->rectangle.getPosition().x);   
        float yy = abs(first->circle.getPosition().y - second->rectangle.getPosition().y);

        float dist;
        float rectHeight = second->rectangle.getSize().y;
        float rectWidth = second->rectangle.getSize().x;

        unsigned short int rectRegion = 1;

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
                return dist < first->circle.getRadius() + rectHeight/2;
            case 2:
                return dist < first->circle.getRadius() + rectWidth/2;
            case 3:
                return dist < first->circle.getRadius() + sqrt((rectHeight/2 * rectHeight/2) + (rectWidth/2 * rectWidth/2));
            default:
                return false;
        };
    };

    bool Collision::RRcollision(Object2D* first, Object2D* second) {
        if(!first->hasRectangle || !second->hasRectangle) return false;

        float x1 = first->rectangle.getPosition().x;
        float y1 = first->rectangle.getPosition().y;
        float x2 = second->rectangle.getPosition().x;
        float y2 = second->rectangle.getPosition().y;
        
        float xx = abs(x2 - x1);
        float yy = abs(y1 - y2);

        float dist;

        float h1 = first->rectangle.getSize().y;
        float w1 = first->rectangle.getSize().x;
        float h2 = second->rectangle.getSize().y;
        float w2 = second->rectangle.getSize().x;

        unsigned short int rectRegion = 1;

        if(
            ((x1 >= x2-w2/2 && x1 <= x2+w2/2) && y1 >= y2+h2/2) || 
            ((x1 >= x2-w2/2 && x1 <= x2+w2/2) && y1 <= y2-h2/2)
        ) {
            rectRegion = 1;
            dist = yy;
        };

        if(
            ((y1 >= y2-h2/2 && y1 <= y2+h2/2) && x1 >= x2+w2/2) || 
            ((y1 >= y2-h2/2 && y1 <= y2+h2/2) && x1 <= x2-w2/2)
        ) {
            rectRegion = 2;
            dist = xx;
        };

        if(
            (x1 < x2-w2/2 && y1 < y2-h2/2) || 
            (x1 > x2+w2/2 && y1 < y2-h2/2) || 
            (x1 < x2-w2/2 && y1 > y2+h2/2) || 
            (x1 > x2+w2/2 && y1 > y2+h2/2)
        ) {
            rectRegion = 3;
        };

        switch(rectRegion){
            case 1:
                return dist < (h1 + h2)/2;
            case 2:
                return dist < (w1 + w2)/2;
            case 3:
                return xx < (w1 + w2)/2 && yy < (h1 + h2)/2;
            default:
                return false;
        };
    };
};