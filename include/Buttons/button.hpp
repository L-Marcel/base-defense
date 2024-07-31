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

      /// @brief Retorna se o botão já foi "ponte'ado" (se um BridgeButton já fez a ponte para esse botão)
      /// @return se o botão já foi "ponte'ado"
      bool wasBridged();

      /// @brief Muda a variável bridged da classe
      /// @param bridged 
      void setBridged(bool bridged);

      /// @brief Diz se o mouse está em cima do botão
      /// @return `true` se estiver, `false` caso contrário
      bool isMouseHovering();
    protected:
      Button();
      Button(string spriteSheet, Box box);
      unsigned short int buttonWidth;
      unsigned short int buttonHeight;
      bool isClicked = false;
      bool bridged = false;
  };
}