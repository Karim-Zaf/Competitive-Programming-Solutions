#include <bits/stdc++.h>
using namespace std ;
 
int main ()
{
    int n ,mx= INT_MIN ; cin >> n ;
    map<string,int> mp;
    int m =n;
    vector <pair <string , int >> a;
    while ( n-- ){
        string x ; cin >> x; cin.ignore() ; int score ; cin >> score ;
        mp[x]+=score;
        a.push_back(make_pair(x,mp[x]));
        
    }
    for ( map<string, int > :: iterator it = mp.begin(); it != mp.end() ;it++)
        mx= max (mx, it->second);
    for (int i=0; i< m ; i++){
        if ( mp[a[i].first]==mx && a[i].second>=mx){
            cout << a[i].first;return 0;
        }
    }
            
    
}