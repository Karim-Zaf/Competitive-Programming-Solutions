#include <iostream>
#include <string>
#include <cctype>
using namespace std ;
int main ()
{
    int c ; cin >>c;int tab[c]={0}, k=2,len=c;
    while (k--){
        int x ; cin>> x;
        while (x--){
            int r; cin>>r ; tab[r-1]++;
        }
    }
    bool ok =1;int y=len;
    while( y-- )
        {//cout << tab[y]<<endl;
        if (tab[y]==0){ cout << "Oh, my keyboard!";return 0;}
    }cout << "I become the guy.";
}