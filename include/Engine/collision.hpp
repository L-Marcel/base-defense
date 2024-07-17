#include <Engine/base.hpp>
#include <cstring>
#include <functional>

namespace Game{
    class GameProcess;
    class Collision{
        private:
            string type1 = "none";
            string type2 = "none";
        public:
            void step(GameProcess *gp);

            void meet(string obj_type1, string obj_type2);

            string getType1();

            string getType2();
    } typedef Collision;
};