//  (1/0+) WINS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define fr(i,a,b) for(ll i = a;i < (ll)b;i++)
#define rfr(i,a,b) for(ll i = a;i > (ll)b;i--)
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define INF (ll)(1e18)
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;} 
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e5+5 , MOD =1e9+7, Q =1e5+3 ;

bool comp (pair<pair<ll,ll>,ll> e, pair<pair<ll,ll>,ll> k ) {
    pi p = e.F ; 
    pi g = k.F ; 
    if ( g.F!=p.F) 
        return p.F < g.F ;
    return p.S >g.S ; 
}

void solve () {
    ll n ; 
    cin >> n ;
    vector <pair<pair<ll,ll>,ll>> v ; multiset <pair<ll,ll>>  jdid ; 
    for (ll i= 0 ;i<n ; i++){
        ll l , r ; 
        cin >> l >> r ; 
        v.pb({{l, r },i}) ; 
    }
    sort(all(v), comp )  ; 
    for (ll i= 0 ;i<n ; i++ ) {
        pi p = make_pair(v[i].F.S,0) ; 
        auto pr = jdid.lower_bound (  p )  ; 
        if (  pr !=jdid.end() ) {
            ll hachti = (*pr).S ; 
            ll res = v[hachti].S ; 
            cout << v[i].S +1 <<  " " << res+1 <<endl;
            return;
        } 
        jdid .insert ( {v[i].F.S ,i} ) ; 
    }
    cout << "-1 -1" <<endl; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt=1; 
    // cin >> tt;
    while (tt--)
        solve() ;
}