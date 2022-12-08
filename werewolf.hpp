#ifndef WEREWOLF_HPP
#define WEREWOLF_HPP

#include "entity.hpp"

class Werewolf : public Entity 
{
  public:
    // Constructor
    Werewolf(int health, int attack, int defense);

    // Overridden defend function
    void defend(int damage) override ;

    // Overridden attack function
    void attack(Entity& target) override ;

    // Function for moving the werewolf on the grid
    void move(Grid& grid) override ;

    // Getters for the werewolf's position
    int getX() const ;
    int getY() const ;

  private:
    int the_x, the_y; // Werewolf's position on the grid
};

#endif // WEREWOLF_HPP