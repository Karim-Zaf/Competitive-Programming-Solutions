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
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

const int M = 365;
vector<pair<int,int>> vp;
int n, k;

int dp[M][M][M][2];
vector<int> v;

int work(int indx, int rem, int prv, int flag = 1){
    // cout << indx << " " << rem << " " << prv << endl;

    if (rem < 0) return -INF;
    if (indx >= vp.size()) return 0;
    int& ret = dp[indx][rem][prv][flag];
    if (ret != -1) return ret;
    ret = 0;

    auto [value, occ] = vp[indx];

    ret = max(ret, work(indx + 1, rem, prv));
    if (prv < value){
        ret = max(ret, occ + work(indx + 1, rem - (flag ? prv + 1 : 1), prv + 1, 1));
        ret = max(ret, occ + work(indx, rem - (flag ? prv + 1 : 1), prv + 1, 0));
    }

    // if (indx > 0) prv = vp[indx - 1].F;
    // kar(prv);
    // for (int j = prv; j <= value; j++){
    //     int diff = j - prv;
    //     ret = max(ret, diff * occ + work(indx + 1, rem - j));
    // }

    return ret;
}

void Solve(){
    cin >> n >> k;

    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= k; j++){
            for (int z = 0; z <= k; z++)

                dp[i][j][z][0] = dp[i][j][z][1] = -1;
        }

    v.resize(n + 1);
    vp.clear();
    for (int i = 1; i <= n; i++)cin >> v[i];

    int suff_mx = -1;
    for (int i = 1; i <= n; i++){
        if (v[i] > suff_mx){
            vp.pb({v[i], n - i + 1});
            suff_mx = v[i];
        }
    }

    kar(vp);
    kar(work(0,k,0));

    cout << work(0, k, 0) << endl;
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
