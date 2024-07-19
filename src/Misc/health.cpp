#include <Misc/health.hpp>

namespace Game{
    void Health::setCurrentHealth(float newHealth)
    {
        this->currentHealth = newHealth;
    }

    void Health::damage(float dmg)
    {   
        if (dmg >= this->currentHealth)
        {   
            Health::setCurrentHealth(0);
            // this->object->destroy()
        }else
        {
            Health::setCurrentHealth(this->currentHealth - dmg);
        }
    }

    void Health::heal(float heal)
    {
        if (heal > this->maxHealth)
        {   
            Health::setCurrentHealth(this->currentHealth+(std::abs(this->maxHealth - this->currentHealth)));
        }else
        {
            Health::setCurrentHealth(this->currentHealth + heal);
        }
    }

    Health::Health(Object *obj, float maxHealth)
    {
        this->object = obj;
        this->maxHealth = maxHealth;
        this->currentHealth = maxHealth;
    }
}
