#include <iostream>
#include "Grid.hpp"

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
            map[i][j].identity = 0;

    return;
}

//Destructor
Grid::~Grid()
{

}

//Function to alter current identiy of a tile given it's coordinates
void Grid::set_identity(int x, int y, int k)
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