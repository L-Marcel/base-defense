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

            /// @brief Função step para verificar as colisões
            /// @param gp GameProcess
            void step(GameProcess *gp);

            /// @brief Função para definir os tipos da colisão (objetos que irão colidir)
            /// @param obj_type1 tipo do primeiro objeto
            /// @param obj_type2 tipo do segundo objeto
            void collision_between(string obj_type1, string obj_type2);

            /// @brief Retorna o type1 da classe
            /// @return type1 da classe
            string getType1();

            /// @brief Retorna o type2 da classe
            /// @return type2 da classe
            string getType2();

            /// @brief Checa a colisão entre dois círculos (duas colisões circulares)
            /// @param obj1 objeto 1 (a função collision_between já dá esses objetos por ter acesso aos tipos da classe)
            /// @param obj2 objeto 2 (a função collision_between já dá esses objetos por ter acesso aos tipos da classe)
            void CCcollision(Object* obj1, Object* obj2);

            /// @brief Checa a colisão entre um círculo e um retângulo (uma colisão circular e uma colisão retangular)
            /// @param obj1 objeto 1 (a função collision_between já dá esses objetos por ter acesso aos tipos da classe)
            /// @param obj2 objeto 2 (a função collision_between já dá esses objetos por ter acesso aos tipos da classe)
            void CRcollision(Object* obj1, Object* obj2);

            /// @brief Checa a colisão entre dois retângulos (duas colisões retangulares)
            /// @param obj1 objeto 1 (a função collision_between já dá esses objetos por ter acesso aos tipos da classe)
            /// @param obj2 objeto 2 (a função collision_between já dá esses objetos por ter acesso aos tipos da classe)
            void RRcollision(Object* obj1, Object* obj2);

            /// @brief isCol recebe true (sinal que está colidindo)
            void Colliding();

            /// @brief isCol recebe false (sinal que NÃO está colidindo)
            void NoColliding();

            /// @brief Retorna se os objetos estão colidindo ou não
            /// @return isCol
            bool isColliding();
            
    } typedef Collision;
};