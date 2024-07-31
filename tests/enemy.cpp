#include <Tests.hpp>

TEST(EnemyTest, Type) {
  GameProcess gp;
  Player::create();
  Base::create();
  Enemy* enemy = Enemy::create();
  EXPECT_EQ(enemy->type(), "Enemy");
};