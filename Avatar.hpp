#ifndef AVATAR
#define AVATAR
#include <iostream>
#include "Entity.hpp"
#include "Werewolf.hpp"
#include "Vampire.hpp"
using namespace std;

class Avatar : public Entity 
{
  public:
    // Constructor
    Avatar(int health);

    // Overridden defend function
    void defend(int damage) override;

    // Overridden attack function
    void attack(Entity& target) override;

    // Function for moving the avatar on the grid
    void move(Grid& grid, char input) override;

    // Getters for the avatar's position
    int get_x() const ;
    int get_y() const ;

    // Getter and setter for the avatar's potions
    int get_magic_potions() const;
    void set_magic_potions(int potions);

    // Function for using a magic potion
    void use_magic_potion(char side,int number_of_team_members, Werewolf* w_array, Vampire* v_array);

  private:
    int the_x, the_y; // Avatar's position on the grid
    int magic_potions; // the amount of magic potions the avatar has
};

#endif // AVATAR
