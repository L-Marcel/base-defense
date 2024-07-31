#include <Tests.hpp>

TEST(MedicalKitTest, Type) {
  GameProcess gp;
  MedicalKit* medkit = MedicalKit::create(&gp, Vector<float>(300,300));
  EXPECT_EQ(medkit->type(), "MedicalKit");
}

TEST(MedicalKitTest, Destroy) {
  GameProcess gp;
  MedicalKit* medkit = MedicalKit::create(&gp, Vector<float>(300,300));
  gp.objects.add(medkit);
  medkit->free();
  EXPECT_EQ((int) gp.objects.length(), 0);
}