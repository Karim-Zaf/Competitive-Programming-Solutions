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

const int N = 50 ;
char a[N][N] ; 
ll dp[N][N] , lst[N] , fsr[N] ; 
int n , m ; 

ll work(int i,int j){
    if(i > n) return 1 ; 
    ll &ret = dp[i][j] ; 
    if(ret != -1) return ret ; 
    ret = 0 ; 
    
    if(j>0) ret += work(i,j-1) ;
    
    if(lst[i] <= j && fsr[i] > j) ret += work(i+1,j) ;  
    
    return ret ; 
}

void solve(){
    cin >> n >> m ; 
    
    for(int i=0 ; i<=n ; i++){
        fsr[i] = 2e9 ; 
        for(int j=0 ; j<=m ; j++) 
            dp[i][j] = -1 ; 
    }

    for(int i=1 ; i<=n ;i++)
        for(int j=1 ; j<=m ; j++)
            cin >> a[i][j] ;

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++) {
            if(a[i][j] == 'B') lst[i] = j ;
            if(a[i][j] == 'R' && fsr[i]==2e9) fsr[i] = j ;  
        }
    }   
    cout << work(1,m) << endl ;
}

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  