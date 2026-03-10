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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

vector<int> graph[N], values(N) ;
vector <int> spf (N), primes ;
map<int,int> mp[N] ;
int n, ans = 0;



void sieve(){
    for (int i=1 ; i< N ; i++ ) spf[i]= i ;
    for  (int i =2 ; i<N ; i++){
        if (spf[i] != i) continue;
        primes.push_back (i);
        for ( int j= i ; j<N ; j+=i)
            spf[j]=min(spf[i], i);
    }
}

vector<int> factors(int n){
    vector<int> res  ;
    set <int> temp ;
    while ( n > 1 ) {
        temp.insert(spf[n]) ;
        n/= spf[n] ;
    }
    for (int val : temp ) res.push_back(val) ;
    return res ;
}


void dfs (int curr , int parent =-1){

    for (auto child: graph[curr]){
        if (child == parent )continue;
        dfs (child,curr) ;
    }

    vector<int> f = factors(values[curr]);
    for (auto x: f ){
        mp[curr][x]= 1 ;
        multiset<int> s;

        for (auto child: graph[curr]){
            if (child == parent )continue;

            int cnt = mp[child][x];
            mp[curr][x]= max(mp[curr][x],cnt+1);
            s.insert(cnt);
        }

        for (auto child: graph[curr]){
            if (child == parent )continue;

            int cnt = mp[child][x];
            s.erase(s.find(cnt));
            int mx = 0;
            if (!s.empty())mx = *s.rbegin();
            ans = max (ans,1+mx+cnt) ;
            s.insert(cnt);
        }

        ans =max (ans , mp[curr][x]);
    }
}

void Solve() {
    sieve();
    cin >> n ;
    for (int i= 1; i<=n ;i++)cin >> values[i] ;
    for (int i= 1, u , v; i<n ;i++){
        cin >> u >> v;
        graph[v].pb(u) ;
        graph[u].pb(v);
    }
    dfs(1);
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}