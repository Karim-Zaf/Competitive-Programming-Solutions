/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define endl '\n'
 
const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;
 
struct DSU{
    vector<int> sz, parent;
 
    void init(int n){
        for (int i = 0; i < n; i++){
            parent.pb(i);
            sz.pb(1);
        }
    }
 
    int get(int a){ return (parent[a] == a ? a : parent[a] = get(parent[a])); }
 
    bool unite(int a, int b){
        if ((a = get(a)) == (b = get(b))) return false;
        if (sz[a] > sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
 
    bool same_set(int a, int b){ return get(a) == get(b); }
    int size(int a){ return sz[get(a)]; }
};
 
void Solve(){
    int n;
    cin >> n;
    vector<int> p(n + 4);
 
    DSU dsu;
    dsu.init(n + 1);
 
    for (int i = 1; i <= n; i++)cin >> p[i];
    for (int i = 1; i <= n; i++)dsu.unite(i, p[i]);
 
    map<int, set<pair<int,int>>> mp;
 
    for (int i = 1; i <= n; i++) mp[dsu.get(i)].insert({p[i], i});
 
    vector<int> best;
 
    int ans = 0;
    for (auto& [x, s] : mp){
        auto [mx,pos] = *prev(s.end());
 
        int i = p[pos], score_cycle = mx, lst = 1;
        while (i != pos){
            lst *= -1;
 
            score_cycle += lst * p[i];
            i = p[i];
        }
 
        int mx_score_cycle = abs(score_cycle);
        int sz = s.size(), prv = mx;
 
        i = p[pos];
        while (sz % 2 && i != pos){
            score_cycle -= prv;
            score_cycle *= -1;
            score_cycle += prv;
 
            mx_score_cycle = max(mx_score_cycle, abs(score_cycle));
            prv = p[i];
            i = p[i];
        }
 
        mx_score_cycle = abs(mx_score_cycle);
        if (sz % 2 == 0)ans += mx_score_cycle;
        else best.pb(mx_score_cycle);
    }
 
    sort(rall(best));
 
    int lst = 1;
    for (auto x : best){
        if (lst == 1) ans += x;
        else ans += -x;
        lst *= -1;
    }
 
    cout << ans << endl;
}
 
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}