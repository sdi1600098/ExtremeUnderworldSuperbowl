#include <iostream>
#include "Vampire.hpp"
using namespace std;


// Constructor
Vampire::Vampire(int health): Entity(health) 
  {
    v_healing_potions = rand() % 3;
  } 

// Overridden defend function
void Vampire::defend(int damage) //override 
{
  // Reduce the damage taken based on the vampire's defense
  damage -= the_defense;
  if (damage < 0) damage = 0;

  // Update the vampire's health
  the_health -= damage;
}

// Overridden attack function
void Vampire::attack(Entity& target) //override 
{
  // Deal damage to the target based on the vampire's attack
  target.defend(the_attack);
}

// Function for moving the vampire on the grid
void Vampire::move(Grid& grid, char input) //override
{
  // Randomly choose a direction for the vampire to move
  int dx = rand() % 3 - 1; // -1, 0, or 1
  int dy = rand() % 3 - 1; // -1, 0, or 1

  // Calculate the new position of the vampire
  int x = the_v_x + dx;
  int y = the_v_y + dy;

  // Check if the new position is within the bounds of the grid
  if (x >= 0 && x < grid.get_length() && y >= 0 && y < grid.get_height()) 
  {
    // Check if the new position is passable
    //const Tile& tile = grid.get_tile(x, y);
    if (grid.map[y][x].identity == ground) 
    {
      // Update the vampire's position
      the_v_x = x;
      the_v_y = y;
    }
  }
}

// Getters for the vampire's position
int Vampire::get_x() const { return the_v_x; }
int Vampire::get_y() const { return the_v_y; }

// Getter and setter for the vampire's potions

int Vampire::get_v_healing_potions() const 
{
  return v_healing_potions;
}

void Vampire::set_v_healing_potions(int potions) 
{
  v_healing_potions = potions;
}

// Function for interactions
void Vampire::attack_or_heal(Grid& grid, Vampire& other)
{
  // Check if the other entity is within the bounds of the grid
  if (other.get_x() >= 0 && other.get_x() < grid.get_length() && other.get_y() >= 0 && other.get_y() < grid.get_height())
  {
    // Check if other vampire is adjacent
    if (abs(the_v_x - other.get_x()) <= 1 && abs(the_v_y - other.get_y()) <= 1)
    {
      // Check if other vampire is not at full health and this vampire has magic potions
      if (other.get_health() < 3 && v_healing_potions > 0)
      {
        // Randomly decide whether to use a magic potion
        if (rand() % 2 == 0)
        {
          // Use a magic potion and update the number of potions remaining
          other.set_health(other.get_health() + 1);
          set_v_healing_potions(v_healing_potions - 1);
        }
      } 
    }
    // Check if there is a werewolf adjacent
    else if (abs(the_v_x - other.get_x()) <= 1 && abs(the_v_y - other.get_y()) <= 1)
    {
      // Check if this vampire has higher attack than the werewolf
      if (get_attack() > other.get_attack())
      {
        // Attack the werewolf
        attack(other);
      }
    }
  }
}

