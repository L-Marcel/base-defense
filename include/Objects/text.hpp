#pragma once
#include <Objects.hpp>

namespace Game {
  class Text : public Object {
    public:
      virtual string type();
      using Object::step;
      using Object::collision;
      virtual void draw();
      using Object::free;
      virtual ~Text();

      /// @brief Cria uma instância do texto
      /// @param gp ponteiro do processo do jogo
      /// @param position a posição do texto
      /// @param content o conteúdo do texto
      static Text* create(GameProcess* gp, Vector<float> position, string content, unsigned int size);
      
      /// @brief Define a posição do texto
      /// @param position a posição
      void setPosition(Vector<float> position);

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

      /// @brief Carrega o arquivo da fonte
      /// @param filename o nome do arquivo
      void loadFontFromFile(string filename);

      Text();
    private:
      sf::Text text;
      sf::Font font;
  };
};