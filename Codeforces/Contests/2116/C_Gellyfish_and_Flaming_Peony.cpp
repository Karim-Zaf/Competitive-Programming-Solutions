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
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    int g = 0;
    for (int i = 1; i <= n; i++) g = __gcd(g, v[i]);
    for (auto& x : v) x /= g;

    set<pair<int,int>> s;
    for (int i = 1; i <= n; i++){
        int x = v[i], nw = 1, cnt = 0;
        for (int d = 2; d * d <= x; d++){
            if (x % d) continue;
            while (x % d == 0) x /= d;
            nw *= d;
            cnt++;
        }
        if (x > 1) cnt++, nw *= x;
        s.insert({cnt, nw});
    }

    if (s.find({0, 1}) != s.end())return void(cout << (n - count(all(v), 1ll)) << endl);

    const int MX = 6;
    set<int> dp[MX];


    vector vect(all(s));
    for (int i = 0; i < vect.size(); i++){
        for (int j = MX - 2; j >= 1; j--){ for (auto x : dp[j]){ dp[j + 1].insert(__gcd(vect[i].S, x)); } }
        dp[1].insert(vect[i].S);
    }

    for (int i = 1; i <MX; i++){ if (dp[i].find(1) != dp[i].end()){ return void(cout << (n - 2 + i) << endl); } }

    cout << n << endl;
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
