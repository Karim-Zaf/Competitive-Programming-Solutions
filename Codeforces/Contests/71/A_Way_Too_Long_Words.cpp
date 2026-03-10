#include <iostream>
#include <string>
using namespace std;
int main ()
{
    int nb; cin >> nb;
    for (int i=0; i < nb; i++)
    {
        string ch ;cin >>ch;
        int x =int(ch.length());
        if ( x>10)
            cout << ch[0] << x-2 << ch[x-1]<< endl;
        else  cout << ch<< endl;
    }
}