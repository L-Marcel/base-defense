#include <Engine/base.hpp>
#include <cstring>
#include <functional>

namespace Game{
    class GameProcess;
    class Collision{
        private:
            string type1 = "none";
            string type2 = "none";
            bool isCol = false;
        public:
            unsigned short int rectRegion;

            void step(GameProcess *gp);

            void collision_between(string obj_type1, string obj_type2);

            string getType1();

            string getType2();

            void CCcollision(Object* obj1, Object* obj2);

            void CRcollision(Object* obj1, Object* obj2);

            void RRcollision(Object* obj1, Object* obj2);

            void Colliding();

            void NoColliding();

            bool isColliding();
            
    } typedef Collision;
};