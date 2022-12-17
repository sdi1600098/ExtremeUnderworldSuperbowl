#include <iostream>
//#include "Grid.hpp"
#include "Avatar.hpp"
using namespace std;

int main()
{
    int height, length;
    char input;
    int correct_input = 0;
    //-----Read input---------------//
    cout<<"Input height:";          
    cin>>height;                     
    cout<<endl<<"Input length:";    
    cin>>length;                     
    cout<<endl;
    while(correct_input == 0)            
    {         
        cout<<"Pick a side"<<endl;
        cout<<"Press 'w' to join the ferocious werewolf army or press 'v' if you are goth."<<endl;
        cin>>input;
        cout<<endl;
        switch(input)
        {
            case 'w':
                correct_input = 1;
            case 'v':
                correct_input = 1;
            case 'W':
                correct_input = 1;
            case 'V':
                correct_input = 1;
        }
        if(correct_input == 0)
            cout<<"Incorrect input! ";
    }
    //cout<<input;
    //------------------------------//

    //initialize map
    Grid map(height, length);
    map.rand_in_board();
    map.print();
    //-----------------------------------//
    cin>>input;
    Avatar player(5);
    player.move(map, input);





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