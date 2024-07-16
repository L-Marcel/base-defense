#include <Engine.hpp>
#include <Input.hpp>
#include <Mouse.hpp>

namespace Game {
    class Player : public Object {
        public:
            void step(GameProcess* gp);
            string type();
            void draw(GameProcess* gp);

            short unsigned int life = 10;
            using Object::Object;
            bool firstAttack = true;
    };
};