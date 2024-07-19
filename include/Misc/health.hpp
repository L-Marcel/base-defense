#ifndef HEALTH_HPP
#define HEALTH_HPP

#include <Engine/objects.hpp>
#include <SFML/Graphics.hpp>
#include <Engine.hpp>

namespace Game {
    class Health{
    public:
        Object* object; 
        float currentHealth;
        float maxHealth;

        void setCurrentHealth(float newHealth);

        void damage(float dmg);
        void heal(float heal);

        Health(
            Object* obj, 
            float maxHealth
        );

    };
};

#endif