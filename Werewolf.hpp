#ifndef WEREWOLF
#define WEREWOLF
#include <iostream>
#include "Entity.hpp"
using namespace std;

class Werewolf : public Entity 
{
  public:
    // Constructor
    Werewolf(int health);

    // Overridden defend function
    void defend(int damage) override;

    // Overridden attack function
    void attack(Entity& target) override;

    // Function for moving the werewolf on the grid
    void move(Grid& grid, char input) override;

    // Getters for the werewolf's position
    int get_x() const ;
    int get_y() const ;
    int hp;
  private:
    int the_w_x, the_w_y; // Werewolf's position on the grid
    int healing_potions; //  The amount of healing potions the werewolf has
};

#endif // WEREWOLF
