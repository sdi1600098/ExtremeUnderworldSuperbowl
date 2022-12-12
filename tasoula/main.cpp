#include <iostream>
#include "Grid.hpp"
using namespace std;

int main()
{
    int length, width;
    //-----Read input---------------//
    cout<<"Input height:";          //
    cin>>length;                    //
    cout<<endl<<"Input length:";    //
    cin>>width;                     //
    cout<<endl;                     //
    //------------------------------//

    //initialize map
    Grid map(length, width);
    map.rand_in_board();
    //map.set_identity(3, 5, tree);
    map.print();
    return 0;
}