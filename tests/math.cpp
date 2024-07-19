#include <Tests.hpp>

TEST(MathTest, PointDirection) {
    double direction = Math::pointDirection(1.0, 1.0);
    EXPECT_FLOAT_EQ(direction, 45.0);
};

TEST(MathTest, Vector) {
    Vector<float> point = Math::pointInRadius(1.0, 45.0);
    EXPECT_FLOAT_EQ(point.x, 1.0/sqrt(2));
    EXPECT_FLOAT_EQ(point.y, 1.0/sqrt(2));
};

TEST(MathTest, Distance) {
    Vector<float> a(sqrt(2), sqrt(2));
    Vector<float> b(-sqrt(2), -sqrt(2));
    EXPECT_FLOAT_EQ(Math::pointDistance(a, b), 4.0f);
};