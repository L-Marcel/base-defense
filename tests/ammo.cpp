#include <Tests.hpp>

TEST(AmmoTest, Control) {
  GameProcess gp;
  Player* player = Player::create();
  Ammo ammo(player);

  ammo.consume(1);
  EXPECT_EQ((int) ammo.get(), 19);
  ammo.consume(19);
  EXPECT_EQ((int) ammo.get(), 0);
  ammo.recharge(0);
  EXPECT_EQ((int) ammo.get(), 0);
  ammo.recharge(20);
  EXPECT_EQ((int) ammo.get(), 20);
};