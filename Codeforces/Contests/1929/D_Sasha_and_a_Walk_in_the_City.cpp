/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define kar(...)
#endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int N=3e5+30,mod=998244353,MOD=mod,INF=1e18+10;

vector<int> graph[N] , ans(N);
int n , res;
ll mult(ll a, ll b){b%=MOD;return a%MOD*b%MOD;}
ll add (ll a, ll b){ return ((a%mod + b%mod)%mod + mod)%mod;}

void init(){
    for (int i= 1; i<=n ;i++) graph[i].clear();
    res  =0;
    for (int i= 1; i<=n ;i++ )ans[i]=1 ;
}

void dfs (int curr, int parent =-1){
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs (child,curr);
    }
    for (auto child: graph[curr]){
        if (child == parent)continue;
        ans[curr]= mult (ans[curr],ans[child]);//making set between children
        res = add(res,add(ans[child],-1)) ; // making set with {curr} and its children except empty{}
    }
    ans[curr]= add(ans[curr],1);//{curr}
}

void Solve() {
    cin >> n ;
    init();
    for (int i=1, u , v ; i<n ;i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs (1);
    cout << add(ans[1],res)<< endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}