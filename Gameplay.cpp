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
        if(height >= 5 && height <= 50)
            correct_input = 1;  
        else
        {
            cout<<"Invalid height, enter a number between 5 and 50."<<endl<<endl;
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
        if(length >= 5 && length <= 50)
            correct_input = 1;  
        else
        {
            cout<<"Invalid length, enter a number between 5 and 50."<<endl<<endl;
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

Vampire create_vampire()
{
    Vampire temp_vampire(5);
    return temp_vampire;
}

void fill_mob_arrays(int number_of_team_members, Werewolf* w_array, Vampire* v_array)
{
    
    for(int i = 0 ; i < number_of_team_members ; i++)
    {
        w_array[i] = create_werewolf();
        v_array[i] = create_vampire();
    }
}

void set_coordinates(Grid& board, Werewolf* w_array, Vampire* v_array, int height, int length)
{
    int werewolf_index = 0;
    int vampire_index = 0;
    for(int i = 0 ; i < height ; i++)
        for(int j = 0 ; j < length ; j++)
        {
            if(board.map[i][j].identity == werewolf && board.map[i][j].picked == 0)
            {
                w_array[werewolf_index].set_x(j);
                w_array[werewolf_index].set_y(i);
                board.map[i][j].picked = 1;
                werewolf_index++;
            }
            else if(board.map[i][j].identity == vampire && board.map[i][j].picked == 0)
            {
                v_array[vampire_index].set_x(j);
                v_array[vampire_index].set_y(i);
                board.map[i][j].picked = 1;
                vampire_index++;
            }

        }
}

void play(Avatar player, Grid& board, Werewolf* w_array, Vampire* v_array, int number_of_team_members)
{
    int game_over = 0;
    int game_paused = 0;
    char input;
    int first_move = 1;
    while(game_over == 0)
    {
        if(game_paused == 0 || first_move == 1)
        {
            first_move == 0;
            board.print();
        }
        else
        {
            cout<<" # GAME PAUSED #"<<endl<<endl;
            cout<<"Werewolf alliance of the oppressed warriors left: "<<endl;
            cout<<"Pale edgy people with black make-up left: "<<endl;
            cout<<"It is day/night"<<endl<<endl;
            cout<<"press 'p' to resume"<<endl;
        }
        cin>>input;
        cout<<endl;
        if(input == 'p')
        {
            if(game_paused == 0)
                game_paused = 1;
            else    
                game_paused = 0;
        }
        player.move(board, input);
        cout<<"---------"<<w_array[5].get_x()<<"  "<<w_array[1].get_y()<<endl;
        //for(int i = 0 ; i < number_of_team_members ; i++)
        //{
            //w_array[i].move(board, input);
        //}
    }
}