#include "Grid.hpp"

using namespace std;

// Constructor
Grid::Grid(int in_height, int in_length, int number_of_team_members, Werewolf **w_array, Vampire **v_array)
{
    int i, j;
    is_night = false;
    this->number_of_team_members = number_of_team_members;
    this->w_array = w_array;
    this->v_array = v_array;
    height = in_height;
    length = in_length;
    map = new Tile *[height];
    if (!map)
        cout << "Error allocating memory!";
    for (i = 0; i < height; i++)
    {
        map[i] = new Tile[height];
        if (!map[i])
            cout << "Error allocating memory!";
    }

    for (i = 0; i < height; i++)
        for (j = 0; j < length; j++)
            map[i][j].identity = ground;

    return;
}

// Destructor
Grid::~Grid()
{
    for (int i = 0; i < height; i++)
        delete[] map[i];
    delete[] map;
}

bool Grid::get_is_night()
{
    return this->is_night;
}
void Grid::rotate_is_night()
{
    if (this->is_night)
    {
        this->is_night = false;
    }
    else
    {
        this->is_night = true;
    }
}
//randomizing board. First inserting trees, then water, then potion, then mobs, then player.
void Grid::rand_in_board()
{
    srand(time(NULL));
    int valid;
    int candidate_h;
    int candidate_l;
    //trees
    for (int i = 0; i <= (height * length) / 15; i++)
    {
        valid = 0;
        while (valid == 0)
        {
            candidate_h = rand() % height;
            candidate_l = rand() % length;
            if (map[candidate_h][candidate_l].identity == ground)
            {
                map[candidate_h][candidate_l].identity = tree;
                valid = 1;
            }
        }
    }
    //water
    for (int i = 0; i <= (height * length) / 15; i++)
    {
        valid = 0;
        while (valid == 0)
        {
            candidate_h = rand() % height;
            candidate_l = rand() % length;
            if (map[candidate_h][candidate_l].identity == ground)
            {
                map[candidate_h][candidate_l].identity = water_body;
                valid = 1;
            }
        }
    }
    //potion
    valid = 0;
    while (valid == 0)
    {
        candidate_h = rand() % height;
        candidate_l = rand() % length;
        if (map[candidate_h][candidate_l].identity == ground)
        {
            map[candidate_h][candidate_l].identity = potion;
            valid = 1;
        }
    }
    //vampire
    for (int i = 0; i < (height * length) / 15; i++)
    {
        valid = 0;
        while (valid == 0)
        {
            candidate_h = rand() % height;
            candidate_l = rand() % length;
            if (map[candidate_h][candidate_l].identity == ground)
            {
                map[candidate_h][candidate_l].identity = vampire;
                valid = 1;
            }
        }
    }
    //werewolf
    for (int i = 0; i < (height * length) / 15; i++)
    {
        valid = 0;
        while (valid == 0)
        {
            candidate_h = rand() % height;
            candidate_l = rand() % length;
            if (map[candidate_h][candidate_l].identity == ground)
            {
                map[candidate_h][candidate_l].identity = werewolf;
                valid = 1;
            }
        }
    }
    //player
    valid = 0;
    while (valid == 0)
    {
        candidate_h = rand() % height;
        candidate_l = rand() % length;
        if (map[candidate_h][candidate_l].identity == ground)
        {
            map[candidate_h][candidate_l].identity = player_avatar;
            valid = 1;
        }
    }
}
//getter for number of team members of each faction
int Grid::get_number_of_team_members()
{
    return number_of_team_members;
}
//getter for werewolf array
Werewolf **Grid::get_w_array()
{
    return w_array;
}
//getter for vampire array
Vampire **Grid::get_v_array()
{
    return v_array;
}

// Function to alter current identiy of a tile given it's coordinates
void Grid::set_identity(int x, int y, en_identity k)
{
    map[x][y].identity = k;
    return;
}

// Function to print the current identity of a tile given it's coordinates
int Grid::get_identity(int x, int y)
{
    return map[x][y].identity;
}
//getter for x dimension of player in the matrix
int Grid::get_player_x(void)
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < length; j++)
            if (map[i][j].identity == player_avatar)
                return j;
    return 0;
}
//getter for y dimension of player in the matrix
int Grid::get_player_y(void)
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < length; j++)
            if (map[i][j].identity == player_avatar)
                return i;
    return 0;
}
//getter for board height
int Grid::get_height()
{
    return height;
}
//getter for board length
int Grid::get_length()
{
    return length;
}

// Function to print the map using ASCII art(kinda)
void Grid::print()
{
    cout<<endl;
    for (int i = 0; i < height; i++)
    {
        cout << "|";
        for (int j = 0; j < length; j++)
        {
            if (j == length - 1)
            {
                cout << "---";
                break;
            }
            cout << "----";
        }
        cout << "|";
        cout << endl
             << "|";
        for (int j = 0; j < length; j++)
            switch (map[i][j].identity)
            {
            case 0:
                cout << "   |";
                break;
            case 1:
                cout << " T |";
                break;
            case 2:
                cout << " L |";
                break;
            case 3:
                cout << " @ |";
                break;
            case 4:
                cout << " V |";
                break;
            case 5:
                cout << " W |";
                break;
            case 6:
                cout << " P |";
                break;
            }
        cout << endl;
    }
    cout << "|";
    for (int j = 0; j < length; j++)
    {
        if (j == length - 1)
        {
            cout << "---";
            break;
        }
        cout << "----";
    }
    cout << "|" << endl
         << "|";
}