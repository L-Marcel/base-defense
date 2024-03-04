#include "../Engine/math.hpp"

namespace lm {
  namespace Mouse {
    Coord position(Window* window = nullptr);

    bool left();
    bool right();
    bool middle();

    bool extra1();
    bool extra2();
  };
};