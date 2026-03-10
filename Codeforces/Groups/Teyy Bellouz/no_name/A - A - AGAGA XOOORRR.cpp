//  (1/0+) WINS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MOD mod
#define INF (ll)(1e18)
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;} 
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 2e5+5 , MOD = 998244353, Q =2e5+3 ;


void solve(){
    ll n, xr = 0  , xr_left= 0 , xr_right = 0 , xr_aaks = 0; 
    cin >> n; 
    vi v (n);
    for (ll i= 0 ;i<n ; i++){
        cin >> v[i];
        xr^= v[i] ;
    }
    for (ll i= 0 ;i<n ; i++){
        xr_left^=v[i] ;
        xr_right = xr ^xr_left; 
        if ( xr_right == xr_left){yes return ;}
    }
    xr_left= 0 , xr_right = 0 , xr_aaks = 0;
    for (ll i= 0 ;i<n; i++ ){
        xr_right = xr^xr_aaks ;  
        xr_aaks^=v[i];
        if (i<1 ) continue ;
        xr_left=0 ;
        for (ll j= 0 ; j<i-1 ; j++ ){
            xr_left^= v[j] ;
            ll xr_west = xr^xr_left^xr_right ; 
            if ( xr_west== xr_left && xr_right == xr_west){yes return; }
        }
    }
    no
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ;
    ll tt=1;  ;   
    cin >> tt ;   
    while (tt--)
        solve() ;
}