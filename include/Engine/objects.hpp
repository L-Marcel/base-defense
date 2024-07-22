#pragma once
#include <Engine/list.hpp>

namespace Game {
  class GameProcess;
  class Object {
    public:
      /// @brief Retorna o tipo de objeto, que deve ser uma string associada a classe
      /// que herdar o tipo Object
      /// @return uma string representando o tipo do objeto
      virtual string type();
    
      /// @brief Função executada a cada frame do jogo, ou seja: é executada
      /// 60 vezes por segundo
      /// @param gp ponteiro do processo do jogo
      virtual void step();

      /// @brief Função executada logo após a função step para atualizar as mascaras de colisão
      /// @param gp ponteiro do processo do jogo
      virtual void collision();
      
      ///@brief Função que desenha o objeto na tela. A classe que herdar o
      /// tipo Object deve definir a forma que o objeto será desenhado
      /// @param gp ponteiro do processo do jogo
      virtual void draw();

      /// @brief Remove a instância do jogo e libera ela da memória
      virtual void free();

      /// @brief Destroi objeto
      virtual ~Object();

      /// @brief Coloca o objeto na lista de objetos a serem apagados
      void destroy();

      /// @brief Cria uma instância do objeto
      /// @param gp ponteiro do processo do jogo
      /// @param spriteSheet página de textura do sprite do objeto
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      static Object* create(GameProcess* gp);

      int depth = 0;
    protected:
      GameProcess* gp;
      bool free_queued = false;

      /// @brief Cria uma instância do objeto
      Object();
  };
};