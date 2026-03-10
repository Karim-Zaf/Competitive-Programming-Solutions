#include <bits/stdc++.h>
using namespace std ;
 
int main ()
{
    int n ; cin >> n ;
    map<string,int> mp;
    while ( n-- ){
        string x ; cin >> x;
        if ( !mp[x] ) cout << "OK"<<endl;
        else{
            cout << x << mp[x]<<endl;
        }
        mp[x]++;
    }
}