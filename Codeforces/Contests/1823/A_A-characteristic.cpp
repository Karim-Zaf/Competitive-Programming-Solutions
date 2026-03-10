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

const ll N = 2e5+5 , MOD =1e9+7, Q =1e10+3 ;

void solve () { 
    ll n , a  ; 
    cin >> n >> a ; 
    vi v ;   
    ll one=n , moins_un  = 0 ,res = (n*(n-1)) /2   , nw;
    nw = res ;  
    while ( one >=  0 && nw > a  ) {
        moins_un++ ; 
        one -- ; 
        nw = res - moins_un *one ; 
    }
    if ( nw == a ) {
        for (ll j= 0 ;j< moins_un ; j++) v.pb (-1) ;
        for( ll j =moins_un ; j< n ; j++) v.pb(1) ;
            yes dbg(v) ; 
        return; 
    }
    no
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ;
    ll tt=1;  
    cin >> tt ;   
    while (tt--)
        solve() ;
}