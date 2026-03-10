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

const int N = 1e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

const int SQ = sqrt(N);

void Solve(){
    /*SQRT decomposition*/
    int n, q;
    cin >> n >> q;

    vector<int> v(n);

    for (int i = 0; i < n; i++)cin >> v[i];

    vector<array<int, 3>> dp(n);
    for (int j = 0; ; j++){
        int l = j * SQ;
        if (l > n) break;
        int r = min(n - 1, l + SQ - 1);
        for (int i = r; i >= l; i--){
            if (v[i] + i > r) dp[i] = {1, i, i + v[i]};
            else{
                dp[i] = dp[i + v[i]];
                dp[i][0]++;
            }
        }
    }

    while (q--){
        int ans = 0, lst = -1;
        int x, a, b;;
        cin >> x >> a;
        a--;
        if (x == 0){
            cin >> b;

            v[a] = b;
            int curr = a / SQ;
            int l = curr * SQ;
            int r = min(n - 1, l + SQ - 1);
            for (int i = r; i >= l; i--){
                if (v[i] + i > r) dp[i] = {1, i, i + v[i]};
                else{
                    dp[i] = dp[i + v[i]];
                    dp[i][0]++;
                }
            }
        }
        else{
            while (a < n){
                ans += dp[a][0];
                lst = dp[a][1];
                a = dp[a][2];
            }
            cout << lst + 1 << " " << ans << endl;
        }
    }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
