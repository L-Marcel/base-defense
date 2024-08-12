#pragma once
#include <Engine/list.hpp>

namespace Game {
  
  class Object {
    public:
      /// @brief Retorna o tipo de objeto, que deve ser uma string associada a classe
      /// que herdar o tipo Object
      /// @return uma string representando o tipo do objeto
      virtual string type();
    
      /// @brief Função executada a cada frame do jogo, ou seja: é executada
      /// 60 vezes por segundo
      virtual void step();

      /// @brief Função executada logo após a função step para atualizar as mascaras de colisão
      virtual void collision();
      
      ///@brief Função que desenha o objeto na tela. A classe que herdar o
      /// tipo Object deve definir a forma que o objeto será desenhado
      virtual void draw();

      /// @brief Remove a instância do jogo e libera ela da memória
      virtual void free();

      /// @brief Destroi objeto
      virtual ~Object();

      /// @brief Coloca o objeto na lista de objetos a serem apagados
      void destroy();

      /// @brief Cria uma instância do objeto
      /// @param sprite_sheet página de textura do sprite do objeto
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      static Object* create();

      /// @brief Diz se o objeto é pausável
      /// @return `true` se for, `false` caso contrário
      bool isPausable();

      int depth = 0;
      bool visible = true;
    protected:
      bool free_queued = false;
      bool pausable = true;

      /// @brief Cria uma instância do objeto
      Object();
  };
};