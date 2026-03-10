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

const int LG = (58);
int dp[LG][LG][LG+10];

int work(int x, int y, int lst = LG+1){
    if (!x && !y) return 0;
    if (x < 0) return INF;
    if (y < 0) return INF;
    if (lst < 0) return INF;

    int& ret = dp[x][y][lst];
    if (ret != -1) return ret;

    ret = INF;
    // skip
    ret = min(ret, work(x, y, lst - 1));

    // apply to x ;
    ret = min(ret, (1ll << lst) + work(x - lst, y, lst - 1));

    // apply to y ;
    ret = min(ret, (1ll << lst) + work(x, y - lst, lst - 1));

    return ret;
}

void Solve(){
    int x, y;
    cin >> x >> y;
    if (x == y) return void(cout << 0 << endl);
    
    int ans = INF;
    for (int i = 0; i < LG; i++)
        for (int j = 0; j < LG; j++){
            if ((x >>i) == (y >>j)){
                ans = min(ans, dp[i][j][LG+3]);
            }
        }
    cout << ans << '\n';
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    memset(dp, -1, sizeof(dp));

    for (int i= 0 ; i<LG ; i++){
        for (int j= 0 ; j<LG; j++){
            for (int z = 0 ; z < LG +4; z ++)
                work(i,j,z);
        }
    }
    while (Test_case--) Solve();
}
