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

const ll N = 1e6+2 , MOD =1e9+7, Q =2e5+3 ;

void solve(){
    ll n, m ; 
    cin >> n ; 
    vi v(n ) ; 
    for (ll i= 0 ;i<n ; i++ ) cin >> v[i] ; 
        // dbg (v);
    for (ll i= 0 ;i<=n ; i++ ) {
        ll cnt = 0 ;
        for (ll j= 0;j< n ; j++ ) {
            // watch (v[j])
            if (v[j]> i ) cnt ++ ; 
        }
        // watch(i); 
        // watch(cnt); 
        if (cnt ==i ){
            cout << i <<endl; return ;
        }
    }
    cout << -1 <<endl; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;    
    cin >> test_case ;    
    while (test_case--)  solve() ;
}