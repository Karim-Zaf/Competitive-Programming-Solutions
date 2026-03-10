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
vector<ll> a[N] , prefix[N]; 
ll lst[N] ;

void solve(){
    ll x , k ; 
    cin >> x >> k ; 

    ll ans = -inf ; 
    vector<array<ll,3>> v ;
     
    for(int i=1 ; i<=k ; i++) {
        int l ; 
        cin >> l ; 
        a[i] = vector<ll>(l+1) ;
        for(int j=1 ; j<=l ; j++) {
            cin >> a[i][j] ; 
            a[i][j] += a[i][j-1] ;
        }
        ll mx = -inf , mn = inf ; 
        for(int j=0 ; j<=l ; j++){
            mn = min(mn , a[i][j]) ;
            v.pb({mn,a[i][j],i}) ; 
        }
    }
    sort(v.rbegin() , v.rend()) ; 
    for(int i=0 ; i<v.size() ; i++){
        if(v[i][0] + x >= 0){
            if(lst[v[i][2]] <= v[i][1]) {
                x += v[i][1] - lst[v[i][2]] ; 
                lst[v[i][2]] = v[i][1] ; 
            }
        }
    }
    cout << x << endl ;
}

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  