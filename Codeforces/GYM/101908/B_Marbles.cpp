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
 
int Grundy[105][105], vis[105][105];
 
void Solve() {
    int n, mex = 0;
    cin >> n;
 
    queue<pair<int, int>> q;
    q.push({0, 0});
 
    for (int i = 0; i <= 100; i++) Grundy[i][i] = Grundy[0][i] = Grundy[i][0] = INF;
 
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x > 100 || y > 100 || vis[x][y]) continue;
        vis[x][y] = 1;
        q.push({x, y + 1});
        q.push({x + 1, y});
        q.push({x + 1, y + 1});
        if (x == y || x == 0 || y == 0)continue;
 
        set<int> s;
        for (int i = x - 1; i >= 0; i--) s.insert(Grundy[i][y]);
        for (int j = y - 1; j >= 0; j--) s.insert(Grundy[x][j]);
 
        for (int k = 1;; k++) {
            if (x - k < 0 || y - k < 0) break;
            s.insert(Grundy[x - k][y - k]);
        }
 
        vector<int> v;
        for (auto xx: s) v.pb(xx);
 
        for (int i = 0; i <= v.size(); i++) {
            if (i == v.size())Grundy[x][y] = i;
            else if (v[i] != i) {
                Grundy[x][y] = i;
                break;
            }
        }
    }
 
//    for (int i = 0; i <= 100; i++) {
//        for (int j = 0; j <= 100; j++) {
//            cout << Grundy[i][j] << " ";
//        }
//        cout << endl;
//    }
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (x == y || x == 0 || y == 0) {
            cout << 'Y' << endl;
            return;
        }
        mex ^= Grundy[x][y];
    }
    cout << (mex ? 'Y' : 'N');
}
 
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}