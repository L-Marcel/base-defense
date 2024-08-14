#include <Engine.hpp>

namespace Game{
	void Collision::destroy() {
		delete this;
	};

	void Collision::step() {
		for(unsigned int i = 0; i < GameProcess::length(); i++){
			Object* candidate = GameProcess::get(i);
			if(candidate->type() == this->collider && this->object != candidate) {
				Object2D* collider = (Object2D*) candidate;
				if(
					has_circles_collision(this->object, collider) ||
					has_circle_and_rectangle_collision(this->object, collider) ||
					has_rectangles_collision(this->object, collider)
				) {
					this->object->colliders.add(collider);
				};
			};
		};
	};

	bool Collision::has_circles_collision(Object2D* first, Object2D* second) {
		if(first == nullptr || second == nullptr) return false;
    if(!first->has_circle || !second->has_circle) return false;
		float dist = Math::pointDistance(first->circle.getPosition(), second->circle.getPosition());
		return dist < (first->circle.getRadius() + second->circle.getRadius());
	};

	bool Collision::has_circle_and_rectangle_collision(Object2D* first, Object2D* second) {
		if(first == nullptr || second == nullptr) return false;
    if(!first->has_circle || !second->has_rectangle) {
			if(!second->has_circle || !first->has_rectangle) {
				return false;
			};

			Object2D* _second = second;
			second = first;
			first = _second;
		};

		float cx = first->circle.getPosition().x;
		float cy = first->circle.getPosition().y;
		float rx = second->rectangle.getPosition().x;
		float ry = second->rectangle.getPosition().y;

		float xx = abs(first->circle.getPosition().x - second->rectangle.getPosition().x);
		float yy = abs(first->circle.getPosition().y - second->rectangle.getPosition().y);

		float dist = 0.0;
		float rect_height = second->rectangle.getSize().y;
		float rect_width = second->rectangle.getSize().x;

		unsigned short int rect_region = 1;

		if(
			((cx > rx-rect_width/2 && cx < rx+rect_width/2) && cy > ry+rect_height/2) ||
			((cx > rx-rect_width/2 && cx < rx+rect_width/2) && cy < ry-rect_height/2)
		) {
			rect_region = 1;
			dist = yy;
		};

		if(
			((cy > ry-rect_height/2 && cy < ry+rect_height/2) && cx > rx+rect_width/2) ||
			((cy > ry-rect_height/2 && cy < ry+rect_height/2) && cx < rx-rect_width/2)
		) {
			rect_region = 2;
			dist = xx;
		};

		if(
			(cx < rx-rect_width/2 && cy < ry-rect_height/2) ||
			(cx > rx+rect_width/2 && cy < ry-rect_height/2) ||
			(cx < rx-rect_width/2 && cy > ry+rect_height/2) ||
			(cx > rx+rect_width/2 && cy > ry+rect_height/2)
		){
			if(abs(xx - rect_width/2) < 17 && abs(xx - rect_width/2) > 4){
				rect_region = 3;
				dist = (sqrt((xx*xx) + (yy*yy)))+6;
			} else if(abs(yy - rect_height/2) < 10){
				rect_region = 3;
				dist = (sqrt((xx*xx) + (yy*yy)))+2;
			} else if(abs(xx - rect_width/2) <= 4){
				rect_region = 3;
				dist = (sqrt((xx*xx) + (yy*yy)))+10;
			} else{
				rect_region = 3;
				dist = sqrt((xx*xx) + (yy*yy));
			};
		};

		switch(rect_region) {
			case 1:
				return dist < first->circle.getRadius() + rect_height/2;
			case 2:
				return dist < first->circle.getRadius() + rect_width/2;
			case 3:
				return dist < first->circle.getRadius() + Math::pointDistance(Point(rect_height/2, rect_width/2));
			default:
				return false;
		};
	};

	bool Collision::has_rectangles_collision(Object2D* first, Object2D* second) {
		if(first == nullptr || second == nullptr) return false;
    if(!first->has_rectangle || !second->has_rectangle) return false;

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

		unsigned short int rect_region = 1;

		if(
			((x1 >= x2-w2/2 && x1 <= x2+w2/2) && y1 >= y2+h2/2) ||
			((x1 >= x2-w2/2 && x1 <= x2+w2/2) && y1 <= y2-h2/2)
		) {
			rect_region = 1;
			dist = yy;
		};

		if(
			((y1 >= y2-h2/2 && y1 <= y2+h2/2) && x1 >= x2+w2/2) ||
			((y1 >= y2-h2/2 && y1 <= y2+h2/2) && x1 <= x2-w2/2)
		) {
			rect_region = 2;
			dist = xx;
		};

		if(
			(x1 < x2-w2/2 && y1 < y2-h2/2) ||
			(x1 > x2+w2/2 && y1 < y2-h2/2) ||
			(x1 < x2-w2/2 && y1 > y2+h2/2) ||
			(x1 > x2+w2/2 && y1 > y2+h2/2)
		) {
			rect_region = 3;
		};

		switch(rect_region){
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

  Collision::Collision() {};

	Collision* Collision::create(Object2D* object, string collider) {
		Collision* collision = new Collision();
		collision->object = object;
		collision->collider = collider;
		object->collisions.add(collision);
		return collision;
	};
};