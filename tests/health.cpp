#include <gtest/gtest.h>
#include <Engine/objects.hpp>
#include <SFML/Graphics.hpp>
#include <Engine.hpp>
#include <Misc/health.hpp>

Mock Object class for testing
class MockObject : public Game::Object {
public:
    MockObject() : Game::Object("assets/bullet.png", Game::Box(0, 0, 10, 10)) {}
};

Test for Health component creation
TEST(HealthTest, Creation) {
    MockObject mockObject;
    float maxHealth = 100.0f;
    Game::Health healthComponent(&mockObject, maxHealth);

    EXPECT_EQ(healthComponent.object, &mockObject);
    EXPECT_EQ(healthComponent.currentHealth, maxHealth);
    EXPECT_EQ(healthComponent.maxHealth, maxHealth);
}

// Test for Health component methods
TEST(HealthTest, Methods) {
    MockObject mockObject;
    float maxHealth = 100.0f;
    Game::Health healthComponent(&mockObject, maxHealth);

    // Test damage
    healthComponent.damage(30.0f);
    EXPECT_EQ(healthComponent.currentHealth, 70.0f);

    // Test heal
    healthComponent.heal(20.0f);
    EXPECT_EQ(healthComponent.currentHealth, 90.0f);

    // Test overhealing
    healthComponent.heal(20.0f);
    EXPECT_EQ(healthComponent.currentHealth, maxHealth);

    // Test overdamage
    healthComponent.damage(150.0f);
    EXPECT_EQ(healthComponent.currentHealth, 0.0f);
}