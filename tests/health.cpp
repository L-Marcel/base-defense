#include <Tests.hpp>

TEST(HealthTest, Control) {
  Player* player = Player::create();

  player->health.damage(30.0);
  EXPECT_FLOAT_EQ(player->health.get(), 70.0);
  player->health.heal(20.0);
  EXPECT_FLOAT_EQ(player->health.get(), 90.0);
  player->health.heal(20.0);
  EXPECT_FLOAT_EQ(player->health.percent(),  1);
  player->health.damage(50.0);
  EXPECT_FLOAT_EQ(player->health.percent(),  0.5);
  player->health.damage(25.0);
  EXPECT_FLOAT_EQ(player->health.percent(),  0.25);
  player->health.damage(100.0);
  EXPECT_FLOAT_EQ(player->health.percent(),  0);
};