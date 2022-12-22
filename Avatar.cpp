#include <iostream>
#include "Avatar.hpp"
using namespace std;


// Constructor
Avatar::Avatar(int health): Entity(health) 
{
  magic_potions = 1;
}

// Overridden defend function
void Avatar::defend(int damage) //override 
{
  // Reduce the damage taken based on the avatar's defense
  damage -= the_defense;
  if (damage < 0) damage = 0;

  // Update the avatar's health
  the_health -= damage;
}

// Overridden attack function
void Avatar::attack(Entity& target) //override 
{
  // Deal damage to the target based on the avatar's attack
  target.defend(the_attack);
}

// Function for moving the avatar on the grid
void Avatar::move(Grid& grid, char input) //override
{
    // Get the current position of the avatar
    int x = grid.get_player_x();
    int y = grid.get_player_y();
    cout<<input;
    // Update the position of the avatar based on the input
    switch(input)
    {
        case 'w' :
            if(y > 0 && (grid.map[y - 1][x].identity == ground || grid.map[y - 1][x].identity == potion))
            {   
                if(grid.map[y - 1][x].identity == potion)
                {
                    set_magic_potions(get_magic_potions() + 1);
                }
                // Update the avatar's position on the grid
                grid.set_identity(y, x, ground);
                grid.set_identity(y - 1, x, player_avatar);

                // Update the avatar's position variables
                the_x = x;
                the_y = y - 1;
            }
            break;

        case 'a' :
            if(x > 0 && (grid.map[y][x - 1].identity == ground || grid.map[y][x - 1].identity == potion))
            {
                if(grid.map[y][x - 1].identity == potion)
                {
                    set_magic_potions(get_magic_potions() + 1);
                }
                // Update the avatar's position on the grid
                grid.set_identity(y, x, ground);
                grid.set_identity(y, x - 1, player_avatar);

                // Update the avatar's position variables
                the_x = x - 1;
                the_y = y;
            }
            break;

        case 's' :
            if(y < grid.get_height() - 1 && (grid.map[y + 1][x].identity == ground || grid.map[y + 1][x].identity == potion))
            {
                if(grid.map[y + 1][x].identity == potion)
                {
                    set_magic_potions(get_magic_potions() + 1);
                }
                // Update the avatar's position on the grid
                grid.set_identity(y, x, ground);
                grid.set_identity(y + 1, x, player_avatar);

                // Update the avatar's position variables
                the_x = x;
                the_y = y + 1;
            }
            break;

        case 'd' :
            if(x < grid.get_length() - 1 && (grid.map[y][x + 1].identity == ground || grid.map[y][x + 1].identity == potion))
            {
                if(grid.map[y][x + 1].identity == potion)
                {
                    set_magic_potions(get_magic_potions() + 1);
                }
                // Update the avatar's position on the grid
                grid.set_identity(y, x, ground);
                grid.set_identity(y, x + 1, player_avatar);

                // Update the avatar's position variables
                the_x = x + 1;
                the_y = y;
            }
            break;
        case 'p' :
            break;

        case 'u' :
            //use magic pot
            break;
            
        default:
            cout<<"INVALID INPUT, PRESS 'p' for controls"<<endl<<endl;
            break;
    }
    
}    

// Getters for the avatar's position
int Avatar::get_x() const { return the_x; }
int Avatar::get_y() const { return the_y; }

int Avatar::get_magic_potions() const 
{
  return magic_potions;
}

void Avatar::set_magic_potions(int potions) 
{
  magic_potions = potions;
}

// Function for using a magic potion
void Avatar::use_magic_potion(char side,int number_of_team_members, Werewolf* w_array, Vampire* v_array)
{
    // Check if the avatar has any magic potions remaining
    if (get_magic_potions() > 0)
    {
        // Check if the avatar is team werewolves or team vampires.
        // Then, check if it is day or night.
        if (side == 'w' || side == 'W') // && it is night
        {            
            set_magic_potions(get_magic_potions() - 1); // Decrement the number of magic potions remaining
            // Restore every werewolf to full health
            for (int i = 0; i < number_of_team_members; i++)
            {
                w_array[i].set_health(5);  
            }
        }
        else if (side == 'v' || side == 'V') // && it is day
        {
            set_magic_potions(get_magic_potions() - 1); // Decrement the number of magic potions remaining
            // Restore every vampire to full health
            for (int i = 0; i < number_of_team_members; i++)
            {
                v_array[i].set_health(5);  
            }
        }
    }
    else
    {
        cout << "There are no magic potions left." << endl;
    }
}

void Avatar::set_side(char s)
{
    side = s;
}

char Avatar::get_side()
{
    return side;
}



