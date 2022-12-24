#ifndef VAMPIRE
#define VAMPIRE
#include <iostream>
#include <math.h>
#include "Entity.hpp"
#include "Werewolf.hpp"
using namespace std;

class Vampire : public Entity
{
  public:
    // Constructor
    Vampire(int health);

    // Function for moving the vampire on the grid
    void move(Grid* grid, char input) override;
    void retreat(Grid* grid, char input);

    //Setters
    void set_x(int x);
    void set_y(int y);

    // Getters for the vampire's position
    int get_x() const;
    int get_y() const;

    // Getter and setter for the vampire's potions
    int get_v_healing_potions() const;
    void set_healing_potions(int potions);

    // Function for interactions
    void heal_or_attack(Grid* grid);

  private:
    int the_x, the_y; // Vampire's position on the grid
    int healing_potions; //  The amount of healing potions the vampire has
};

#endif // VAMPIRE

