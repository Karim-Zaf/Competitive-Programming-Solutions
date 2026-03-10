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
    vector<int> v(n + 4);
    for (int i = 1; i <= n; i++) cin >> v[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += (i % 2 ? 1 : -1) * v[i];
    int res = ans;

    vector<array<int, 3>> best(n + 4), worst(n + 4);

    set<pair<int,int>> s;
    for (int i = 1; i <= n; i++){
        if (i % 2 == 0){
            auto [val, indx] = *prev(s.end());
            best[i] = {val + 2*v[i] + i, indx, i};
            ans = max(ans, res + val + 2*v[i] + i);
        }
        else{ s.insert({-2*v[i] - i, i}); }
    }

    s.clear();

    for (int i = n; i >= 1; i--){
        if (i % 2 == 0){
            if (i == n) continue;
            auto [val, indx] = *prev(s.end());
            best[i] = {val + v[i] + i, indx, i};
            ans = max(ans, res + val + 2*v[i] - i);
        }
        else{ s.insert({-2*v[i] + i, i}); }
    }
    kar(res ) ;

    ans = max(ans, res + (n - (n % 2 == 0) - 1));

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
