#include <bits/stdc++.h>
using namespace std ;
 
int main ()
{
    int n ; cin >> n ;
    
    while ( n-- ){
          map<int,int> mp, mp2;
        int s , k ; cin >> s >> k;
        for(int i=1; i <= s;i++){
            int x; cin >> x;
            if (! mp.count(x) )mp[x] = i;
            mp2[x]=i;
        }
        //for(map<int, int> :: iterator it = mp.begin();it != mp.end();it++)
           // cout << it -> first << "  "<<it -> second<<endl;
      while(k--){
            int a,b; cin >>a>>b;
            
            if (!mp.count(a) || !mp.count(b)) cout << "NO"<<endl; 
            else if ( mp[a]<= mp2[b]) cout << "YES" << endl;
            else cout << "NO"<<endl;  
      } 
    }

}