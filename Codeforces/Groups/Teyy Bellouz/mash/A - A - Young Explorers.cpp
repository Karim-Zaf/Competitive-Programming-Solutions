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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

struct DSU{
    vector<int>  sz , parent ;
    void init(int n){ for (int i = 0; i < n; i++){ parent.pb(i) ; sz.pb(1) ; } }
    int get(int a){return (parent[a] == a ? a : parent[a] = get(parent[a]));}
    bool unite(int a, int b){
        if ((a = get(a))==(b = get(b))) return false;
        if (sz[a]>sz[b]) swap (a,b) ;
        parent[b] = a;
        sz[a] += sz[b];
        return true ;
    }
    bool same_set(int a, int b){return get(a) == get(b);}
    int size(int a){ return sz[get(a)];}
};

void Solve() {
    int n ;
    cin >> n ;
    vector <int> v(n) ;
    for(auto &x: v) cin>> x;
    sort (all(v));
    int i= 0 , ans = 0 ;
    DSU dsu ;
    dsu.init(n) ;
    while (i<n){
        int mx = v[i], j= i ;
        if (dsu.size(i)>=v[i]){ans ++ ;i++; continue;}
        while (j<n && dsu.size(i)<mx){
            mx = max (mx,v[j]);
            dsu.unite (i,j++);
        }
        if (dsu.size(i)>=mx) ans ++ ;
        i = j ;
    }
    cout << ans << endl;

}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}