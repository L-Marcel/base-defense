#include <Tests.hpp>
#include "_mock.cpp"

TEST(ObjectTest, Type) {
    GameProcess gp;
    Object* object = Object::create(&gp);
    EXPECT_EQ(object->type(), "Object");
}

TEST(ObjectTest, Destroy) {
    GameProcess gp;
    Object* object = Object::create(&gp);
    object->destroy();
    EXPECT_EQ((int) gp.objects.length(), 0);
}