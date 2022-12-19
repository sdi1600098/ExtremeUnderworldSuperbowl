#include <iostream>
#include "Werewolf.hpp"
using namespace std;


// Constructor
Werewolf::Werewolf(int health)
  : Entity(health) {hp = 69;}

// Overridden defend function
void Werewolf::defend(int damage) //override 
{
  // Reduce the damage taken based on the werewolf's defense
  damage -= the_defense;
  if (damage < 0) damage = 0;

  // Update the werewolf's health
  the_health -= damage;
}

// Overridden attack function
void Werewolf::attack(Entity& target) //override 
{
  // Deal damage to the target based on the werewolf's attack
  target.defend(the_attack);
}

// Function for moving the werewolf on the grid
void Werewolf::move(Grid& grid, char input) //override
{
  // Randomly choose a direction for the werewolf to move
  int dx = 0, dy = 0;
  int r = rand() % 4;
  if (r == 0) dx = -1;
  else if (r == 1) dx = 1;
  else if (r == 2) dy = -1;
  else if (r == 3) dy = 1;

  // Calculate the new position of the werewolf
  int x = the_w_x + dx;
  int y = the_w_y + dy;

  // Check if the new position is within the bounds of the grid
  if (x >= 0 && x < grid.get_length() && y >= 0 && y < grid.get_height()) 
  {
    // Check if the new position is passable
    //const Tile& tile = grid.get_tile(x, y);
    if (grid.map[y][x].identity == ground)
    {
      // Update the werewolf's position
      the_w_x = x;
      the_w_y = y;
    }
  }
}

// Getters for the werewolf's position
int Werewolf::get_x() const { return the_w_x; }
int Werewolf::get_y() const { return the_w_y; }


int the_w_x, the_w_y; // Werewolf's position on the grid
int healing_potions; //  The amount of healing potions the werewolf has

