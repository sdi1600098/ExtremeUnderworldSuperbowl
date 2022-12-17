#ifndef VAMPIRE
#define VAMPIRE
#include <iostream>
#include "Entity.hpp"
using namespace std;

class Vampire : public Entity
{
  public:
    // Constructor
    Vampire(int health);

    // Overridden defend function
    void defend(int damage) override;

    // Overridden attack function
    void attack(Entity& target) override;

    // Function for moving the vampire on the grid
    void move(Grid& grid) override;

    // Getters for the vampire's position
    int getX() const;
    int getY() const;

  private:
    int the_x, the_y; // Vampire's position on the grid
    int healing_potions; //  The amount of healing potions the vampire has
};

#endif // VAMPIRE
