#ifndef TILE
#define TILE

#include <iostream>
//enumeration for clarity in the rest of the program.
enum en_identity
{
    ground,
    tree,
    water_body,
    player_avatar,
    vampire,
    werewolf,
    potion


};

class Tile
{
    public:
        Tile();
        ~Tile();
        int picked;
        en_identity identity;
        /*  identity = 0 -> ground
            identity = 1 -> tree
            identity = 2 -> water body
            identity = 3 -> player avatar
            identity = 4 -> vampire
            identity = 5 -> werewolf
            identity = 6 -> potion  */
};

#endif