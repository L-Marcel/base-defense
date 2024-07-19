#ifndef BULLET_HPP
#define BULLET_HPP

#include <Engine.hpp>
#include <Input.hpp>
#include <Mouse.hpp>
#include <Engine/objects.hpp>
#include <SFML/Graphics.hpp>

namespace Game {
    class Bullet : public Object {
    public:
        void step(GameProcess* gp);
        string type();

        float direction;
        float speed;

        using Object::Object;

        void update();

        void setDirection(float direction);

        void setSpeed(float speed);

    
    };
};


#endif