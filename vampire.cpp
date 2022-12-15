#include <iostream>
#include "vampire.hpp"
using namespace std;

class Vampire : public Entity 
{
  public:
    // Constructor
    Vampire(int health)
      : Entity(health) {}

    // Overridden defend function
    void defend(int damage) override 
    {
      // Reduce the damage taken based on the vampire's defense
      damage -= the_defense;
      if (damage < 0) damage = 0;

      // Update the vampire's health
      the_health -= damage;
    }

    // Overridden attack function
    void attack(Entity& target) override 
    {
      // Deal damage to the target based on the vampire's attack
      target.defend(the_attack);
    }

    // Function for moving the vampire on the grid
    void move(Grid& grid) override
    {
      // Randomly choose a direction for the vampire to move
      int dx = rand() % 3 - 1; // -1, 0, or 1
      int dy = rand() % 3 - 1; // -1, 0, or 1

      // Calculate the new position of the vampire
      int x = the_x + dx;
      int y = the_y + dy;

      // Check if the new position is within the bounds of the grid
      if (x >= 0 && x < grid.getWidth() && y >= 0 && y < grid.getHeight()) 
      {
        // Check if the new position is passable
        const Tile& tile = grid.getTile(x, y);
        if (tile.isPassable()) 
        {
          // Update the vampire's position
          the_x = x;
          the_y = y;
        }
      }
    }

    // Getters for the vampire's position
    int getX() const { return the_x; }
    int getY() const { return the_y; }

  private:
    int the_x, the_y; // Vampire's position on the grid
};
