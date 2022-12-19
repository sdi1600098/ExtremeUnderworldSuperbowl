#include <iostream>
#include "Vampire.hpp"
using namespace std;


// Constructor
Vampire::Vampire(int health)
  : Entity(health) {} 

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


int the_v_x, the_v_y; // Vampire's position on the grid
int v_healing_potions; //  The amount of healing potions the vampire has

