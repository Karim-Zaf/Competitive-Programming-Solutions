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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v(n + 2);
    v[0] = -INF;
    v[n + 1] = +INF;
    for (int i = 1; i <= n; i++) cin >> v[i];

    sort(all(v));
    int l = 0, r = 1e9 + 3, ans = -1;
    while (l <= r){
        int md = l + (r - l) / 2;

        int cnt = 0;
        for (int i = 1; i < n + 2; i++){
            int l = v[i - 1] + md;
            int r = v[i] - md;
            l = max(l, 0ll);
            r = min(r, x);
            cnt += max(0ll, r - l + 1);
        }

        if (cnt >= k){
            ans = md;
            l = md + 1;
        }
        else r = md - 1;
    }

    int lst = -1;
    for (int i = 1; i < n + 2; i++){
        int l = v[i - 1] + ans;
        int r = v[i] - ans;
        l = max(l, lst + 1);
        r = min(r, x);
        for (int j = l; j <= r; j++){
            lst = j;

            cout << j << " ";
            k--;
            if (k == 0)return void(cout << endl);
        }
    }
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
