#include <iostream>
#include "Gameplay.hpp"
using namespace std;

int main()
{
    int height = input_height();
    int length = input_length();
    int number_of_team_members = (height * length) / 15;
    char side = pick_side();
    
    Avatar *player = new Avatar(5, side);
    Werewolf **W_team = new Werewolf *[number_of_team_members];
    Vampire **V_team = new Vampire *[number_of_team_members];
    Grid *map = create_board(height, length, number_of_team_members, W_team, V_team);

    fill_mob_arrays(number_of_team_members, W_team, V_team);
    set_coordinates(map, W_team, V_team, height, length);
    play(player, map, W_team, V_team, number_of_team_members);

    // Delete allocated blocks
    delete player;
    delete map;

    for (int i = 0; i < number_of_team_members; i++)
    {
        delete W_team[i];
        delete V_team[i];
    }
    delete[] W_team;
    delete[] V_team;

    return 0;
}