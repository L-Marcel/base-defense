#pragma once
#include <Engine/list.hpp>

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
      /// @brief Retorna o tipo de objeto, que deve ser uma string associada a classe
      /// que herdar o tipo Object
      /// @return uma string representando o tipo do objeto
      virtual string type();
    
      /// @brief Função executada a cada frame do jogo, ou seja: é executada
      /// 60 vezes por segundo
      virtual void step(GameProcess* gp);
      
      ///@brief Função que desenha o objeto na tela. A classe que herdar o
      /// tipo Object deve definir a forma que o objeto será desenhado
      virtual void draw(GameProcess* gp);
      
      /// @brief Remove a instância do jogo e libera ela da memória
      virtual void destroy();

      Rectangle rect_collision;
      float rcolHeight;
      float rcolWidth;
      Circle circ_collision;
      float cRadius;

      bool hasCCol;
      bool hasRCol;

      /// @brief Destroi objeto
      virtual ~Object();

      /// @brief Cria uma instância do objeto
      /// @param gp pornteiro do processo do jogo
      /// @param spriteSheet página de textura do sprite do objeto
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      static Object* create(GameProcess* gp);

      /// @brief Cria uma colisão retangular
      /// @param width a largura do retângulo
      /// @param height a altura do retângulo
      void RectCollision(float width, float height);

      /// @brief Cria uma colisão circular
      /// @param radius Raio do círculo
      void CircCollision(float radius);

      List<Object>* _list;
    protected:
      /// @brief Cria uma instância do objeto
      Object();
  } typedef Object;
};