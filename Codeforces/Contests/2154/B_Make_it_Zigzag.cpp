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

void Solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto& x : v) cin >> x;
    int mx = v[0];
    for (int i = 0; i < n; i++){
        if (i % 2 == 0);
        else{ v[i] = max(v[i], mx); }
        mx = max(mx, v[i]);
    }
    kar(v);

    int cnt = 0;
    for (int i = 1; i < n; i += 2){
        if
        (i + 1 < n && v[i] <= v[i + 1]){
            int prv = v[i + 1];
            int nw = v[i] - 1;
            cnt += abs(prv - nw);
            v[i + 1] = nw;
        }
    }

    for (int i = 1; i < n; i += 2){
        if
        (v[i] <= v[i - 1]){
            int prv = v[i - 1];
            int nw = v[i] - 1;
            cnt += abs(prv - nw);
            v[i - 1] = nw;
        }
    }

    kar(v);

    cout << cnt << endl;
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
