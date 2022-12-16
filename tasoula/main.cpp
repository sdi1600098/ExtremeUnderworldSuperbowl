#include <iostream>
#include "Grid.hpp"
using namespace std;

int main()
{
    int height, length;
    char input;
    //-----Read input---------------//
    cout<<"Input height:";          
    cin>>height;                     
    cout<<endl<<"Input length:";    
    cin>>length;                     
    cout<<endl;                     
    cout<<"Pick a side"<<endl;
    cout<<"Press 'w' to join the ferocious army of werewolves or press 'v' if you are goth."<<endl;
    cin>>input;
    cout<<endl;
    cout<<input;
    //------------------------------//

    //initialize map
    Grid map(height, length);
    map.rand_in_board();
    //map.set_identity(3, 5, tree);
    map.print();
    return 0;
}