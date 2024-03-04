#include "../Engine/math.hpp"

namespace lm {
  namespace Mouse {
    Vector<float> position(Window* window = nullptr);

    bool left();
    bool right();
    bool middle();

    bool extra1();
    bool extra2();
  };
};