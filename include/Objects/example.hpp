#include <Engine.hpp>
#include <Mouse.hpp>

namespace Game{
    class Example : public Object2D {
        public:
            virtual string type();
            using Object2D::step;
            using Object2D::collision;
            virtual void draw();
            using Object2D::destroy;
            virtual ~Example();

            /// @brief Cria uma instância do exemplo
            /// @param gp pornteiro do processo do jogo
            /// @param spriteSheet página de textura do sprite do exemplo
            /// @param box uma caixa que informa a origem do sprite e as dimesões dele
            static Example* create(GameProcess* gp, string spriteSheet, Box box);
        protected:
            using Object2D::Object2D;
    };
};