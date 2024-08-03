#pragma once
#include <Objects/object.hpp>

namespace Game {
  class Text : public Object {
    public:
      virtual string type();
      using Object::step;
      using Object::collision;
      virtual void draw();
      using Object::free;
      ~Text();

      /// @brief Cria uma instância do texto
      /// @param position a posição do texto
      /// @param content o conteúdo do texto
      static Text* create(Point position, string content);

      /// @brief Define a posição do texto
      /// @param position a posição
      void setPosition(Point position);

      /// @brief Define a fonte do texto
      /// @param font a fonte
      void setFont(sf::Font& font);

      /// @brief Define o contúdo do texto
      /// @param content o conteúdo
      void setText(string content);

      /// @brief Define o tamanho da fonte
      /// @param size o tamanho em pixels
      void setSize(unsigned int size);

      /// @brief Define a cor do texto
      /// @param color a cor
      void setColor(Color color);

      /// @brief Define o alinhamento do texto para o meio dele
      void setAlignCenter();

      /// @brief Carrega o arquivo da fonte
      /// @param filename o nome do arquivo
      void loadFontFromFile(string filename);

      /// @brief Cria um texto
      Text();
    private:
      sf::Text text;
      sf::Font font;
  };
};