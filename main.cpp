#include <iostream>
//#include "Grid.hpp"
//#include "Avatar.hpp"
#include "Gameplay.hpp"
using namespace std;

int main()
{
    int height = input_height();
    int length = input_length();
    char side = pick_side();
    Grid map = create_board(height, length);
    Avatar player = create_player();
    Werewolf* W_team = new Werewolf[(height*length)/15];
    Vampire* V_team = new Vampire[(height*length)/15];
    fill_mob_arrays((height*length)/15, W_team, V_team);
    set_coordinates(map, W_team, V_team, height, length);
    for(int i = 0 ; i < (height*length)/15 ; i++)
    {
        cout<<"Wolf# "<<i<<"x: "<<W_team[i].get_x()<<" y: "<<W_team[i].get_y()<<endl;
        //cout<<"Vamp# "<<i<<"x: "<<V_team[i].get_x()<<" y: "<<V_team[i].get_y()<<endl;
        //cout<<"#"<<i<<"pots: "<<W_team[i].get_w_healing_potions()<<endl;
    }
    play(player, map, W_team, V_team, (height*length)/15);
    
    return 0;
}