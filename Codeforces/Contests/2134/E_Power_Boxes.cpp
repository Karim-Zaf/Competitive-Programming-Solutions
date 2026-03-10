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

int ask(int op, int val){
    cout << (op == 0 ? "swap" : "throw") << " " << val << endl;
    cout.flush();
    int ret = -1;
    if (op) cin >> ret;
    return ret;
}

void rep(vector<int> ans){
    cout << "! ";
    for (int i = 1; i < ans.size(); i++)cout << ans[i] << " ";
    cout << endl;
    cout.flush();
}

int tryy(vector<int>& v, int pos){
    int cnt = 0;
    while (pos < v.size()){
        pos += v[pos];
        cnt++;
    }
    return cnt;
}

void Solve(){
    int n;
    cin >> n;

    vector<int> ans(n + 1), curr(n + 1), dp(n + 4);
    dp[n] = 1;
    for (int i = n - 1; i >= 1; i--){
        dp[i] = dp[i + 1] + 1;
        if (dp[i + 1] == dp[i + 2]) continue;
        dp[i] = ask(1, i);

        ans[i] = dp[i] == dp[i + 1] + 1 ? 1 : 2;
    }

    for (int i = 1; i <= n - 2; i++){
        if (ans[i] == 0){
            ask(0, i);
            dp[i + 1] = ask(1, i + 1);
            ans[i] = dp[i + 1] == dp[i + 2] + 1 ? 1 : 2;
        }
    }

    ask(0, n - 1);
    ans[n] = ask(1, n - 1) == 1 ? 2 : 1;

    rep(ans);
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
