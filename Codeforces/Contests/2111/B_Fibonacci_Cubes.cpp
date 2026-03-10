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
    vector<int> v{1, 1};

    for (int i = 1; i < n; i++) v.pb(v[v.size() - 1] + v[v.size() - 2]);

    auto work = [&](int a, int b, int c){
        int lst = v[v.size() - 1] + v[v.size() - 2];
        if (a >= lst && b >= v.back() && c >= v.back()) return true;
        return false;
    };

    kar(v);
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        ans |= work(a, b, c);
        ans |= work(a, c, b);
        ans |= work(b, a, c);
        ans |= work(b, c, a);
        ans |= work(c, a, b);
        ans |= work(c, b, a);

        cout << (ans ? 1 : 0);
    }

    cout << endl;
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
