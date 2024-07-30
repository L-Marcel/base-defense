#include <Tests.hpp>
#include "_mock.cpp"

TEST(Object2DTest, Type) {
  GameProcess gp;
  Object2D* object = Object2D::create(&gp, "player.png", Box(12, 14, 24, 28));
  EXPECT_EQ(object->type(), "Object2D");
}