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

const int  N=2e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;


vector<int> graph[N];
int cnt[N] ;
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

void Solve(){
    int n , m ;
    cin >> n>> m ;
    set <int> s ;
    for (int i= 1;i<= n;i++)s.insert(i);
    for (int i= 0;i<m;i++) {
        int u , v ;
        cin >> u>> v ;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    init(n+1);
    for (int i= 1;i<=n;i++){
        vector <int> mnaa ;
        set <int> nws ;
        for (auto child :graph[i]){
            int  rass= get(child);
            int &siz = cnt[rass];
            if (++siz==sz[rass]){
                mnaa.pb(rass);
                s.erase(rass);
                nws.insert(rass);
            }
        }
        for (auto child :graph[i])cnt[get(child)]--;
        for (auto x:s) unite(i,x);
        nws.insert(get(i));
        s= nws;
    }
    vector <int> res ;
    for (auto x : s) res.pb(size(x));
    sort (all(res));
    cout << res.size()<< endl;
    for (auto x: res) cout << x << " " ; cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}