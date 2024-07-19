#include <Objects.hpp>

namespace Game{
    class GameProcess;
    class Collision {
        protected:
            GameProcess* gp;
            Object2D* object;
            string collider = "none";

            /// @brief Cria uma instância do registro de uma colisão
            Collision();
        public:
            unsigned short int rectRegion;

            /// @brief Registra a colisão entre um objeto e um tipo de objeto
            /// @param gp o ponteiro do processo do jogo
            /// @param object o objeto que registrará a colisão
            /// @param collider o tipo de objeto que pode colidir com ele
            static Collision* create(GameProcess* gp, Object2D* object, string collider);

            /// @brief Remove a instância do jogo e libera ela da memória
            void destroy();

            /// @brief Função step para verificar as colisões
            /// @param gp GameProcess
            void step();

            /// @brief Checa a colisão entre dois círculos (duas colisões circulares)
            /// @param obj1 objeto 1 (a função collision_between já dá esses objetos por ter acesso aos tipos da classe)
            /// @param obj2 objeto 2 (a função collision_between já dá esses objetos por ter acesso aos tipos da classe)
            bool CCcollision(Object2D* obj1, Object2D* obj2);

            /// @brief Checa a colisão entre um círculo e um retângulo (uma colisão circular e uma colisão retangular)
            /// @param obj1 objeto 1 (a função collision_between já dá esses objetos por ter acesso aos tipos da classe)
            /// @param obj2 objeto 2 (a função collision_between já dá esses objetos por ter acesso aos tipos da classe)
            bool CRcollision(Object2D* obj1, Object2D* obj2);

            /// @brief Checa a colisão entre dois retângulos (duas colisões retangulares)
            /// @param obj1 objeto 1 (a função collision_between já dá esses objetos por ter acesso aos tipos da classe)
            /// @param obj2 objeto 2 (a função collision_between já dá esses objetos por ter acesso aos tipos da classe)
            bool RRcollision(Object2D* obj1, Object2D* obj2);
    };
};