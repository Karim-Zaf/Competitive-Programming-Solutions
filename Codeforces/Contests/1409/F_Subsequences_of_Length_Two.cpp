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

const int M = 205;
int dp[M][M][M];

string s;
char a, b;
int work(int pos, int nb_a, int operation){
    if (operation < 0)return -INF;
    if (pos >= s.size()) return 0;

    int& ret = dp[pos][nb_a][operation];
    if (ret != -1) return ret;

    ret = 0;

    // skip
    ret = max(ret, (s[pos] == b ? nb_a : 0) + work(pos + 1, nb_a + (s[pos] == a), operation));

    // make it a
    ret = max(ret, work(pos + 1, nb_a + 1, operation - 1));

    // make it b
    ret = max(ret, nb_a + work(pos + 1, nb_a, operation - 1));

    return ret;
}

void Solve(){
    int n, k;
    cin >> n >> k;
    cin >> s >> a >> b;

    memset(dp, -1, sizeof(dp));

    if (a == b){
        int sum = count(all(s), a);
        sum += k;
        sum = min(sum, n);
        cout << sum * (sum - 1) / 2 << endl;
        return;
    }
    if (k == 0){
        int prev = 0, ans = 0;
        for (auto x : s){
            prev += (x == a);
            if (x == b) ans += prev;
        }
        cout << ans << endl;
        return;
    }

    cout << work(0, 0, k) << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
