class Avatar : public Entity 
{
  public:
    // Constructor
    Avatar(int health, int attack, int defense)
      : Entity(health, attack, defense) {}

    // Overridden defend function
    void defend(int damage) override 
    {
      // Reduce the damage taken based on the avatar's defense
      damage -= the_defense;
      if (damage < 0) damage = 0;

      // Update the avatar's health
      the_health -= damage;
    }

    // Overridden attack function
    void attack(Entity& target) override 
    {
      // Deal damage to the target based on the avatar's attack
      target.defend(the_attack);
    }

    // Function for moving the avatar on the grid
    void move(Grid& grid, int dx, int dy) override
    {
      // Calculate the new position of the avatar
      int x = the_x + dx;
      int y = the_y + dy;

      // Check if the new position is within the bounds of the grid
      if (x >= 0 && x < grid.getWidth() && y >= 0 && y < grid.getHeight()) 
      {
        // Check if the new position is passable
        const Tile& tile = grid.getTile(x, y);
        if (tile.isPassable()) 
        {
          // Update the avatar's position
          the_x = x;
          the_y = y;
        }
      }
    }

    // Getters for the avatar's position
    int getX() const { return the_x; }
    int getY() const { return the_y; }

  private:
    int the_x, the_y; // Avatar's position on the grid
};