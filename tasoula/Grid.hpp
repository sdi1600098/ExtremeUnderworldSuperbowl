#include "Tile.hpp"
using namespace std;

class Grid
{
    public:
        Grid(int in_height, int in_length);
        ~Grid();
        void set_identity(int x, int y, int k);
        int get_identity(int x, int y);
        void print();
    private:
        int height;
        int length;
        Tile** map;
};
