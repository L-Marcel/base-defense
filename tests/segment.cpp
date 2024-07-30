#include<Tests.hpp>

TEST(SegmentTest, Parallel) {
  Segment a(0, 0, 1, 0);
  Segment b(0, 1, 1, 1);
  EXPECT_FALSE(a & b);
};

TEST(SegmentTest, Extremity) {
  Segment a(0, 0, 1, 1);
  Segment b(0, 1, 1, 1);
  EXPECT_TRUE(a & b);
  Segment c(0, 1, 1, 0);
  Segment d(0, 1, 1, 1);
  EXPECT_TRUE(c & d);
};

TEST(SegmentTest, Equal) {
  Segment a(0, 0, 1, 1);
  EXPECT_TRUE(a & a);
};

TEST(SegmentTest, Middle) {
  Segment a(0, 0, 1, 0);
  Segment b(0.5, 1, 0.5, -1);
  EXPECT_TRUE(a & b);
  Segment c(0, 0, 1, 0);
  Segment d(2, 1, 2, -1);
  EXPECT_FALSE(c & d);
};