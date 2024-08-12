#include <Tests.hpp>

TEST(NotFound, TextureNotFound) {
  EXPECT_ANY_THROW({
    Object2D::create("", Box(10,10,10,10));
  });
  EXPECT_ANY_THROW({
    Object2D::create(".png", Box(10,10,10,10));
  });
};

TEST(NotFound, SoundNotFound) {
  EXPECT_ANY_THROW({
    Sound sound("");
  });
  EXPECT_ANY_THROW({
    Sound sound(".ogg");
  });
};