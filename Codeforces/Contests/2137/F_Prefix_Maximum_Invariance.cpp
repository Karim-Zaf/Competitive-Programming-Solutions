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
    Seg(int _n){ n = _n, seg.assign(2 * n, ID); }
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
    map<int, vector<int>> mp, mp2;
    int n, ans = 0;
    cin >> n;

    vector<int> a(n + 3), b(n + 4);
    vector<int> prv(n + 3), nxt(n + 4);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) mp[-a[i]].pb(i);
    for (int i = 1; i <= n; i++) mp[-b[i]];
    for (int i = 1; i <= n; i++) mp2[-b[i]].pb(i);

    set<int> s{0, n + 1};
    vector<int> righti(n + 3);
    Seg<int> sg(n + 3);

    for (int i = 1; i <= n; i++) sg.upd(i, (n - i + 1));
    for (auto& [val, vec] : mp){
        for (auto pos : vec){
            auto it = s.lower_bound(pos);
            nxt[pos] = *it;
        }
        for (auto pos : vec) s.insert(pos);
        for (auto pos : vec){
            auto it = s.lower_bound(pos);
            prv[pos] = *prev(it);
        }
        for (auto pos : vec){ righti[pos] = sg.query(pos + 1, nxt[pos] - 1); }

        for (auto pos : mp2[val]){ sg.upd(pos, 0); }
    }

    for (int i = 1; i <= n; i++){
        int lef = i - prv[i];
        int alll = 0;
        alll += righti[i] * lef;
        alll += (a[i] == b[i]) * lef * (n - i + 1);
        ans += alll;
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
