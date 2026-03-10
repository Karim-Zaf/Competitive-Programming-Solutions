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

void Solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n + 3), pos(n + 3);
    set<int> lef, used;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        lef.insert(i);
        pos[v[i]] = i;
    }
    int l = 1, r = n + 1, flag = 0;

    while (true) {
        if (r - l == 1)break;
        int m = (r + l) / 2;
        if (v[m] <= x) l = m;
        else r = m;
        lef.erase(v[m]);
        used.insert(x);
    }
    if (lef.find(x) != lef.end() || *lef.begin()>=x || l == pos[x]) {
        cout << 1 << endl;
        cout << pos[x] << " " << l << endl;
        return ;
    }

    // if x found in the path
    // we change the position of it to one less than it

    int mn = *lef.begin() ;
    cout << 2 << endl;
    cout << pos[x]<< " " << l << endl;
    cout << pos[x]<< " " << pos[mn] << endl;

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}