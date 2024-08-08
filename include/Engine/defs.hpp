#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <functional>
#include <time.h>
#include <map>
#include <locale>
#include <codecvt>
#include <vector>
#include <stack>

#define PI 3.14159265359

#define TOWER_SIZE 32
#define BASE_SIZE Vector<float>(416, 288)
#define CENTER Vector<float>(640, 360)
#define TOP_LEFT_TOWER_POSITION Vector<float>(448, 232)
#define BOTTOM_LEFT_TOWER_POSITION Vector<float>(448, 488)
#define TOP_RIGHT_TOWER_POSITION Vector<float>(832, 232)
#define BOTTOM_RIGHT_TOWER_POSITION Vector<float>(832, 488)

#define R1280x720 Resolution(1280, 720)
#define R1024x576 Resolution(1024, 576)
#define R800x600 Resolution(800, 600)

#define NORMAL_SCREEN sf::Style::Close | sf::Style::Titlebar
#define FULLSCREEN sf::Style::Fullscreen

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
  Keyboard::Key typedef Key;
  sf::Mouse::Button typedef MouseButton;
  sf::Color typedef Color;
  sf::Drawable typedef Drawable;
  sf::FloatRect typedef FloatRect;

  enum Rarity {
    GUARANTEED,
    COMMON,
    RARE,
    EPIC
  };

  template <typename T> 
    using Vector = sf::Vector2<T>;
  Vector<float> typedef Point;
  Vector<float> typedef Resolution;

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