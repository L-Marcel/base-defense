#include <Engine/list.hpp>
#include <cstring>
#include <functional>

namespace Game {
  // union Mask {
  //   Rectangle rectangle;
  //   Circle circle;

  //   short int state = 0;

  //   Mask() {};
  //   ~Mask() {
  //     delete this;
  //   };
  // };

  class GameProcess;
  class Object {
    public:
      /// @brief Função executada a cada frame do jogo, ou seja: é executada
      /// 60 vezes por segundo
      virtual void step(GameProcess* gp);
      
      /// @brief Retorna o tipo de objeto, que deve ser uma string associada a classe
      /// que herdar o tipo Object
      /// @return uma string representando o tipo do objeto
      virtual string type();

      /// @brief Remove a instância do jogo e libera ela da memória
      virtual void destroy();

      /// @brief Destroi objeto
      virtual ~Object();

      /// @brief Cria uma instância do objeto
      /// @param gp pornteiro do processo do jogo
      /// @param spriteSheet página de textura do sprite do objeto
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      static Object* create(GameProcess* gp, string spriteSheet, Box box);

      List<Object>* _list;
      Sprite* sprite;
      Texture* texture;
      //Mask mask;

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
    protected:
      /// @brief Cria uma instância do objeto
      /// @param spriteSheet a página de textura do sprite do objeto
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      Object(string spriteSheet, Box box);
  } typedef Object;
};