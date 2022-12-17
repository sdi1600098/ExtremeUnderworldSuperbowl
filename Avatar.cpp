#include <iostream>
#include "Avatar.hpp"
using namespace std;


// Constructor
Avatar::Avatar(int health)
  : Entity(health) {}

// Overridden defend function
void Avatar::defend(int damage) override 
{
  // Reduce the damage taken based on the avatar's defense
  damage -= the_defense;
  if (damage < 0) damage = 0;

  // Update the avatar's health
  the_health -= damage;
}

// Overridden attack function
void Avatar::attack(Entity& target) override 
{
  // Deal damage to the target based on the avatar's attack
  target.defend(the_attack);
}

// Function for moving the avatar on the grid
void Avatar::move(Grid& grid, char input) override
{
    // Get the current position of the avatar
    int x = getX();
    int y = getY();

    // Update the position of the avatar based on the input
    switch(input)
    {
        case 'w' :
            if(y > 0)
            {
                // Update the avatar's position on the grid
                grid.set_identity(y, x, ground);
                grid.set_identity(y - 1, x, player_avatar);

                // Update the avatar's position variables
                the_x = x;
                the_y = y - 1;
            }
            break;

        case 'a' :
            if(x > 0)
            {
                // Update the avatar's position on the grid
                grid.set_identity(y, x, ground);
                grid.set_identity(y, x - 1, player_avatar);

                // Update the avatar's position variables
                the_x = x - 1;
                the_y = y;
            }
            break;

        case 's' :
            if(y < grid.getHeight() - 1)
            {
                // Update the avatar's position on the grid
                grid.set_identity(y, x, ground);
                grid.set_identity(y + 1, x, player_avatar);

                // Update the avatar's position variables
                the_x = x;
                the_y = y + 1;
            }
            break;

        case 'd' :
            if(x < grid.getLength() - 1)
            {
                // Update the avatar's position on the grid
                grid.set_identity(y, x, ground);
                grid.set_identity(y, x + 1, player_avatar);

                // Update the avatar's position variables
                the_x = x + 1;
                the_y = y;
            }
            break;
        default:
        break;
    }
}    

// Getters for the avatar's position
int Avatar::getX() const { return the_x; }
int Avatar::getY() const { return the_y; }


int the_x, the_y; // Avatar's position on the grid

