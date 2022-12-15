#include <iostream>
#include "werewolf.hpp"
using namespace std;

class Werewolf : public Entity 
{
  public:
    // Constructor
    Werewolf(int health)
      : Entity(health) {}

    // Overridden defend function
    void defend(int damage) override 
    {
      // Reduce the damage taken based on the werewolf's defense
      damage -= the_defense;
      if (damage < 0) damage = 0;

      // Update the werewolf's health
      the_health -= damage;
    }

    // Overridden attack function
    void attack(Entity& target) override 
    {
      // Deal damage to the target based on the werewolf's attack
      target.defend(the_attack);
    }

    // Function for moving the werewolf on the grid
    void move(Grid& grid) override
    {
      // Randomly choose a direction for the werewolf to move
      int dx = 0, dy = 0;
      int r = rand() % 4;
      if (r == 0) dx = -1;
      else if (r == 1) dx = 1;
      else if (r == 2) dy = -1;
      else if (r == 3) dy = 1;

      // Calculate the new position of the werewolf
      int x = the_x + dx;
      int y = the_y + dy;

      // Check if the new position is within the bounds of the grid
      if (x >= 0 && x < grid.getWidth() && y >= 0 && y < grid.getHeight())
      {
        // Check if the new position is passable
        const Tile& tile = grid.getTile(x, y);
        if (tile.isPassable()) 
        {
          // Update the werewolf's position
          the_x = x;
          the_y = y;
        }
      }
    }

    // Getters for the werewolf's position
    int getX() const { return the_x; }
    int getY() const { return the_y; }

  private:
    int the_x, the_y; // Werewolf's position on the grid
};
