#ifndef WEREWOLF
#define WEREWOLF
#include <iostream>
#include <math.h>
#include "Entity.hpp"
#include "Vampire.hpp"
using namespace std;

class Werewolf : public Entity
{
public:
  // Constructor
  Werewolf(int health);

  // Function for moving the werewolf on the grid
  void move(Grid *grid, char input) override;
  void retreat(Grid *grid, char input);

  // Setters for the werewolves' position
  void set_x(int x);
  void set_y(int y);
  // Getters for the werewolf's position
  int get_x() const;
  int get_y() const;
  // Getter and setter for the vampire's potions
  int get_w_healing_potions() const;
  void set_healing_potions(int potions);

  // Function for interactions
  void heal_or_attack(Grid *grid);

private:
  int the_x, the_y;    // Werewolf's position on the grid
  int healing_potions; //  The amount of healing potions the werewolf has
};

#endif // WEREWOLF

