#include <bits/stdc++.h>
using namespace std ;
int main (){
    int  n,x; cin >> n >> x ; string t ;cin >> t;
    for (int j =0; j< x ; j++){
        for (int i =0; i< int( t.length() ) -1  ; i++){
            if ( t[i]=='B' && t[i+1]=='G'){
                t[i]='G';
                t[i+1]='B';
                i++;
            }
        }
    }
    cout << t;
}