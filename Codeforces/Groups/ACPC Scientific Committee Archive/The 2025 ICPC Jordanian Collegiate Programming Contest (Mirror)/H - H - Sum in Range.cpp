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
 
template <class T>
struct Seg{ /*CHANGE THE ID YA KARIM !!*/
    const T ID = 0;
    int n;
    vector<T> seg;
    T merge(T a, T b){ return a + b; }
    Seg(int _n) : n(_n), seg(2 * n, ID){}
    void pull(int p){ seg[p] = merge(seg[2 * p], seg[2 * p + 1]); }
 
    void upd(int p, T val){
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }
 
    T query(int l, int r){
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2){
            if (l & 1) ra = merge(ra, seg[l++]);
            if (r & 1) rb = merge(seg[--r], rb);
        }
        return merge(ra, rb);
    }
 
    void print(int i = -1){
        while (++i < n) cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " ");
    }
};
 
void Solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    int q;
    cin >> q;
    vector<array<int, 3>> queries(q);
 
    vector<array<int, 5>> mp;
 
    for (auto& [l,r,k] : queries)cin >> l >> r >> k;
 
    for (int i = 0; i < q; i++){
        auto& [l,r,k] = queries[i];
        mp.pb({k, -1, l, r, i});
    }
    for (int i = 0; i < n; i++){ mp.pb({v[i], -2, i, 0, 0}); }
 
    Seg<int> sg(n + 3);
 
    sort(all(mp));
    vector<int> ans(q);
 
    for (auto x : mp){
        auto& [k,t,l,r,i] = x;
        if (t == -2) sg.upd(l, v[l]);
        if (t == -1) ans[i] = sg.query(l - 1, r - 1);
    }
 
    for (auto x : ans){ cout << x << endl; }
}
 
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}