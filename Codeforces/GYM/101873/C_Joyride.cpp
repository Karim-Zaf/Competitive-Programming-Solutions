#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define clean(v) (v).resize(distance((v).begin(), unique(all(v))));
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

void nop() {
    cout << -1 << endl;
    return;
}
const int N = 1e3+5 ;
vector<int> adj[N] ;
int a[N] , b[N] ;
ll dp[N][N] ;
ll inf = 1e15 ;
int n , m , t , x ;
ll work(int node , int rem)
{
    if(rem<0) return inf ;
    if(node==1 && !rem) return 0 ;
    if(!rem) return inf ;
    ll& ret = dp[node][rem] ;
    if(ret!=-1) return ret ;
    ret = inf ;
    ckmin(ret , work(node , rem-a[node]) + b[node]) ;
    for(int c : adj[node]){
        ckmin(ret , work(c , rem - t - a[c]) + b[c]) ;
    }
    return ret ;
}

void solve() {
    cin>>x ;
    cin>>n>>m>>t ;
    memset(dp , -1 , sizeof (dp)) ;
    for(int i = 1 ; i<=m ; i++){
        int u , v ; cin>>u>>v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }
    for(int i = 1 ; i<=n ; i++) cin>>a[i]>>b[i] ;
    ll ans = work(1 , x-a[1]) + b[1] ;
    if(ans>=1e15){
        cout<<"It is a trap."<<endl;
    }
    else cout<<ans<<endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    io();
    ll tt = 1;
    //cin>>tt ;
    while (tt--) {
        solve();
    }

    return 0;
}