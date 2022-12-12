#include <iostream>
#include "Grid.hpp"
#include <ctime>

using namespace std;

//Constructor
Grid::Grid(int in_height, int in_length)
{
    int i, j;
    height = in_height;
    length = in_length;
    map = new Tile* [height];
    if (!map) cout<<"Error allocating memory!";
    for (i = 0; i < height ; i++)
    {
        map[i] = new Tile [height];
        if (!map[i]) cout<<"Error allocating memory!";
    }

    for (i = 0 ; i < height ; i++)
        for (j = 0 ; j < length ; j++)
            map[i][j].identity = ground;

    return;
}

//Destructor
Grid::~Grid()
{

}

void Grid::rand_in_board()
{
    srand(time(NULL));
    int valid;
    int candidate_h;
    int candidate_l;

    for (int i = 0 ; i <=(height*length)/15 ; i++)
    {

    }

    for (int i = 0 ; i <=(height*length)/15 ; i++)
    {
        valid = 0;
        while(valid == 0)
        {
            candidate_h = rand() % height;
            candidate_l = rand() % length;
            if(map[candidate_h][candidate_l].identity == ground)
            {
                map[candidate_h][candidate_l].identity = tree;
                valid = 1;
            }
        }
    }

    valid = 0;
    while(valid == 0)
    {
        candidate_h = rand() % height;
        candidate_l = rand() % length;
        if(map[candidate_h][candidate_l].identity == ground)
        {
            map[candidate_h][candidate_l].identity = potion;
            valid = 1;
        }
    }

    for (int i = 0 ; i <(height*length)/15 ; i++)
    {
        valid = 0;
        while(valid == 0)
        {
            candidate_h = rand() % height;
            candidate_l = rand() % length;
            if(map[candidate_h][candidate_l].identity == ground)
            {
                map[candidate_h][candidate_l].identity = vampire;
                valid = 1;
            }
        }
    }

    for (int i = 0 ; i <(height*length)/15 ; i++)
    {
        valid = 0;
        while(valid == 0)
        {
            candidate_h = rand() % height;
            candidate_l = rand() % length;
            if(map[candidate_h][candidate_l].identity == ground)
            {
                map[candidate_h][candidate_l].identity = werewolf;
                valid = 1;
            }
        }
    }

    valid = 0;
    while(valid == 0)
    {
        candidate_h = rand() % height;
        candidate_l = rand() % length;
        if(map[candidate_h][candidate_l].identity == ground)
        {
            map[candidate_h][candidate_l].identity = player_avatar;
            valid = 1;
        }
    }

}

//Function to alter current identiy of a tile given it's coordinates
void Grid::set_identity(int x, int y, en_identity k)
{
    map[x][y].identity = k;
    return;
}

//Function to print the current identity of a tile given it's coordinates
int Grid::get_identity(int x, int y)
{
    return map[x][y].identity;
}

//Function to print the map
void Grid::print()
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < length ; j++)
            cout<< map[i][j].identity << ' ';
        cout<<endl;
    }
}