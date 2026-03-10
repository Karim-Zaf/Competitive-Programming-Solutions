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
 
const int LG = 30;
 
int cnt[LG][LG][2][2], dp[LG][LG][2][2];
 
void Solve(){
    int n, ans = 0 ;
    cin >> n;
    vector<int> v(n), mrgl(LG);
    for (auto& x : v) cin >> x;
 
    vector<int> BL(LG), BR(LG);
 
    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
 
    auto bit = [&](int x, int bit){ return ((1 << bit) & x) ? 1 : 0; };
 
    auto highest_bit = [&](int x){ for (int j = LG; j >= 0; j--){ if (bit(x, j)) return j; } };
    for (int i = 0; i < n; i++){
        int HB = highest_bit(v[i]);
        ans += mrgl[HB];
 
        for (int k = 0; k < LG; k++){
            mrgl[k] += cnt[HB][k][0][bit(v[i], k)];
        }
 
 
        for (int j = 0; j < LG; j++){
            for (int k = 0; k < LG; k++){
                cnt[j][k][bit(v[i], j)][bit(v[i], k)]++;
            }
        }
    }
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