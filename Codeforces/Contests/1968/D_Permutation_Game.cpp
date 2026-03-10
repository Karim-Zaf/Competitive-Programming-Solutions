/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>

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
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve() {
    int n, k, p_b, p_s;
    cin >> n >> k >> p_b >> p_s;

    vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++)cin >> a[i];


    auto work = [&](int pos) {
        vector<int> vis(n + 1);
        int curr = pos;

        int etape = 0, sum = 0;

        int ret = k * a[curr];


        while (true) {
            sum += a[curr];
            curr = p[curr];
            etape++;
            if (vis[curr] || etape > k)break;
            ret = max(ret, (k - etape) * a[curr] + sum);
            vis[curr] = 1;
        }

        return ret;
    };
    int one = 0 , two =0;
    one = work(p_b);
    two = work(p_s);

    if (one == two)cout << "Draw\n";
    else if (one > two) cout << "Bodya\n";
    else cout << "Sasha\n";


}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}