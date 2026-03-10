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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> vp(m);

    for (auto& x : vp) cin >> x.S;
    for (auto& x : vp) x.F = x.S / 100;

    sort(all(vp));
    int t[n][6];
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < (n + 1) / 2; j++){
            int one = vp[j].S, two = vp[m - j - 1].S;
            kar(one, two);
            t[j][i] = one;
            t[n - j - 1][i] = two;

            if (i % 2){
                t[j][i] = two;
                t[n - j - 1][i] = one;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 6; j++){ cout << t[i][j] << " "; }
        cout << endl;
    }
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
