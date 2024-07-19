#ifndef BULLET_HPP
#define BULLET_HPP

#include <Engine.hpp>
#include <Input.hpp>
#include <Mouse.hpp>
#include <Engine/objects.hpp>
#include <SFML/Graphics.hpp>

namespace Game {
    class Bullet : public Object2D {
        public:
            virtual string type();
            void step();
            using Object2D::collision;
            using Object2D::draw;
            using Object2D::destroy;
            virtual ~Bullet();

            float direction;
            float speed;
        protected:
            using Object2D::Object2D;
    };
};


#endif