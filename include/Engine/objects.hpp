#include "list.hpp"
#include <cstring>
#include <functional>

namespace lm {
  union Mask {
    Rectangle rectangle;
    Circle circle;

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

      int depth = 0;
      float image = 0;
      double rotation = 0; 

      short int state = 0;

      int speed = 0;
      double direction = 0;
      float fps = 0;
      bool loop = true;
      bool animationFinished = false;

      Object();
      Object(string spriteSheet, Box box);

      void animate(float fps, unsigned short int textureRow, bool loop = true, float image = 0);
      void scale(float scale);
      void scale(float xScale, float yScale);

      function<void(Room*, GameProcess*)> step = [](Room* room, GameProcess* gp){};
  } typedef Object;
};