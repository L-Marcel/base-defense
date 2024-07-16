#include <Engine.hpp>
#include <Mouse.hpp>

namespace Game{
    class Example : public Object{
        public:
            void step(GameProcess* gp);
            string type();
            using Object::Object;
    };
};