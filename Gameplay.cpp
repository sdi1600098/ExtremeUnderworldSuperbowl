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

void pick_side(Avatar& player)
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
    player.set_side(input);

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
    return;
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
        move_werewolves(board, w_array, v_array, number_of_team_members, input);
        move_vampires(board, w_array, v_array, number_of_team_members, input);
        game_over = check_for_game_over(w_array, v_array, number_of_team_members);
    }
    
}

void move_werewolves(Grid& board, Werewolf* w_array, Vampire* v_array, int number_of_team_members, char input)
{
    for(int i = 0 ; i < number_of_team_members ; i++)
    {   
        if(w_array[i].get_health() > 0)
        {
            int im_moving = 1;
            int x = w_array[i].get_x();
            int y = w_array[i].get_y();
            if(y > 0)
            {
                int w1 = check_for_neighboring_werewolf(board, w_array, number_of_team_members, x, y - 1);
                if(w1 > -1)
                {
                    cout<<"O APO PANW: "<<w_array[w1].get_x()<<", "<<w_array[w1].get_y()<<endl;
                    if(w_array[w1].get_health() < 5 && rand() % 2 == 1)
                    {
                        cout<<"HEALED"<<endl;
                        im_moving = 0;
                    }
                }
                else
                {
                    int v1 = check_for_neighboring_vampire(board, v_array, number_of_team_members, x, y - 1);
                    if(v1 > -1)
                    {
                        cout<<"O APO PANW VAMPIRE: "<<v_array[v1].get_x()<<", "<<v_array[v1].get_y()<<endl;
                        if(w_array[i].get_attack() >= v_array[v1].get_attack())
                        {
                            v_array[v1].defend(w_array[i].get_attack());
                            if(v_array[v1].get_health() <= 0)
                            {
                                board.map[v_array[v1].get_y()][v_array[v1].get_x()].identity = ground;
                            }
                            
                            im_moving = 0;
                        }
                       // else
                            //cout<<"ME ATK = "<<v_array[v1].get_attack()<<endl;
                    }
                }
            }
            if(y + 1 < board.get_height() && im_moving == 1)
            {
                int w2 = check_for_neighboring_werewolf(board, w_array, number_of_team_members, x, y + 1);
                if(w2 > -1)
                {
                    cout<<"O APO KATW: "<<w_array[w2].get_x()<<", "<<w_array[w2].get_y()<<endl;
                    if(w_array[w2].get_health() < 5 && rand() % 2 == 1)
                    {
                        cout<<"HEALED"<<endl;
                        im_moving = 0;
                    }
                }
                else
                {
                    int v2 = check_for_neighboring_vampire(board, v_array, number_of_team_members, x, y + 1);
                    if(v2 > -1)
                    {
                        cout<<"O APO KATW VAMPIRE: "<<v_array[v2].get_x()<<", "<<v_array[v2].get_y()<<endl;
                        if(w_array[i].get_attack() >= v_array[v2].get_attack())
                        {
                            v_array[v2].defend(w_array[i].get_attack());
                            if(v_array[v2].get_health() <= 0)
                            {
                                board.map[v_array[v2].get_y()][v_array[v2].get_x()].identity = ground;
                            }
                            
                            im_moving = 0;
                        }
                        //else
                           // cout<<"ME ATK = "<<v_array[v2].get_attack()<<endl;
                    }
                }
            }
            if(x > 0 && im_moving == 1)
            {
                int w3 = check_for_neighboring_werewolf(board, w_array, number_of_team_members, x - 1, y);
                if(w3 > -1)
                {
                    cout<<"O APO ARISTERA: "<<w_array[w3].get_x()<<", "<<w_array[w3].get_y()<<endl;
                    if(w_array[w3].get_health() < 5 && rand() % 2 == 1)
                    {
                        cout<<"HEALED"<<endl;
                        im_moving = 0;
                    }
                }
                else
                {
                    int v3 = check_for_neighboring_vampire(board, v_array, number_of_team_members, x - 1, y);
                    if(v3 > -1)
                    {
                        cout<<"O APO ARISTERA VAMPIRE: "<<v_array[v3].get_x()<<", "<<v_array[v3].get_y()<<endl;
                        if(w_array[i].get_attack() >= v_array[v3].get_attack())
                        {
                            v_array[v3].defend(w_array[i].get_attack());
                            if(v_array[v3].get_health() <= 0)
                            {
                                board.map[v_array[v3].get_y()][v_array[v3].get_x()].identity = ground;
                            }
                        
                            im_moving = 0;
                        }
                        //else
                           // cout<<"ME ATK = "<<v_array[v3].get_attack()<<endl;
                    }
                }
            }
            if(x + 1 < board.get_length() && im_moving == 1)
            {
                int w4 = check_for_neighboring_werewolf(board, w_array, number_of_team_members, x + 1, y);
                if(w4 > -1)
                {
                    cout<<"O APO DEKSIA: "<<w_array[w4].get_x()<<", "<<w_array[w4].get_y()<<endl;
                    if(w_array[w4].get_health() < 5 && rand() % 2 == 1)
                    {
                        cout<<"HEALED"<<endl;
                        im_moving = 0;
                    }
                }
                else
                {
                    int v4 = check_for_neighboring_vampire(board, v_array, number_of_team_members, x + 1, y);
                    if(v4 > -1)
                    {
                        cout<<"O APO DEKSIA VAMPIRE: "<<v_array[v4].get_x()<<", "<<v_array[v4].get_y()<<endl;
                        if(w_array[i].get_attack() >= v_array[v4].get_attack())
                        {
                            v_array[v4].defend(w_array[i].get_attack());
                            if(v_array[v4].get_health() <= 0)
                            {
                                board.map[v_array[v4].get_y()][v_array[v4].get_x()].identity = ground;
                            }
                            im_moving = 0;
                        }
                        //else
                           // cout<<"ME ATK = "<<v_array[v4].get_attack()<<endl;
                    }
                }
            }
            if(im_moving == 1)
                w_array[i].move(board, input);
        }
        //cout<<"EPAIKSE O "<<i<<endl;
        //board.print();
    }
}

