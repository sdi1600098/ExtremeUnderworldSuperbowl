#include "Tile.hpp"
using namespace std;

class Grid
{
    public:
        Grid(int in_height, int in_length);
        ~Grid();
        void rand_in_board();
        void set_identity(int x, int y, en_identity k);
        int get_identity(int x, int y);
        int get_player_y();
        int get_player_x();
        int get_height();
        int get_length();
        void print();
        Tile** map;
    private:
        int height;
        int length;
        //Tile** map;
};
