/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
// #ifndef ONLINE_JUDGE
// #include "debug.cpp"
// #else
// #define kar(...)
// #endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> graph[N], val(N), a(N), ans(N);

template<class T>
struct Seg {  /*CHANGE THE ID YA KARIM !!*/
    const T ID = 0; /**/ int n;/**/ vector<T> seg;/**/
    T merge(T a, T b) { return a + b; } // Function
    void build(int _n) { n = _n, seg.assign(2 * n, ID); } /**/
    void pull(int p) { seg[p] = merge(seg[2 * p], seg[2 * p + 1]); }/**/
    void upd(int p, T val) { seg[p += n] = val;/**/for (p /= 2; p; p /= 2)pull(p);/**/}/**/
    T query(int l, int r) {/**/T ra = ID, rb = ID;/**/for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1)ra = merge(ra, seg[l++]);/**/if (r & 1)rb = merge(seg[--r], rb);
        }/**/return merge(ra, rb);
    }/**/void print(int i = -1) {/**/while (++i < n)
            cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " ");/**/}
};

Seg<int> sg;
int n;

int get_mex() {
    int l = 0, r = n, res = 0;
    while (l <= r) {
        int md = l + (r - l) / 2;
        if (sg.query(0, md) == md + 1) {
            res = md + 1;
            l = md + 1;
        } else r = md - 1;
    }
    return res;
}

void dfs(int curr, int parent = -1) {

    val[a[curr]]++;
    sg.upd(a[curr], 1);

    ans[curr] = get_mex();

    for (auto child: graph[curr]) {
        if (child == parent)continue;
        dfs(child, curr);
    }


    val[a[curr]]--;
    if (val[a[curr]] == 0)sg.upd(a[curr], 0);
}

void Solve() {
    cin >> n;
    sg.build(n + 4);
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        val[i] = 0;
    }

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        graph[i].pb(x);
        graph[x].pb(i);
    }

    dfs(1);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

}

int32_t main() {
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
//    #endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
