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


const int N = 1100 ;
int v[N] ; 

void solve(){
    int n , a , b ; 
    cin >> n >> a >> b ; 
    v[1] = a ; 
    v[n] = b ; 
    set<int> s ; 
    for(int i=1 ; i<=n ; i++){
        if(i!=a && i!=b){
            s.insert(i) ; 
        }
    }
    for(int i=2 ; i<=n/2 ; i++){
        v[i] = *prev(s.end()) ;
        s.erase(prev(s.end())) ;  
    }
    for(int i=n-1 ; i>n/2 ; i--) {
        v[i] = *s.begin();
        s.erase(s.begin()) ;
    }
    int mn = 1e9  , mx = 0 ; 
    for(int i=1 ; i<=n/2 ; i++){
        mn = min(mn , v[i]) ; 
    }
    for(int i=n/2+1 ; i<=n ; i++) mx = max(mx , v[i]) ; 
    if(mn==a && mx==b){
        for(int i=1 ; i<=n ;i++){
            cout << v[i] << " " ;
        }
    } else{
        cout << "-1" ;
    }
    cout << endl ; 
}

int main(){
    fast 
    ll t = 1 ; 
    cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  