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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    vector<array<int, 4>> b(n);
    for (int i = 0; i < n; i++) cin >> b[i][1] >> b[i][2] >> b[i][3];
    for (int i = 0; i < n; i++) b[i][0] = b[i][3] - b[i][2];
    sort(rall(b));

    int ans = 0;
    multiset<int> s(all(a));
    vector<int> zeyed;
    for (auto& [val ,x,y,z] : b){
        k -= y;
        auto it = s.lower_bound(x);
        if (it == s.end()){
            zeyed.push_back(val);
            continue;
        };
        s.erase(s.find(*it));
        ans++;
    }
    sort(all(zeyed));

    kar(zeyed);
    for (auto x : zeyed){
        if (k >= x){
            ans++;
            k -= x;
        }
    }

    cout << (k < 0 ? 0 : ans) << endl;
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
