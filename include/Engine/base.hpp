#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;

namespace lm {
  sf::Clock typedef Clock;
  sf::Time typedef Time;
  sf::Event typedef Event;
  sf::RenderWindow typedef Window;
  sf::VideoMode typedef VideoMode;
  sf::IntRect typedef Box;
  sf::RectangleShape typedef Rectangle;
  sf::CircleShape typedef Circle;
  sf::Sprite typedef Sprite;
  sf::Texture typedef Texture;
  sf::Keyboard typedef Keyboard;

  template <typename T> 
    using Vector = sf::Vector2<T>;
  
  template <typename T> 
    using Vector3 = sf::Vector3<T>;
};