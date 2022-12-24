#ifndef GAMEPLAY
#define GAMEPLAY

#include "Grid.hpp"
#include "Avatar.hpp"

int input_height();
int input_length();
char pick_side();

Grid* create_board(int in_height, int in_length, int number_of_team_members, Werewolf** w_array, Vampire** v_array);

void fill_mob_arrays(int number_of_team_members, Werewolf** w_array, Vampire** v_array);
void set_coordinates(Grid* board, Werewolf** w_array, Vampire** v_array, int height, int length);
void play(Avatar* player, Grid* board, Werewolf** w_array, Vampire** v_array, int number_of_team_members);
int check_win(Grid* board);
int count_vampires(Grid* board);
int count_werewolves(Grid* board);

#endif