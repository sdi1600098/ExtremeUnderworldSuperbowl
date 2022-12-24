#ifndef ENTITY
#define ENTITY
#include "Grid.hpp"
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
    int get_health() const;
    int get_attack() const;
    int get_defense() const;

    // Setters
    void set_health(int health);

    // Function for generating a random attack value
    void rand_attack();

    // Function for generating a random defense value
    void rand_defense();

    // Virtual functions
    virtual void move(Grid* grid, char input) = 0;

  protected:
    int the_health, the_attack, the_defense; // Entity's stats
};

#endif // ENTITY

