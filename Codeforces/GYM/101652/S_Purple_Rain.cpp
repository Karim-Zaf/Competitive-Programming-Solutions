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

const int N = 100100 ; 
int prefix1[N] , prefix2[N] ; 

void solve(){
    string s ; 
    cin >> s ; 
    int n = (int)s.length() ; 
    s = "#" + s ; 
    for(int i=1 ; i<=n ; i++){
        if(s[i] == 'B') prefix1[i]++ ; 
        else prefix2[i]++ ;
    }
    for(int i=1 ; i<=n ; i++){
        prefix1[i]+=prefix1[i-1] ; 
        prefix2[i]+=prefix2[i-1] ; 
    }
    int mx1 = 0 , idx1 = 1 , mx2 = 0 , idx2 = 1 , ans = 0 , l = -1 , r = -1;
    for(int i=1 ; i<=n ; i++){
        int gg1 = prefix1[i] - prefix2[i] ; 
        if(gg1 + mx1 > ans){
            ans = gg1 + mx1 ; 
            l = idx1 ; 
            r = i ; 
        }
        int gg2 = prefix2[i] - prefix1[i] ; 
        if(gg2 + mx2 > ans){
            ans = gg2 + mx2 ; 
            l = idx2 ; 
            r = i ; 
        }
        if(gg2 > mx1){
            mx1 = gg2 ; 
            idx1 = i+1 ; 
        }
        if(gg1 > mx2){
            mx2 = gg1 ; 
            idx2 = i+1 ;
        }
    } 
    cout << l << " " << r << endl ;
}


int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  