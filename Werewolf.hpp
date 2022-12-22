#ifndef WEREWOLF
#define WEREWOLF
#include <iostream>
#include <math.h>
#include "Entity.hpp"
using namespace std;

class Werewolf : public Entity 
{
  public:
    //Default Constructor
    Werewolf();

    // Constructor
    Werewolf(int health);

    // Overridden defend function
    void defend(int damage) override;

    // Overridden attack function
    void attack(Entity& target) override;

    // Function for moving the werewolf on the grid
    void move(Grid& grid, char input) override;

    //Setters for the werewolves' position
    void set_x(int x);
    void set_y(int y);
    // Getters for the werewolf's position
    int get_x() const ;
    int get_y() const ;
    //int hp;
    // Getter and setter for the vampire's potions
    int get_w_healing_potions() const;
    void set_w_healing_potions(int potions);

    // Function for interactions
    void attack_or_heal(Grid& grid, Werewolf& other);

  private:
    int the_w_x, the_w_y; // Werewolf's position on the grid
    int w_healing_potions; //  The amount of healing potions the werewolf has
};

#endif // WEREWOLF
