#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;

namespace lm {
  class Clock : public sf::Clock {
    using sf::Clock::Clock;
  };

  // class Time : public sf::Time {
  //   public:
  //     using sf::Time::Time;
  //     Time(const sf::Time& time);
  // };

  class Event : public sf::Event {
    using sf::Event::Event;
  };

  class Window : public sf::RenderWindow {
    using sf::RenderWindow::RenderWindow;
  };
  
  class VideoMode : public sf::VideoMode {
    using sf::VideoMode::VideoMode;
  };

  class Box : public sf::IntRect {
    public:
      /// @brief cria uma caixa
      /// @param x a posição x origem da caixa
      /// @param y a posição y origem da caixa
      /// @param w a largura da caixa
      /// @param h a altura da caixa
      Box(int x, int y, int w, int h);
  };

  class Rectangle : public sf::RectangleShape {
    using sf::RectangleShape::RectangleShape;
  };

  class Circle : public sf::CircleShape {
    using sf::CircleShape::CircleShape;
  };

  class Sprite : public sf::Sprite {
    using sf::Sprite::Sprite;
  };

  class Texture : public sf::Texture {
    using sf::Texture::Texture;
  };

  class Coord : public sf::Vector2f {
    public:
      /// @brief Cria um parzinho de coordenadas
      /// @param x a coordenada do eixo x
      /// @param y a coordenada do eixo y
      Coord(float x, float y);
  };
};