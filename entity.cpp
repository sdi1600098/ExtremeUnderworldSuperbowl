#include "entity.hpp"
#include <iostream>
using namespace std;

class Entity 
{
  public:
    // Constructor
    Entity(int health) : the_health(health) 
    {
        rand_Attack();
        rand_Defense();
    }

    // Destructor
    virtual ~Entity() {}

    // Getters
    int getHealth() const { return the_health; }
    int getAttack() const { return the_attack; }
    int getDefense() const { return the_defense; }

    // Setters
    void setHealth(int health) { the_health = health; }

    // Function for generating a random attack value
    void rand_Attack() 
    {
      the_attack = 1 + rand() % 3;
    }

    // Function for generating a random defense value
    void rand_Defense() 
    {
      the_defense = 1 + rand() % 2;
    }

    // Virtual functions
    virtual void defend(int damage) = 0;
    virtual void attack(Entity& target) = 0;
    virtual void move() = 0;

  protected:
    int the_health, the_attack, the_defense; // Entity's stats
};