#include <conio.h> // For getch() function

void updateGameState() 
{
  // Update the game state here
}

void drawGame(const Grid& grid, const Avatar& avatar) 
{
  // Clear the screen
  clrscr();

  // Draw the grid
  for (int y = 0; y < grid.getHeight(); y++) {
    for (int x = 0; x < grid.getWidth(); x++) {
      const Tile& tile = grid.getTile(x, y);

      // Draw the tile
      if (tile.isTransparent()) {
        putchar('.');
      } else {
        putchar('#');
      }
    }

    putchar('\n');
  }

  // Draw the avatar
  gotoxy(avatar.getX(), avatar.getY());
  putchar('@');

  // Refresh the screen
  refresh();
}


int main() 
{
  // Create a grid
  Grid grid(10, 10);

  // Create an avatar
  Avatar avatar(100, 2, 1);

  // Set the initial position of the avatar on the grid
  avatar.move(grid, 0, 0);

  // Main game loop
  while (true) 
  {
    // Get the input from the keyboard
    int key = getch();

    // Process the input
    int dx = 0, dy = 0;
    if (key == KEY_UP) dy = -1;
    else if (key == KEY_DOWN) dy = 1;
    else if (key == KEY_LEFT) dx = -1;
    else if (key == KEY_RIGHT) dx = 1;

    // Move the avatar on the grid
    avatar.move(grid, dx, dy);

    // Update the game state
    updateGameState();

    // Draw the game
    drawGame(grid, avatar);
  }

  return 0;
}