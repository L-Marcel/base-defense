#pragma once
#include <Buttons.hpp>
#include <Objects/text.hpp>
#include <Objects/object_2d.hpp>

namespace Game {
  class Menu : public Object2D {
    public:
      virtual string type();
      using Object2D::step;
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      virtual ~Menu();

      /// @brief Fecha o menu
      void close();

      List<Object2D> objects;
    protected:
      List<Text> texts;

      /// @brief Cria uma instância do menu
      /// @param spriteSheet página de textura do sprite do menu
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      Menu(string spriteSheet, Box box);
  };
};