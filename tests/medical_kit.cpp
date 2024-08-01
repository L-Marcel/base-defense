#include <Tests.hpp>

TEST(MedicalKitTest, Type) {
  GameProcess gp;
  MedicalKit* medkit = MedicalKit::create(Point(300,300));
  EXPECT_EQ(medkit->type(), "MedicalKit");
};