#include <Tests.hpp>
#include "_mock.cpp"

namespace Mouse {
  Point position(Window* _) {
    return Point(1.0, 1.0);
  }
}

TEST(PlayerTest, Type) {
  GameProcess gp;
  Player* player = Player::create(&gp);
  EXPECT_EQ(player->type(), "Player");
}