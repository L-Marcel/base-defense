#include <Tests.hpp>
#include "_mock.cpp"

TEST(ObjectTest, Type) {
  GameProcess gp;
  Object* object = Object::create();
  EXPECT_EQ(object->type(), "Object");
};

TEST(ObjectTest, Destroy) {
  GameProcess gp;
  Object* object = Object::create();
  EXPECT_EQ((int) GameProcess::length(), 1);
  GameProcess::destroy(object);
  gp.nextFrame();
  EXPECT_EQ((int) GameProcess::length(), 0);
};