#include <Tests.hpp>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  GameProcess gp;
  return RUN_ALL_TESTS();
}