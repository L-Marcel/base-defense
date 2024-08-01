#pragma once
#include <Objects.hpp>
#include <Input.hpp>
#include <Objects/text.hpp>

namespace Game{
  class Text;
  class Button : public Object2D {
    public:
      virtual string type();
      using Object2D::step;
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      virtual ~Button();

      /// @brief Cria uma instância de um botão
      /// @param sprite sprite do botão
      /// @param box caixa que informa a origem e tamanho do sprite
      /// @param pauseBt se é um botão de tela de pause
      /// @return uma instância de um botão
      static Button* create(string sprite, Box box, bool pauseBt);
      
      /// @brief Diz se o mouse está em cima do botão
      /// @return `true` se estiver, `false` caso contrário
      bool isHovered();
    protected:
      /// @brief Cria uma instância do botão
      /// @param spriteSheet página de textura do sprite do botão
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      Button(string spriteSheet, Box box);
      Button();
  };
}