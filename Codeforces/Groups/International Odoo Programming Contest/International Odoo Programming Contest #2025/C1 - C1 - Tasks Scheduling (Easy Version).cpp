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
    T merge(T a, T b){ return (a + b); }
    void init(int _n){ n = _n, seg.assign(2 * n, ID); }
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
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> v[m + 1];

    for (int j = 1; j <= m; j++){
        v[j].resize(2 * n * 7 + 3);

        for (int i = 0; i <= 2 * n * 7 + 2; i++){ v[j][i] = 4; }
        for (int i = 0; i <= 2 * n * 7 + 2; i++){ if ((i / 2) % 7 == 0 || (i / 2) % 7 == 6) v[j][i] = 0; }
    }

    while (q--){
        int x, emp, y;
        cin >> x;
        if (x == 1){
            cin >> emp >> x;
            v[emp][2 * x] = 0;
            v[emp][2 * x + 1] = 0;
            kar(2*x, 2*x+1);
        }
        else if (x == 2){
            cin >> emp >> x >> y;

            if (y == 1) v[emp][2 * x] = 0;
            else v[emp][2 * x + 1] = 0;
        }
        else{
            int a, b, x, t;
            cin >> a >> b >> x >> t;

            int one = 0, lst = -1, ok = 0;
            for (int j = 2 * x; j <= 2 * n * 7 + 1; j++){
                one += (v[a][j] & v[b][j]);
                lst = j;
                if (one >= t){
                    ok = 1;
                    break;
                }
            }
            cout << (ok ? lst / 2 : -1) << '\n';
        }
    }
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
