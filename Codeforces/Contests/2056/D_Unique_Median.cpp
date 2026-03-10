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
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    int ans = 0, prv = 0;

    for (int i = 1; i <= 10; i++){
        vector<int> curr = v, pref(n + 3);
        for (auto& x : curr){
            if (x <= i) x = -1;
            else x = 1;
        }
        for (int j = 1; j <= n; j++){ pref[j] = pref[j - 1] + curr[j]; }

        map<int, vector<int>> mp;

        mp[0].pb(0);

        int lst = -1;
        int curr_ans = 0;

        for (int j = 1; j <= n; j++){
            if (v[j] == i){ lst = j; }
            curr_ans += lower_bound(all(mp[pref[j]]), lst) - mp[pref[j]].begin();

            mp[pref[j]].pb(j);
        }

        ans += curr_ans;
    }
    cout << (n * (n + 1) / 2) - ans << endl;
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
