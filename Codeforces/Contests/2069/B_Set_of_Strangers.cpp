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

void Solve(){
    int n, m;
    cin >> n >> m;
    map<int,int> mp;
    int t[n + 4][m + 4];
    for (int i = 0; i <= n + 2; i++){ for (int j = 0; j <= m + 2; j++){ t[i][j] = 0; } }
    for (int i = 1; i <= n; i++){ for (int j = 1; j <= m; j++){ cin >> t[i][j]; } }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            mp[t[i][j]] = max(1ll, mp[t[i][j]]);
            if (t[i - 1][j] == t[i][j] || t[i + 1][j] == t[i][j] || t[i][j - 1] == t[i][j] || t[i][j + 1] == t[i][j]){
                mp[t[i][j]] = 2;
            }
        }
    }
    vector<int> v;
    for (auto x : mp)v.pb(x.S);
    sort(all(v));
    int sum = accumulate(all(v), 0ll);
    cout << sum - v.back() << endl;;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
