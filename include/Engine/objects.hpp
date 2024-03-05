#include "list.hpp"
#include <cstring>
#include <functional>

namespace lm {
  union Mask {
    Rectangle rectangle;
    Circle circle;

    short int state = 0;

    Mask() {};
    ~Mask() {
      delete this;
    };
  };

  class Room;
  class GameProcess;
  class Object : public Instantiable {
    public:
      Sprite* sprite;
      Texture* texture;
      Mask mask;

      float x = 0;
      float y = 0;

      int depth = 0;
      float image = 0;
      double rotation = 0; 

      short int state = 0;

      int speed = 0;
      double direction = 0;
      float fps = 0;
      bool loop = true;
      bool animationFinished = false;

      /// @brief Cria uma instância do objeto
      Object();

      /// @brief Cria uma instância do objeto
      /// @param spriteSheet a página de textura do sprite do objeto
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      Object(string spriteSheet, Box box);

      /// @brief Inicia uma das animações disponíveis para o objeto
      /// @param fps o número de frames por segundo
      /// @param textureRow a linha da animação na textura (do sprite)
      /// @param loop se é animação deve ficar se repetindo
      /// @param image o íncide do frame da animação
      void animate(float fps, unsigned short int textureRow, bool loop = true, float image = 0);
     
      /// @brief Muda a escala do objeto
      /// @param scale a nova escala
      void scale(float scale);

      /// @brief Muda a escala do objeto
      /// @param xScale a escala x
      /// @param yScale a escala y
      void scale(float xScale, float yScale);

      /// @brief Função executada a cada frame do jogo, ou seja: é executada
      /// 60 vezes por segundo
      function<void(Room*, GameProcess*)> step = [](Room* room, GameProcess* gp){};
  } typedef Object;
};