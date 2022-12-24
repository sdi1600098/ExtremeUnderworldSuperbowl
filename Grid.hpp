#ifndef GRID
#define GRID

#include "Tile.hpp"
#include <iostream>
#include <ctime>
class Werewolf;
class Vampire;
using namespace std;

class Grid
{
    public:
        Grid(int in_height, int in_length, int number_of_team_members, Werewolf** w_array, Vampire** v_array);
        ~Grid();
        void rand_in_board();
        void set_identity(int x, int y, en_identity k);
        int get_identity(int x, int y);
        int get_player_y();
        int get_player_x();
        int get_height();
        int get_length();
        void print();
        bool get_is_night();
        void rotate_is_night();
        int get_number_of_team_members();
        Werewolf** get_w_array();
        Vampire** get_v_array();
        Tile** map;
    private:
        int height;
        int length;
        int number_of_team_members;
        Werewolf** w_array;
        Vampire** v_array;
        bool is_night;
};

#endif