void move_vampires(Grid& board, Werewolf* w_array, Vampire* v_array, int number_of_team_members, char input)
{
    for(int i = 0 ; i < number_of_team_members ; i++)
    {   
        if(v_array[i].get_health() > 0)
        {
            int im_moving = 1;
            int x = v_array[i].get_x();
            int y = v_array[i].get_y();
            if(y > 0)
            {
                int v1 = check_for_neighboring_vampire(board, v_array, number_of_team_members, x, y - 1);
                if(v1 > -1)
                {
                    cout<<"O APO PANW: "<<v_array[v1].get_x()<<", "<<v_array[v1].get_y()<<endl;
                    if(v_array[v1].get_health() < 5 && rand() % 2 == 1)
                    {
                        cout<<"HEALED"<<endl;
                        im_moving = 0;
                    }
                }
                else
                {
                    int w1 = check_for_neighboring_werewolf(board, w_array, number_of_team_members, x, y - 1);
                    if(w1 > -1)
                    {
                        cout<<"O APO PANW LYKOS: "<<w_array[w1].get_x()<<", "<<w_array[w1].get_y()<<endl;
                        if(v_array[i].get_attack() >= w_array[w1].get_attack())
                        {
                            w_array[w1].defend(v_array[i].get_attack());
                            if(w_array[w1].get_health() <= 0)
                            {
                                board.map[w_array[w1].get_y()][w_array[w1].get_x()].identity = ground;
                            }
                            
                            im_moving = 0;
                        }
                       // else
                            //cout<<"ME ATK = "<<v_array[v1].get_attack()<<endl;
                    }
                }
            }
            if(y + 1 < board.get_height() && im_moving == 1)
            {
                int v2 = check_for_neighboring_vampire(board, v_array, number_of_team_members, x, y + 1);
                if(v2 > -1)
                {
                    cout<<"O APO KATW: "<<v_array[v2].get_x()<<", "<<v_array[v2].get_y()<<endl;
                    if(v_array[v2].get_health() < 5 && rand() % 2 == 1)
                    {
                        cout<<"HEALED"<<endl;
                        im_moving = 0;
                    }
                }
                else
                {
                    int w2 = check_for_neighboring_werewolf(board, w_array, number_of_team_members, x, y + 1);
                    if(w2 > -1)
                    {
                        cout<<"O APO KATW LYKOS: "<<w_array[w2].get_x()<<", "<<w_array[w2].get_y()<<endl;
                        if(v_array[i].get_attack() >= w_array[w2].get_attack())
                        {
                            w_array[w2].defend(v_array[i].get_attack());
                            if(w_array[w2].get_health() <= 0)
                            {
                                board.map[w_array[w2].get_y()][w_array[w2].get_x()].identity = ground;
                            }
                            
                            im_moving = 0;
                        }
                        //else
                           // cout<<"ME ATK = "<<v_array[v2].get_attack()<<endl;
                    }
                }
            }
            if(x > 0 && im_moving == 1)
            {
                int v3 = check_for_neighboring_vampire(board, v_array, number_of_team_members, x - 1, y);
                if(v3 > -1)
                {
                    cout<<"O APO ARISTERA: "<<v_array[v3].get_x()<<", "<<v_array[v3].get_y()<<endl;
                    if(v_array[v3].get_health() < 5 && rand() % 2 == 1)
                    {
                        cout<<"HEALED"<<endl;
                        im_moving = 0;
                    }
                }
                else
                {
                    int w3 = check_for_neighboring_werewolf(board, w_array, number_of_team_members, x - 1, y);
                    if(w3 > -1)
                    {
                        cout<<"O APO ARISTERA LYKOS: "<<w_array[w3].get_x()<<", "<<w_array[w3].get_y()<<endl;
                        if(v_array[i].get_attack() >= w_array[w3].get_attack())
                        {
                            w_array[w3].defend(v_array[i].get_attack());
                            if(w_array[w3].get_health() <= 0)
                            {
                                board.map[w_array[w3].get_y()][w_array[w3].get_x()].identity = ground;
                            }
                        
                            im_moving = 0;
                        }
                        //else
                           // cout<<"ME ATK = "<<v_array[v3].get_attack()<<endl;
                    }
                }
            }
            if(x + 1 < board.get_length() && im_moving == 1)
            {
                int v4 = check_for_neighboring_vampire(board, v_array, number_of_team_members, x + 1, y);
                if(v4 > -1)
                {
                    cout<<"O APO DEKSIA: "<<v_array[v4].get_x()<<", "<<v_array[v4].get_y()<<endl;
                    if(v_array[v4].get_health() < 5 && rand() % 2 == 1)
                    {
                        cout<<"HEALED"<<endl;
                        im_moving = 0;
                    }
                }
                else
                {
                    int w4 = check_for_neighboring_werewolf(board, w_array, number_of_team_members, x + 1, y);
                    if(w4 > -1)
                    {
                        cout<<"O APO DEKSIA VAMPIRE: "<<w_array[w4].get_x()<<", "<<w_array[w4].get_y()<<endl;
                        if(v_array[i].get_attack() >= w_array[w4].get_attack())
                        {
                            w_array[w4].defend(v_array[i].get_attack());
                            if(w_array[w4].get_health() >= 0)
                            {
                                board.map[w_array[w4].get_y()][w_array[w4].get_x()].identity = ground;
                            }
                            im_moving = 0;
                        }
                        //else
                           // cout<<"ME ATK = "<<v_array[v4].get_attack()<<endl;
                    }
                }
            }
            if(im_moving == 1)
                v_array[i].move(board, input);
        }
        //cout<<"EPAIKSE O "<<i<<endl;
        //board.print();
    }
}

