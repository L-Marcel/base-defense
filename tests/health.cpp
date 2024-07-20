#include <Tests.hpp>

TEST(HealthTest, Control) {
  GameProcess gp;
  Player* player = Player::create(&gp);
  Health health(player);

  health.damage(30.0);
  EXPECT_FLOAT_EQ(health.get(), 70.0);
  health.heal(20.0);
  EXPECT_FLOAT_EQ(health.get(), 90.0);
  health.heal(20.0);
  EXPECT_FLOAT_EQ(health.percent(),  1);
  health.damage(50.0);
  EXPECT_FLOAT_EQ(health.percent(),  0.5);
  health.damage(25.0);
  EXPECT_FLOAT_EQ(health.percent(),  0.25);
  EXPECT_EQ((int) gp.objects.length(), 1);
  health.damage(100.0);
  EXPECT_FLOAT_EQ(health.percent(),  0);
  EXPECT_EQ((int) gp.objects.length(), 0);
};