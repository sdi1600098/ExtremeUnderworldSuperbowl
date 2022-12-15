#ifndef AVATAR
#define AVATAR
#include <iostream>
#include "entity.hpp"
using namespace std;

class Avatar : public Entity 
{
  public:
    // Constructor
    Avatar(int health, int attack, int defense);

    // Overridden defend function
    void defend(int damage) override ;

    // Overridden attack function
    void attack(Entity& target) override ;

    // Function for moving the avatar on the grid
    void move(Grid& grid, int dx, int dy) override;

    // Getters for the avatar's position
    int getX() const ;
    int getY() const ;

  private:
    int the_x, the_y; // Avatar's position on the grid
};

#endif // AVATAR