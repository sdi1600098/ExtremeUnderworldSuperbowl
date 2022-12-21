#include <iostream>
#include "Werewolf.hpp"
using namespace std;


// Constructor
Werewolf::Werewolf(int health): Entity(health) 
{
  w_healing_potions = rand() % 3;
}

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

// Getter and setter for the werewolf's potions

int Werewolf::get_w_healing_potions() const 
{
  return w_healing_potions;
}

void Werewolf::set_w_healing_potions(int potions) 
{
  w_healing_potions = potions;
}

// Function for interactions
void Werewolf::attack_or_heal(Grid& grid, Werewolf& other)
{
  // Check if the other entity is within the bounds of the grid
  if (other.get_x() >= 0 && other.get_x() < grid.get_length() && other.get_y() >= 0 && other.get_y() < grid.get_height())
  {
    // Check if other werewolf is adjacent
    if (abs(the_w_x - other.get_x()) <= 1 && abs(the_w_y - other.get_y()) <= 1)
    {
      // Check if other werewolf is not at full health and this werewolf has potions
      if (other.get_health() < 3 && w_healing_potions > 0)
      {
        // Randomly decide whether to use a potion
        if (rand() % 2 == 0)
        {
          // Use a potion and update the number of potions remaining
          other.set_health(other.get_health() + 1);
          set_w_healing_potions(w_healing_potions - 1);
        }
      } 
    }
    // Check if there is a vampire adjacent
    else if (abs(the_w_x - other.get_x()) <= 1 && abs(the_w_y - other.get_y()) <= 1)
    {
      // Check if this werewolf has higher attack than the vampire
      if (get_attack() > other.get_attack())
      {
        // Attack the vampire
        attack(other);
      }
    }
  }
}