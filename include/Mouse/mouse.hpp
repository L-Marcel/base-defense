#include "../Engine/math.hpp"

namespace lm {
  namespace Mouse {
    Coord position();
    Coord position(RenderWindow* window);

    bool left();
    bool right();
    bool middle();

    bool extra1();
    bool extra2();
  };
};