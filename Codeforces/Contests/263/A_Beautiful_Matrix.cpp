#include <iostream>
#include <cmath>
using namespace std ;
int x=0,y;
int main ()
{
    bool var=0;
    while (x<5&& !var){x++;y=0;
    while (!var && y<5)
    {
        cin >>var;y++;}}
    cout<<abs(y-3)+abs(x-3);
}