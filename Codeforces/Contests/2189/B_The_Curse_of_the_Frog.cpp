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
    int n, x;
    cin >> n >> x;

    int curr = 0;
    int mx = -INF;

    vector<array<int, 3>> v;
    int indx = 0;
    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;

        curr += (a * (b - 1));
        v.pb({a, b, c});

        int cnt = (-v[i][2] + v[i][1] * v[i][0]);
        int cnt2 = (-v[indx][2] + v[indx][1] * v[indx][0]);

        if (cnt > cnt2){ indx = i; }
    }
    if (curr >= x) return void(cout << 0 << endl);

    int cnt = (-v[indx][2] + v[indx][1] * v[indx][0]);

    if (cnt <= 0) return void(cout << -1 << endl);
    x -= curr;
    cout << (x + cnt - 1) / cnt << endl;
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
