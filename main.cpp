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
    Werewolf* W_team = new Werewolf(5);
    Vampire* V_team = new Vampire(5);
    fill_mob_arrays((height*length)/15, W_team, V_team);
    set_coordinates(map, W_team, V_team, height, length);
    for(int i = 0 ; i < (height*length)/15 ; i++)
    {
        cout<<"Wolf# "<<i<<"x: "<<W_team[i].get_x()<<" y: "<<W_team[i].get_y()<<endl;
        //cout<<"Vamp# "<<i<<"x: "<<V_team[i].get_x()<<" y: "<<V_team[i].get_y()<<endl;
        //cout<<"#"<<i<<"pots: "<<W_team[i].get_w_healing_potions()<<endl;
    }
    map.print();
    for(int i = 0 ; i < (height*length)/15 ; i++)
    {
        W_team[i].move(map, 'c');
        map.print();
    }
    play(player, map, W_team, V_team, (height*length)/15);

   /* int game_over = 0;
    int game_paused = 0;
    int p_y;
    int p_x;
    while(game_over == 0)
    {
        p_y = map.get_player_y();
        p_x = map.get_player_x();
        cin>>input;
        switch(input)
        {
            case 'w' :
                if(p_y != 0 && (map.map[p_y - 1][p_x].identity == ground || map.map[p_y - 1][p_x].identity == potion))
                {   
                    
                    map.set_identity(p_y, p_x, ground);
                    map.set_identity(p_y - 1, p_x, player_avatar);
                }
                break;

            case 'a' :
                if(p_x != 0)
                {
                    map.set_identity(p_y, p_x, ground);
                    map.set_identity(p_y, p_x - 1, player_avatar);
                }
                break;

            case 's' :
                if(p_y != height - 1)
                {
                    map.set_identity(p_y, p_x, ground);
                    map.set_identity(p_y + 1, p_x, player_avatar);
                }
                break;

            case 'd' :
                if(p_x != length - 1)
                {
                    map.set_identity(p_y, p_x, ground);
                    map.set_identity(p_y, p_x + 1, player_avatar);
                }
                break; 

            case 'p' :
                if(game_paused == 1)
                    game_paused = 0;
                else
                    game_paused = 1;

        }
        if(game_paused == 0)
            map.print();
        else
        {
            cout<<" # GAME PAUSED #"<<endl<<endl;
            cout<<"Werewolf alliance of the oppressed warriors left: "<<endl;
            cout<<"Pale edgy people with black make-up left: "<<endl;
            cout<<"It is day/night"<<endl<<endl;
            cout<<"press 'p' to resume"<<endl;
        }
    }*/

    return 0;
}