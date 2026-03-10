#include <bits/stdc++.h>
using namespace std ;
int t[26]={0};
int somme ( string x){
    int s =0;
    for ( int i =0 ; i < int (x.length()) ; i++)
        s+= x[i]-'a'+1;
    return s;
} 
int main (){
    int n ; cin >> n ; 
    while (n--){
        string w ,neww; int p; cin >> w;cin.ignore(); cin >> p ;
        neww=w;
        sort ( neww.begin(), neww.end());
        //cout << "w intitial est : "<< neww<<endl; 
        int z = somme (neww);
        while (z>p){
            t[neww.back()-'a']++;
            z-= neww.back()-'a'+1;
            neww.pop_back();
            //cout << neww << endl;
            
        }
        //cout << "final w is : "<< neww << endl;
        for (int i =0; i < int (w.length()) ;i++){
            if ( (t[w[i]-'a'])==0){
                cout << w[i];
                continue;
            }
            t[w[i]-'a']--;  
        } 
        cout << endl;
            
    }
    
}