#include <Engine.hpp>
#include <Input.hpp>
#include <Mouse.hpp>

namespace Game {
    class Player : public Object {
        public:
            void step(GameProcess* gp);
            string type();
            ~Player();
            using Object::Object;
            short unsigned int life = 10;
            bool firstAttack = true;
    };
};