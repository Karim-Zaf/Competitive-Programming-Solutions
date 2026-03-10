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

const ll N = 1e7+5 , MOD =1e9+7, Q =1e10+3 ;


void solve () { 
    
    ll n , m , a , b ; 
    cin >> n >> m >> a >> b ; 
    ll t[n][m] ; 
    for (ll i  = 0  ; i< n ; i++ )
        for (ll j =  0 ; j <m ; j++ )
            t[i][j] = 0 ;
    vi nb (m) ; 
    for (ll i = 0 ;i<n ; i++ ) {
        vector <pair<ll,ll>> vp ; 
        for (ll j = 0 ;j< m ; j++)
            vp.pb (make_pair(nb[j],j)) ;
        sort(all(vp)); 
        for (ll k = 0 ;k < a ; k++ ) {
            ll j= vp[k].S ; 
            if (nb[j]<b ){
                t[i][j] = 1 ;
                nb[j]++ ;   
            }

        }
    } 
    for (ll i  = 0  ; i< n ; i++ ){
        ll nb1 = 0 ; 
        for (ll j =  0 ; j <m ; j++ )
            if (t[i][j])
                nb1++   ;
        if (nb1 != a ){no return ; }
    }
    for (ll j = 0 ; j < m ; j++ ){
        if (nb[j]!=b) {no return ; }
    }
    yes 
    for (ll i  = 0  ; i< n ; i++ ){
        for (ll j =  0 ; j <m ; j++ )
            cout << t[i][j]  ;
        cout <<endl; 
    }
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