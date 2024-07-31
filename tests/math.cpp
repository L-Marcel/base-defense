#include <Tests.hpp>

TEST(MathTest, PointDirection) {
  double direction = Math::pointDirection(1.0, 1.0);
  EXPECT_FLOAT_EQ(direction, 45.0);
};

TEST(MathTest, Vector) {
  Point point = Math::pointInRadius(1.0, 45.0);
  EXPECT_FLOAT_EQ(point.x, 1.0/sqrt(2));
  EXPECT_FLOAT_EQ(point.y, 1.0/sqrt(2));
};

TEST(MathTest, Distance) {
  Point a(sqrt(2), sqrt(2));
  Point b(-sqrt(2), -sqrt(2));
  EXPECT_FLOAT_EQ(Math::pointDistance(a, b), 4.0f);
};