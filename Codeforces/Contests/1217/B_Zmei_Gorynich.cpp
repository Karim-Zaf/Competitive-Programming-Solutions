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
    ll n , res = INF , x , d , h ,hesba , mx = 0 ; 
    cin >> n >> x ;
    vector <pair <ll,ll >> vp (n); 
    for (ll i= 0 ;i<n ; i++) {
        cin >> vp[i].F >> vp[i].S ;
        mx = max ( mx , vp[i].F );
    }
    for (ll i= 0 ;i<n ; i++) {
        d  = vp[i].F , h = vp[i].S ;
        if ( d>= x ) {cout << 1 <<endl ; return; }
        if ( d>h){
            hesba =( x - mx )/(d-h)+1;
            if ((x-mx)%(d-h)) hesba++;
            res = min ( res , hesba );
        }
    }
    if ( res == INF) cout << -1 <<endl;
    else cout << res <<endl;

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