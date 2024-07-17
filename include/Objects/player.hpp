#include <Engine.hpp>
#include <Sound.hpp>
#include <Input.hpp>
#include <Mouse.hpp>

namespace Game {
    class Player : public Object {
        public:
            /// @brief Função executada a cada frame do jogo, ou seja: é executada
            /// 60 vezes por segundo
            void step(GameProcess* gp);

            /// @brief Retorna o tipo de objeto, que deve ser uma string associada a classe
            /// que herdar o tipo Object
            /// @return uma string representando o tipo do objeto
            string type();

            using Object::destroy;

            ~Player();

            /// @brief Cria uma instância do player
            /// @param gp pornteiro do processo do jogo
            /// @param spriteSheet página de textura do sprite do player
            /// @param box uma caixa que informa a origem do sprite e as dimesões dele
            static Player* create(GameProcess* gp, string spriteSheet, Box box);
 
            short unsigned int life = 10;
            bool firstAttack = true;
            Sound shot_sound = Sound("shot.mp3");
        protected:
            using Object::Object;
    };
};