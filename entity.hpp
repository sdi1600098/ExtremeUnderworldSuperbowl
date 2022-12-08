#ifndef ENTITY
#define ENTITY
#include <iostream>
using namespace std;

class Entity 
{
  public:
    // Constructor
    Entity(int health);

    // Destructor
    virtual ~Entity() {}

    // Getters
    int getHealth() const;
    int getAttack() const;
    int getDefense() const;

    // Setters
    void setHealth(int health);

    // Function for generating a random attack value
    void rand_Attack();

    // Function for generating a random defense value
    void rand_Defense();

    // Virtual functions
    virtual void defend(int damage) = 0;
    virtual void attack(Entity& target) = 0;
    virtual void move(Grid& grid) = 0;

  protected:
    int the_health, the_attack, the_defense; // Entity's stats
};

#endif // ENTITY