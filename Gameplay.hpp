#include "Avatar.hpp"
//#include "Werewolf.hpp"
//#include "Vampire.hpp"

int input_height();
int input_length();
char pick_side();

Grid create_board(int height, int length);

Avatar create_player();
Werewolf create_werewolf();
Vampire create_vampire();
void fill_mob_arrays(int number_of_team_members, Werewolf* w_array, Vampire* v_array);
void set_coordinates(Grid& board, Werewolf* w_array, Vampire* v_array, int height, int length);
void play(Avatar player, Grid& board, Werewolf* w_array, Vampire* v_array, int number_of_team_members);
int check_for_neighboring_werewolf(Grid& board, Werewolf* w_array, int number_of_team_members, int x, int y);
int check_for_neighboring_vampire(Grid& board, Vampire* v_array, int number_of_team_members, int x, int y);