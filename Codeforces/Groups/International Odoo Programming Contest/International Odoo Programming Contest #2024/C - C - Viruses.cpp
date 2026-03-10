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
    int n, m, q;
    cin >> n >> m >> q;
    map<int, array<int, 2>> modules;
    map<string, int> id;
    map<int, string> conv;
    vector<pair<int, int>> vp;
    vector<array<int, 3>> cap[m + 4];

    set<int> ans;
    for (int i = 1; i <= n; i++) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        id[s] = i;
        conv[i] = s;
        modules[i] = {a, b};
        ans.insert(i);
    }

    for (int i = 1; i <= m; i++) {
        int idd, pos;
        cin >> idd >> pos;
        vp.pb({pos, idd});
    }

    sort(all(vp));
    for (int i = 1; i <= q; i++) {
        int idd, oth;
        string s;
        cin >> idd >> s >> oth;
        cap[idd].pb({modules[id[s]][1], id[s], oth});
    }
    for (int i = 1; i <= m; i++) {
        sort(rall(cap[i]));
    }
    for (auto [pos, virus]: vp) {
        kar (cap[virus]);

        for (auto [blasa, md, pow]: cap[virus]) {
            if (blasa > pos) continue;
            if (ans.find(md) == ans.end())continue;
            if (pow == modules[md][0]) {
                ans.erase(md);
                break;
            }
            if (pow > modules[md][0]) {
                ans.erase(md);
            } else {
                modules[md][0] -= pow;
                break;
            }
        }
    }

    cout << ans.size() << endl;

    vector<pair<int,int>> res ;
    for (auto x: ans) res.pb({modules[x][1],x});
    sort (rall(res));

    for (auto x: res) cout << conv[x.S] << " ";
    cout << endl;
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