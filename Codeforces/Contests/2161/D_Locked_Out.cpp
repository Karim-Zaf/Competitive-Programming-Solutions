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
    T merge(T a, T b){ return max(a, b); }
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

    vector<int> mp[n + 1];
    for (int i = 0; i < n; i++){ mp[v[i]].push_back(i); }

    vector<int> prev;
    vector<int> dp(n + 2, 0);
    vector<int> dp_nb(n + 2);

    Seg<int> sg(n + 2);
    for (int i = 1; i <= n; i++){
        vector<int>& curr = mp[i];
        vector<int>& prev = mp[i - 1];

        reverse(all(curr));
        for (auto pos : curr){
            // ay haja ml suffix ;
            dp[pos] = sg.query(pos, n + 1) + 1;
            dp[pos] = max(dp[pos], (i - 2 >= 0 ? dp_nb[i - 2] + 1 : 1));
            sg.upd(pos, dp[pos]);
        }
        for (auto pos : curr)dp_nb[i] = max(dp_nb[i], dp[pos]);
        dp_nb[i] = max(dp_nb[i], dp_nb[i - 1]);
        reverse(all(curr));
    }
    cout << n - dp_nb[n] << endl;
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
