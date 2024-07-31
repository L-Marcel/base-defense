#pragma once
#include <Objects.hpp>
#include <Input.hpp>

namespace Game{
  class ResolutionButton : public Button {
    public:
      virtual string type();
      virtual void step();
      using Button::collision;
      using Button::draw;
      using Button::free;
      ~ResolutionButton();

      /// @brief Cria uma instância de um botão que muda a resolução do jogo
      /// @param resolution a resolução vinculada ao botão
      static ResolutionButton* create(Resolution resolution);
    protected:
      using Button::Button;
      Resolution resolution;
  };
};