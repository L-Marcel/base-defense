#pragma once
#include <Objects/object_2d.hpp>

//MOTIVAÇÃO PARA CRIAÇÃO DE UMA CLASSE TÃO "PRIMOROSA" QUE NEM A QUE ESTÁ DIANTE DE SEUS OLHOS:
//Estava tentando criar uma variável do tipo Object2D, mas tava bugando a classe player, aí criei essa classe para servir como imagem ou animação de algo que não tem nenhuma peculiaridade.

namespace Game{
  class Image : public Object2D{
    public:
      virtual string type();
      using Object2D::step;
      using Object2D::draw;
      using Object2D::free;
      virtual ~Image();

      /// @brief Cria uma instância de um image
      /// @param spriteSheet spritesheet do image
      /// @param box uma caixa que informa a origem do sprite e as dimensões dele
      /// @return uma instância de um image
      static Image* create(string spriteSheet, Box box);

    protected:
      using Object2D::Object2D;
  };
}