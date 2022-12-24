#include <iostream>
#include "Gameplay.hpp"
using namespace std;

//Function that checks for valid height input (number within the boundaries set). Loops until correct input is given.
int input_height()
{
    int height;
    string input;
    int correct_input = 0;
    bool is_numeric;
    while (correct_input == 0)
    {
        cout << "Input height:";
        cin >> input;
        is_numeric = true;
        for (long unsigned int i = 0; i < input.length(); i++)          //long unsigned int because its used in stoi.
        {
            if (input[i] < '0' || input[i] > '9')
            {
                is_numeric = false;
                cout << "Invalid height, enter a number between 5 and 50." << endl
                     << endl;
                break;
            }
        }
        if (is_numeric == true)
        {
            height = stoi(input);
            if (height >= 5 && height <= 50)
                correct_input = 1;
            else
            {
                cout << "Invalid height, enter a number between 5 and 50." << endl
                     << endl;
            }
        }
    }
    return height;
}

//Function that checks for valid length input (number within the boundaries set). Loops until correct input is given.
int input_length()
{
    int length;
    string input;
    int correct_input = 0;
    bool is_numeric;
    while (correct_input == 0)
    {
        cout << "Input length:";
        cin >> input;
        is_numeric = true;
        for (long unsigned int i = 0; i < input.length(); i++)          //long unsigned int because its used in stoi.
        {
            if (input[i] < '0' || input[i] > '9')
            {
                is_numeric = false;
                cout << "Invalid length, enter a number between 5 and 50." << endl
                     << endl;
                break;
            }
        }
        if (is_numeric == true)
        {
            length = stoi(input);
            if (length >= 5 && length <= 50)
                correct_input = 1;
            else
            {
                cout << "Invalid length, enter a number between 5 and 50." << endl
                     << endl;
            }
        }
    }
    return length;
}

//Function that checks for correct side selection input (w or W for werewolves' team, v or V for vampires' team)
char pick_side()
{
    int correct_input = 0;
    char input;
    while (correct_input == 0)
    {
        cout << "Pick a side" << endl;
        cout << "Press 'w' to join the ferocious werewolf army or press 'v' if you are goth." << endl;
        cin >> input;
        cout << endl;
        switch (input)
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
        if (correct_input == 0)
            cout << "Incorrect input! ";
    }
    return input;
}

//Function to create a game's board (Grid object) and a pointer to it.
Grid *create_board(int in_height, int in_length, int number_of_team_members, Werewolf **w_array, Vampire **v_array)
{
    Grid *temp_board = new Grid(in_height, in_length, number_of_team_members, w_array, v_array);
    temp_board->rand_in_board();
    return temp_board;
}

//Function to create an Avatar object and a pointer to it
Avatar *create_player(char side)
{
    Avatar *temp_player = new Avatar(5, side);
    return temp_player;
}

//Fill the two pointers of team arrays with objects
void fill_mob_arrays(int number_of_team_members, Werewolf **w_array, Vampire **v_array)
{

    for (int i = 0; i < number_of_team_members; i++)
    {
        w_array[i] = new Werewolf(5);
        v_array[i] = new Vampire(5);
    }
}

//Some tiles of grid are enumerated to vampire and werewolf respectively, this function assigns each of those tiles to the created objects.
void set_coordinates(Grid *board, Werewolf **w_array, Vampire **v_array, int height, int length)
{
    int werewolf_index = 0;
    int vampire_index = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < length; j++)
        {
            if (board->map[i][j].identity == werewolf && board->map[i][j].picked == 0)
            {
                w_array[werewolf_index]->set_x(j);
                w_array[werewolf_index]->set_y(i);
                board->map[i][j].picked = 1;
                werewolf_index++;
            }
            else if (board->map[i][j].identity == vampire && board->map[i][j].picked == 0)
            {
                v_array[vampire_index]->set_x(j);
                v_array[vampire_index]->set_y(i);
                board->map[i][j].picked = 1;
                vampire_index++;
            }
        }
}

//Function that plays the game. Player inputs a move, function creates moves/attacks/heals for all mobs.
void play(Avatar *player, Grid *board, Werewolf **w_array, Vampire **v_array, int number_of_team_members)
{
    bool game_over = false;
    int game_paused = 0;
    char input;
    int first_move = 1;
    while (!game_over)
    {
        if (game_paused == 0 || first_move == 1)
        {
            first_move = 0;
            cout<<endl;
            board->print();
        }
        else
        {
            cout << " # GAME PAUSED #" << endl
                 << endl;
            cout << "Werewolf alliance of the oppressed warriors left: " << count_werewolves(board) << endl;
            cout << "Pale edgy people with black make-up left: " << count_vampires(board) << endl;
            if (board->get_is_night())
            {
                cout << "It is night" << endl;
            }
            else
            {
                cout << "It is day" << endl;
            }
            cout<<"Controls:"<<endl<<"press 'w' to go up"<<endl<<"press 's' to go down"<<endl<<"press 'a' to go left"<<endl<<"press 'd' to go right"<<endl<<"press 'u' to use magic potion"<<endl;
            cout << "press 'p' to resume" << endl;
        }
        cin >> input;
        cout << "\n";
        if (input == 'p')
        {
            if (game_paused == 0)
                game_paused = 1;
            else
                game_paused = 0;
        }
        else if (input == 'u' || input == 'w' || input == 'a' || input == 's' || input == 'd' || input == 'u')
        {
            player->move(board, input);
            for (int i = 0; i < number_of_team_members; i++)
            {
                w_array[i]->move(board, input);
            }

            for (int i = 0; i < number_of_team_members; i++)
            {
                v_array[i]->move(board, input);
            }

            board->rotate_is_night();

            if (check_win(board) == vampire)
            {
                cout << "Vampires WIN!\n";
                game_over = true;
            }
            else if (check_win(board) == werewolf)
            {
                cout << "Werewolves WIN!\n";
                game_over = true;
            }
        }
        else
        {
            cout << "INVALID INPUT, PRESS 'p' for controls" << endl;
        }
    }
}

//Check for win. If one of two teams is defeated(has 0 members)
int check_win(Grid *board)
{
    int vampire_counter = count_vampires(board);
    int werewolf_counter = count_werewolves(board);

    if (vampire_counter == 0)
    {
        return werewolf;
    }

    if (werewolf_counter == 0)
    {
        return vampire;
    }

    return 0;
}

//count remaining vampires
int count_vampires(Grid *board)
{
    Vampire **v_array = board->get_v_array();
    int vampire_counter = 0;

    int number_of_team_members = board->get_number_of_team_members();

    for (int i = 0; i < number_of_team_members; i++)
    {
        if (v_array[i]->get_health() > 0)
        {
            vampire_counter++;
        }
    }

    return vampire_counter++;
}

//count remaining werewolves
int count_werewolves(Grid *board)
{
    Werewolf **w_array = board->get_w_array();
    int werewolf_counter = 0;

    int number_of_team_members = board->get_number_of_team_members();

    for (int i = 0; i < number_of_team_members; i++)
    {
        if (w_array[i]->get_health() > 0)
        {
            werewolf_counter++;
        }
    }

    return werewolf_counter;
}