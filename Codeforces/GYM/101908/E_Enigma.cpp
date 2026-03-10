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
 
map<char, vector<int>> mp;
 
void Solve() {
    string s, a;
    cin >> s >> a;
    vector<pair<int, int>> v;
    for (int j = 0; j < a.size(); j++) mp[a[j]].pb(j);
    for (int i = 0; i < s.size(); i++) {
        int add = 0;
        for (auto x: mp[s[i]]) {
            int l = i - x;
            int r = a.size() - x - 1 + i;
            if (l >= 0 && r < s.size())v.pb({l, r});
        }
    }
    int ans = s.size() - a.size() + 1;
    set<pair<int, int>> ss;
    for (auto x: v) ss.insert(x);
    cout << ans - ss.size() << endl;
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