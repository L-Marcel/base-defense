#include <Engine/objects.hpp>

namespace Game {
  class Object2D : public Object {
    public:
      virtual string type();
      virtual void step(GameProcess* gp);
      virtual void draw(GameProcess* gp);
      virtual void destroy();
      virtual ~Object2D();

      /// @brief Cria uma instância do objeto 2D
      /// @param gp pornteiro do processo do jogo
      /// @param spriteSheet página de textura do sprite do objeto 2D
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      static Object2D* create(GameProcess* gp, string spriteSheet, Box box);

      Sprite* sprite;
      Vector<float> position;

      int depth = 0;
      float image = 0;
      double rotation = 0; 

      int speed = 0;
      double direction = 0;
      float fps = 0;
      bool loop = true;
      bool animationFinished = false;

      /// @brief Inicia uma das animações disponíveis para o objeto 2D
      /// @param fps o número de frames por segundo
      /// @param textureRow a linha da animação na textura (do sprite)
      /// @param loop se é animação deve ficar se repetindo
      /// @param image o íncide do frame da animação
      void animate(float fps, unsigned short int textureRow, bool loop = true, float image = 0);
     
      /// @brief Muda a escala do objeto 2D
      /// @param scale a nova escala
      void scale(float scale);

      /// @brief Muda a escala do objeto 2D
      /// @param xScale a escala x
      /// @param yScale a escala y
      void scale(float xScale, float yScale);
    protected:
      /// @brief Cria uma instância do objeto 2D
      /// @param spriteSheet página de textura do sprite do objeto 2D
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      Object2D(string spriteSheet, Box box);
  };
};