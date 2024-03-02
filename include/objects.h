#include "list.h"
#include <cstring>
#include <SFML/Graphics.hpp>

using namespace sf;

namespace lm {
  class Box : public IntRect {
    public:
      /// @brief cria uma caixa
      /// @param x a posição x origem da caixa
      /// @param y a posição y origem da caixa
      /// @param w a largura da caixa
      /// @param h a altura da caixa
      Box(int x, int y, int w, int h);
  };

  union Mask {
    RectangleShape rect;
    CircleShape circ;
    short int state = 0;

    Mask() {};
    ~Mask() {
      delete this;
    };
  };

  class Room;
  class GameProcess;
  class Object : public Instantiable {
    public:
      Sprite* sprite;
      Texture* texture;
      Mask mask;

      float x = 0;
      float y = 0;

      float image = 0;
      short int state = 0;
      int speed = 0;
      int direction = 0;
      float fps = 0;

      Object();
      Object(string spriteSheet, Box box);

      void animate(float fps, unsigned short int textureRow);
      void animate(float fps, unsigned short int textureRow, float image);
      void draw(RenderWindow* window, unsigned short int frame);

      /// @brief Define a função "onStep" do objeto
      /// @param func a função
      void step(void (*func)(Object* self, Room* room, GameProcess* gp));

      void (*onStep)(Object* self, Room* room, GameProcess* gp);
  } typedef ObjectType;
};