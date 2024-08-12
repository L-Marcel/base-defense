#include <Tests.hpp>

TEST(AmmoTest, Control) {
  Player* player = Player::create();

  player->clip.consume(1);
  EXPECT_EQ((int) player->clip.get(), 5);
  player->clip.consume(5);
  EXPECT_EQ((int) player->clip.get(), 0);
  player->clip.recharge(0);
  EXPECT_EQ((int) player->clip.get(), 0);
  player->clip.recharge(20);
  EXPECT_EQ((int) player->clip.get(), 6);
};