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
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;
const int M = 25;
int ans[M][M];
int ans_seul[M];
int dp[M][(1 << 22) + 1];
int n, q;
int work(int lst, int mask){
    if (mask == (1 << (n + 1)) - 2) return ans_seul[lst] + 1;
    int& ret = dp[lst][mask];
    if (ret != -1) return ret;

    ret = INF;
    for (int i = 1; i <= n; i++){
        if (((1 << i) & mask) == 0)
            ret = min(ret, ans[lst][i] + work(i, mask | (1 << i)));
    }
    return ret;
}

void Solve(){
    cin >> n >> q;

    memset(dp, -1, sizeof(dp));

    vector vp(n + 3, vector<pair<int,int>>(q + 4));
    vector<pair<int, char>> queries(q + 4);

    for (int i = 1; i <= q; i++){
        cin >> queries[i].F >> queries[i].S;
        for (int j = 1; j <= n; j++)vp[j][i] = vp[j][i - 1];
        if (queries[i].S == '+') vp[queries[i].F][i].S++;
        else vp[queries[i].F][i].F++;
    }

    for (int i = 1; i <= n; i++)for (int j = 0; j <= q; j++) ans_seul[i] = max(ans_seul[i], vp[i][j].S);
    for (int one = 1; one <= n; one++){
        for (int two = 1; two <= n; two++){
            int& curr = ans[one][two];

            for (int i = 1; i <= q; i++){
                auto [l1,r1] = vp[one][i];
                auto [l2,r2] = vp[two][i];

                curr = max(curr, r1 - l2 + 1);
            }
        }
    }

    cout << work(0, 0) << endl;
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
