#include <Tests.hpp>

TEST(AmmoTest, Control) {
  GameProcess gp;
  Player* player = Player::create();
  Ammo ammo(player);

  ammo.shoot(1);
  EXPECT_FLOAT_EQ(ammo.get(), 19.0);
  ammo.shoot(19);
  EXPECT_FLOAT_EQ(ammo.get(), 0.0);
  ammo.recharge(0);
  EXPECT_FLOAT_EQ(ammo.get(), 0.0);
  ammo.recharge(20);
  EXPECT_FLOAT_EQ(ammo.get(), 20.0);
};