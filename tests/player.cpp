#include <Tests.hpp>
#include "_mock.cpp"

TEST(PlayerTest, Type) {
  GameProcess gp;
  Player* player = Player::create();
  EXPECT_EQ(player->type(), "Player");
};