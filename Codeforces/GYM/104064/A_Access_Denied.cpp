#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define ll long long
#define ld double
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define affichea(a,n) for(ll i=0 ; i<n ; i++) cout << a[i] <<" " ;
#define yes cout << "Yes" << endl;
#define no cout<<"No"<<endl;
#define F first
#define S second
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>
#define double long double
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 


string g1 , g2 ,g3 , g4; 

void work(string s){
    for(int j=0 ; j<(int)s.length() ; j++) {
        int mx = -1 , c = -1 ;  
        for(int i='A' ; i<='Z' ; i++){
            s[j] = char(i) ; 
            cout << s << endl ;
            cout.flush() ; 
            cin >> g1 >> g2  ;
            if(g2=="GRANTED") {
                cout << s << endl ;
                cout.flush() ;  
                return ;
            }
            cin >> g3 >> g4 ; 
            reverse(g3.begin() , g3.end()) ; 
            int x = 0 , y = 1 ;
            for(int i=0 ; i+1<(int)g3.size() ; i++) {
                x += (g3[i]-'0')*y ;
                y *= 10 ; 
            }   
            if(x>mx){
                mx = x ; 
                c = i ; 
            }
        }
        for(int i='a' ; i<='z' ; i++){
            s[j] = char(i) ; 
            cout << s << endl ;
            cout.flush() ;  
            cin >> g1 >> g2 ;
            if(g2=="GRANTED"){
                cout << s << endl ; 
                cout.flush() ;  
                return ;
            }
            cin >> g3 >> g4 ;
            reverse(g3.begin() , g3.end()) ; 
            int x = 0 , y = 1 ;
            for(int i=0 ; i+1<(int)g3.size() ; i++) {
                x += (g3[i]-'0')*y ;
                y *= 10 ; 
            }   
            if(x>mx){
                mx = x ; 
                c = i ; 
            }
        }
        for(int i='0' ; i<='9' ; i++){
            s[j]  = char(i) ; 
            cout << s<< endl ;
            cout.flush() ;  
            cin >> g1 >> g2  ;
            if(g2 == "GRANTED"){
                cout << s << endl ;
                cout.flush() ;  
                return ;
            }
            cin >> g3 >> g4 ;
            reverse(g3.begin() , g3.end()) ; 
            int x = 0 , y = 1 ;
            for(int i=0 ; i+1<(int)g3.size() ; i++) {
                x += (g3[i]-'0')*y ;
                y *= 10 ; 
            }   
            if(x>mx){
                mx = x ; 
                c = i ; 
            }
        }
        s[j] = char(c) ; 
    }
}

void solve(){
    string s = "" ;
    int x = 0 ;
    while(x<=5){
        s+='A' ; 
        cout << s << endl ; 
        cout.flush() ; 
        cin >> g1 >> g2 ;
        if(g2=="GRANTED"){
            cout << s << endl ;
            cout.flush() ; 
            return ; 
        }
        cin >> g3 >> g4 ;
        reverse(g3.begin(),g3.end()) ;
        int g = 0 , y = 1 ;
        for(int i=0 ; i+1<(int)g3.size() ; i++) {
            g += (g3[i]-'0')*y ;
            y *= 10 ; 
        }
        x = g ; 
    }
    work(s) ;
}   

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  