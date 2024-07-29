#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <typeinfo>
#include <string>
#include <iostream>
#include <cmath>

#define TOWER_SIZE 32
#define BASE_SIZE Vector<float>(416, 288)
#define CENTER Vector<float>(640, 360)
#define TOP_LEFT_TOWER_POSITION Vector<float>(448, 232)
#define BOTTOM_LEFT_TOWER_POSITION Vector<float>(448, 488)
#define TOP_RIGHT_TOWER_POSITION Vector<float>(832, 232)
#define BOTTOM_RIGHT_TOWER_POSITION Vector<float>(832, 488)

using namespace std;

namespace Game {
  sf::Clock typedef Clock;
  sf::Time typedef Time;
  sf::Event typedef Event;
  sf::RenderWindow typedef Window;
  sf::VideoMode typedef VideoMode;
  sf::View typedef View;
  sf::IntRect typedef Box;
  sf::RectangleShape typedef Rectangle;
  sf::CircleShape typedef Circle;
  sf::Sprite typedef Sprite;
  sf::Texture typedef Texture;
  sf::Keyboard typedef Keyboard;
  sf::Color typedef Color;

  template <typename T> 
    using Vector = sf::Vector2<T>;

  Vector<float> typedef Point;

  template <typename T> class Vector4 {
    public:
      T x;
      T y;
      T z;
      T w;

      inline Vector4(T x, T y, T z, T w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
      };
  };
  
  template <typename T>
    inline ostream& operator<<(ostream& os, const Vector<T>& vec) {
      os << "(" << vec.x << ", " << vec.y << ")";
      return os;
    };

  template <typename T>
    inline ostream& operator<<(ostream& os, const Vector4<T>& vec) {
      os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
      return os;
    };
};