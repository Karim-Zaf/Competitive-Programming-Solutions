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

const int  N=1e5+8,MOD=1e9+7,mod=1e9+7,INF=1e17;

int n , res[N];

vector <int> graph[N] ;
int values[N] ;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  max(a,b); }
    void build(ll _n) { n = _n; seg.assign(2*n,ID); }
    void pull(ll p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }return comb(ra,rb);
    }
};

Seg <int> sg ;
map <int,multiset <int>> ms ;
void dfs (int curr , int parent = -1){
    int ans = sg.query(0, values[curr]-1)+1;
    res[curr]= max (sg.query(0,n+2),ans) ;
    ms[values[curr]].insert(ans);
    sg.upd(values[curr],max (sg.query(values[curr], values[curr]), ans));

    for (auto child : graph[curr]){
        if (child==parent) continue;
        dfs( child , curr);
    }
    ms[values[curr]].erase(ms[values[curr]].find(ans));
    if (ms[values[curr]].empty())sg.upd(values[curr],0);
    else sg.upd(values[curr],*prev(ms[values[curr]].end()));
}

void Solve() {
    cin >> n ;
    sg.build(n+3) ;
    map <int,int> mp;
    for (int i= 2 ;i<=n ; i++){
        int x ; cin >> x ;
        graph[i].pb(x);
        graph[x].pb(i);
    }for (int i= 1 ;i<=n ;i++){
        cin >> values[i];
        mp[values[i]]=1 ;
    }
    int i= 0 ;
    for (auto x: mp) mp[x.F]=++i;

    for (int i= 1; i<= n ;i++)values[i]= mp[values[i]];
    dfs(1);
    for (int i= 2; i<= n ;i++)cout << res[i] << " " ;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}