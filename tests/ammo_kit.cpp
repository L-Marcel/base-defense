#include <Tests.hpp>

TEST(AmmoKitTest, Type) {
  GameProcess gp;
  AmmoKit* ammokit = AmmoKit::create(Point(300, 300));
  EXPECT_EQ(ammokit->type(), "AmmoKit");
}