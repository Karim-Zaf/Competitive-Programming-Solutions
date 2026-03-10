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
    vector<string> a(n);
    vector<int> done(n), verif(n);
    vector b(m, vector<int>(n));

    vector<int> v(n);

    for (auto& x : a)cin >> x;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            string s;
            cin >> s;
            b[i][j] = (s == a[j]);
        }
    }

    for (auto vect : b)
        for (int i = 0; i < n; i++)verif[i] |= vect[i];

    if (accumulate(all(verif), 0ll) != n)return void(cout << -1 << endl);

    int pos = 0, opt = 0;

    for (int j = 0; j < m; j++){
        vector<int>& vect = b[j];
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (done[i]) continue;
            cnt += vect[i];
        }
        if (cnt > opt){
            opt = cnt;
            pos = j;
        }
    }

    cout << n + 2 * (n - opt) << endl;
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