int check_for_neighboring_werewolf(Grid& board, Werewolf* w_array, int number_of_team_members, int x, int y)
{
    int ii = -1;
    if(board.map[y][x].identity == werewolf)
    {
        for(ii = 0 ; ii < number_of_team_members ; ii++)
        {
            if(w_array[ii].get_x() == x && w_array[ii].get_y() == y)
                break;
        }
                    
    }
    return ii;
}

int check_for_neighboring_vampire(Grid& board, Vampire* v_array, int number_of_team_members, int x, int y)
{
    int ii = -1;
    if(board.map[y][x].identity == vampire)
    {
        for(ii = 0 ; ii < number_of_team_members ; ii++)
        {
            if(v_array[ii].get_x() == x && v_array[ii].get_y() == y)
                break;
        }
                    
    }
    return ii;
}

int check_for_game_over(Werewolf* w_array, Vampire* v_array, int number_of_team_members)
{   
    int werewolves_still_standing = 0;
    int vampires_still_standing = 0;
    int game_over = 0;
    for(int i = 0 ; i < number_of_team_members ; i++)
    {   cout<<w_array[i].get_health()<<", "<<v_array[i].get_health()<<endl;
        if(w_array[i].get_health() > 0)
        {
            werewolves_still_standing = 1;

        }
        if(v_array[i].get_health() > 0)
        {
            vampires_still_standing = 1;
        }
    }
    if(werewolves_still_standing == 0)
    {
        cout<<"# VAMPIRES WIN #"<<endl;
        game_over = 1;
    }
    else if(vampires_still_standing == 0)
    {
        cout<<"# WEREWOLVES WIN #"<<endl;
        game_over = 1;
    }
    return game_over;
}