#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int t; cin >> t;
    while (t--)
    {
        string c ; cin >> c;
        int len = c.length();int x=len;
        char min='9';
        while ( x--){
            if (c[x]<min)
                min=c[x];
            //cout << "min1= " <<min1<< endl << "min2= " << min2  << endl ;
        }
        if ( len==2) cout <<c[1]<<endl;
        else cout << min << endl;
    }
}
