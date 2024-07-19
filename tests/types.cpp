#include <Tests.hpp>

TEST(Types, TypeName) {
    cout << typeid(Object).name() << endl;
    EXPECT_EQ(typeid(Object).name(), "Object");
}
