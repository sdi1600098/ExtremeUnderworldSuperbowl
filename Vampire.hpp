#ifndef VAMPIRE
#define VAMPIRE
#include <iostream>
#include <math.h>
#include "Entity.hpp"
using namespace std;

class Vampire : public Entity
{
  public:
    //Default Constructor
    Vampire();
    // Constructor
    Vampire(int health);

    // Overridden defend function
    void defend(int damage) override;

    // Overridden attack function
    void attack(Entity& target) override;

    // Function for moving the vampire on the grid
    void move(Grid& grid, char input) override;

    //Setters
    void set_x(int x);
    void set_y(int y);

    // Getters for the vampire's position
    int get_x() const;
    int get_y() const;

    // Getter and setter for the vampire's potions
    int get_v_healing_potions() const;
    void set_v_healing_potions(int potions);

    // Function for interactions
    void attack_or_heal(Grid& grid, Vampire& other);

  private:
    int the_v_x, the_v_y; // Vampire's position on the grid
    int v_healing_potions; //  The amount of healing potions the vampire has
};

#endif // VAMPIRE
