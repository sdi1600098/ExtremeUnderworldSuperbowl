#include <iostream>
#include "Gameplay.hpp"
using namespace std;

int input_height()
{
    int height;
    int correct_input = 0;
    while(correct_input == 0)
    {
        cout<<"Input height:";          
        cin>>height;
        if(height >= 5 && height <= 100)
            correct_input = 1;  
        else
        {
            cout<<"Invalid height, enter a number between 5 and 100."<<endl<<endl;
        }                
    }
    return height;

}

int input_length()
{
    int length;
    int correct_input = 0;
    while(correct_input == 0)
    {
        cout<<"Input length:";          
        cin>>length;
        if(length >= 5 && length <= 100)
            correct_input = 1;  
        else
        {
            cout<<"Invalid length, enter a number between 5 and 100."<<endl<<endl;
        }                
    }
    return length;

}

char pick_side()
{
    int correct_input = 0;
    char input;
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
    return input;

}

Grid create_board(int height, int length)
{
    Grid temp_board(height, length);
    temp_board.rand_in_board();
    return temp_board;
}

Avatar create_player()
{
    Avatar temp_player(5);
    return temp_player;
}

Werewolf create_werewolf()
{
    Werewolf temp_werewolf(5);
    return temp_werewolf;
}

/*Vampire create_vampire()
{
    Vampire temp_vampire(5);
    return temp_vampire;
}*/

void fill_mob_arrays(int number_of_team_members, Werewolf* w_array)
{
    for(int i = 0 ; i < number_of_team_members ; i++)
    {
        
        w_array[i] = create_werewolf();
        //v_array[i] = create_vampire();
    }
}