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
 
const int N = 200100 ; 
int a[N] ; 
int g[5] ; 
 
void solve(){
    int n;
    cin >> n ;
    for(int i=1 ; i<=n ; ++i) {
        cin >> a[i] ;
        g[a[i]%5]++ ; 
    }
    int ans = 0 ; 
    ans = g[0] ; 
    int x = min(g[1],g[4]) ; 
    ans += x ; 
    g[1]-=x , g[4]-=x ; 
    x = min(g[2],g[3]) ;
    g[2]-=x , g[3]-=x ;  
    ans += x ; 
 
 
    // 2 1 1 1 : i 
    // 2 2 1 : 
    // 2 2 2 2 2
    // 1 1 1 1 1  
    int cur = 0 ;
    for(int i=0 ; i<=g[2] ; i++){
        if(g[1]/3<i) continue ; 
        int rest = (g[2] - i)/2 ; 
        cur = max(cur , i + min(rest,g[1]-3*i) + (g[2] - i - min(rest,g[1]-3*i)*2)/5 + (g[1] - 3*i - min(rest,g[1]-3*i))/5 ) ; 
    } 
 
    // 3 1 1  
    // 3 3 3 1
    // 3 3 3 3 3
    for(int i=0 ; i<=g[3] ; i++){
        if(g[1]/2<i) continue ; 
        int rest = (g[3] - i)/3 ; 
        cur = max(cur , i + min(rest,g[1]-2*i) + (g[3]-i-min(rest,g[1]-2*i)*3)/5 + (g[1] - 2*i - min(rest,g[1]-2*i))/5 )  ; 
    }
 
    // 4 2 2 2 
    // 4 4 2
    // 4 4 4 4 4
    for(int i=0 ; i<=g[4] ; i++){
        if(g[2]/3<i) continue ; 
        int rest = (g[4] - i)/2 ; 
        cur = max(cur , i + min(rest , g[2] - 3*i) + (g[4] - i - min(rest , g[2] - 3*i)*2)/5 + (g[2] - i*3 - min(rest , g[2] - 3*i))/5) ; 
    }
    // 4 3 3
    // 4 4 4 3
    for(int i=0 ; i<=g[4] ; i++){
        if(g[3]/2<i) continue ; 
        int rest = (g[4] - i)/3 ; 
        cur = max(cur , i + min(rest , g[3] - 2*i) + (g[4] - i - min(rest , g[3] - 2*i)*3)/5 + (g[3] - i*2 - min(rest , g[3] - 2*i))/5) ; 
    }
    // cur = max(cur , min(g[4] , g[3]/2) + (g[4]-min(g[4] , g[3]/2))/5 + (g[3]-min(g[4] , g[3]/2)*2)/5) ; 
     
    for(int i=1 ; i<=4 ; i++) cur = max(cur , g[i]/5) ;
 
    cout << ans + cur << endl ;
}
 
int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  