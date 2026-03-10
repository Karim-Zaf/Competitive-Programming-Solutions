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
    int n;
    cin >> n;
    vector<int> ans(n, INF), value(n + 1, -1), keys;
    vector<array<int, 4>> v(n);

    multiset<int> s, inter_color[n + 1];
    map<int, vector<array<int, 4>>> lef, righ;
    set<int> keyss;

    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        v[i][3] = i;
        lef[v[i][0]].pb(v[i]);
        righ[v[i][1]].pb(v[i]);
        keyss.insert(v[i][0]), keyss.insert(v[i][1]);
    }
    for (auto x: keyss)keys.pb(x);


    // nearest segment at the left of the segment
    for (auto key: keys) {
        auto &vect_righ = righ[key];
        auto &vect_lef = lef[key];


        for (auto [l, r, color, indx]: vect_righ) {
            if (value[color] != -1) s.erase(s.find(value[color]));
            value[color] = r;
            s.insert(r);
        }

        for (auto [l, r, color, indx]: vect_lef) {
            if (value[color] != -1) s.erase(s.find(value[color]));

            if (!s.empty()) ans[indx] = min(ans[indx], l - *prev(s.end()));

            if (value[color] != -1) s.insert(value[color]);
        }

    }

    fill(all(value), -1);
    s.clear();

    // if there is a segment inside me the answer is 0
    for (auto key: keys) {
        auto &vect_righ = righ[key];
        auto &vect_lef = lef[key];

        for (auto [l, r, color, indx]: vect_lef) {
            if (value[color] != -1) s.erase(s.find(value[color]));

            inter_color[color].insert(r);

            value[color] = *inter_color[color].begin();
            s.insert(value[color]);
        }

        for (auto [l, r, color, indx]: vect_lef) {
            if (value[color] != -1) s.erase(s.find(value[color]));

            if (!s.empty()) ans[indx] = 0;

            if (value[color] != -1) s.insert(value[color]);
        }

        for (auto [l, r, color, indx]: vect_righ) {
            if (value[color] != -1) s.erase(s.find(value[color]));

            if (!s.empty()) ans[indx] = 0;

            if (value[color] != -1) s.insert(value[color]);
        }

        for (auto [l, r, color, indx]: vect_righ) {
            if (value[color] != -1) s.erase(s.find(value[color]));

            inter_color[color].erase(inter_color[color].find(r));

            if (!inter_color[color].empty()) value[color] = *inter_color[color].begin();
            else value[color] = -1;

            if (value[color] != -1) s.insert(value[color]);
        }

    }

    sort(rall(keys));
    fill(all(value), -1);
    s.clear();


    // nearest segment at the right of the segment
    for (auto key: keys) {
        auto &vect_lef = lef[key];
        auto &vect_righ = righ[key];

        for (auto [l, r, color, indx]: vect_lef) {
            if (value[color] != -1) s.erase(s.find(value[color]));
            value[color] = l;
            s.insert(l);
        }

        for (auto [l, r, color, indx]: vect_righ) {
            if (value[color] != -1) s.erase(s.find(value[color]));

            if (!s.empty()) ans[indx] = min(ans[indx], *s.begin() - r);
            if (value[color] != -1) s.insert(value[color]);
        }

    }


    fill(all(value), -1);
    s.clear();


    // inclus bkollou
    for (auto key: keys) {
        auto &vect_righ = righ[key];
        auto &vect_lef = lef[key];

        for (auto [l, r, color, indx]: vect_lef) {
            if (value[color] != -1) s.erase(s.find(value[color]));
            else value[color] = INF;
            value[color] = min(value[color], r);
            s.insert(value[color]);
        }
        for (auto [l, r, color, indx]: vect_lef) {
            s.erase(s.find(value[color]));
            if (!s.empty() && *s.begin() <= r) ans[indx] = 0;
            s.insert(value[color]);
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

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