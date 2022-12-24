#include <iostream>
#include "Vampire.hpp"
using namespace std;

// Constructor
Vampire::Vampire(int health) : Entity(health)
{
  healing_potions = rand() % 3;
}

// Function for moving the vampire on the grid
void Vampire::move(Grid *grid, char input) // override
{
  if (this->get_health() <= 0)
  {
    return;
  }
  // Randomly choose a direction for the vampire to move
  int dx = rand() % 3 - 1; // -1, 0, or 1
  int dy = rand() % 3 - 1; // -1, 0, or 1

  // Calculate the new position of the vampire
  int x = this->the_x + dx;
  int y = this->the_y + dy;

  // Check if the new position is within the bounds of the grid
  if (x >= 0 && x < grid->get_length() && y >= 0 && y < grid->get_height())
  {
    // Check if the new position is passable
    if (grid->map[y][x].identity == ground)
    {
      grid->set_identity(get_y(), get_x(), ground);
      grid->set_identity(y, x, vampire);
      // Update the vampire's position
      set_x(x);
      set_y(y);
    }
  }
  heal_or_attack(grid);
}

// Function for moving the vampire on the grid
void Vampire::retreat(Grid *grid, char input) // override
{
  if (this->get_health() <= 0)
  {
    return;
  }
  // Randomly choose a direction for the vampire to move
  int dx = rand() % 3 - 1; // -1, 0, or 1
  int dy = rand() % 3 - 1; // -1, 0, or 1

  // Calculate the new position of the vampire
  int x = this->the_x + dx;
  int y = this->the_y + dy;

  // Check if the new position is within the bounds of the grid
  if (x >= 0 && x < grid->get_length() && y >= 0 && y < grid->get_height())
  {
    // Check if the new position is passable
    if (grid->map[y][x].identity == ground)
    {
      grid->set_identity(get_y(), get_x(), ground);
      grid->set_identity(y, x, vampire);
      // Update the vampire's position
      set_x(x);
      set_y(y);
    }
  }
}

// Setters
void Vampire::set_x(int x)
{
  this->the_x = x;
}
void Vampire::set_y(int y)
{
  this->the_y = y;
}

// Getters for the vampire's position
int Vampire::get_x() const { return this->the_x; }
int Vampire::get_y() const { return this->the_y; }

// Getter and setter for the vampire's potions

int Vampire::get_v_healing_potions() const
{
  return healing_potions;
}

void Vampire::set_healing_potions(int potions)
{
  healing_potions = potions;
}

// Vampire for interactions
void Vampire::heal_or_attack(Grid *grid)
{
  Vampire *other;
  Vampire **v_array = grid->get_v_array();

  Werewolf *target;
  Werewolf **w_array = grid->get_w_array();

  // HEAL
  for (int i = 0; i < grid->get_number_of_team_members(); i++)
  {
    other = v_array[i];

    // If its the same continue
    if (other->get_x() == this->get_x() && other->get_y() == this->get_y())
    {
      continue;
    }

    // If the other is dead, continue
    if (other->get_health() <= 0)
    {
      continue;
    }

    // Check if other is close
    if (abs(the_x - other->get_x()) <= 1 && abs(the_y - other->get_y()) <= 1)
    {
      // Check if other werewolf is not at full health and this werewolf has potions
      if (other->get_health() < 5 && healing_potions > 0)
      {
        // Randomly decide whether to use a potion
        if (rand() % 2 == 0)
        {
          // Use a potion and update the number of potions remaining
          other->set_health(other->get_health() + 1);
          set_healing_potions(healing_potions - 1);
        }
      }
    }
  }

  // ATTACK
  for (int i = 0; i < grid->get_number_of_team_members(); i++)
  {
    int damage;
    target = w_array[i];

    // If the target is dead, continue
    if (target->get_health() <= 0)
    {
      continue;
    }

    // Check if target is close
    if (abs(the_x - target->get_x()) <= 1 && abs(the_y - target->get_y()) <= 1)
    {
      // Check if target has less health
      if (target->get_attack() <= target->get_attack())
      {
        damage = this->get_attack() - target->get_defense();
        if (damage > 0)
        {
          target->set_health(target->get_health() - damage);
        }

        if (target->get_health() <= 0)
        {
          grid->set_identity(target->get_y(), target->get_x(), ground);
        }
      }
      else
      {
        this->move(grid, (char)40);
      }
    }
  }
}
