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

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

int n, m, ans = INF;
vector<pair<int, int>> robbers, searchlights, nw;

void overlaps() {
    //elminitaing overlaps ;
    sort(all(searchlights));
    for (auto [one, two]: searchlights) {
        while (!nw.empty() && two >= nw.back().S)nw.pop_back();
        nw.pb({one, two});
    }
    m = nw.size();
    searchlights = nw;
    sort(all(searchlights));
    nw = searchlights;
}


void cost() {
//    robbers = {{1, 6}};
    vector<array<int, 3>> a;
    vector<int> pref(N);
    set<int> s;
    for (int i = 0; i < N; i++)s.insert(i);

    for (auto [x, y]: robbers) {
        pair<int, int> p = {x, -INF};
        int pos = lower_bound(all(searchlights), p) - searchlights.begin();
        int prv = x;
        while (pos < nw.size()) {
            array<int, 3> nw_a;
            int ad = max(0ll, nw[pos].S - y + 1);
            nw_a[0] = ad;
            nw_a[1] = prv- x ;
            nw_a[2] = nw[pos].F -x ;
            prv = nw[pos].F + 1;
            pos++;
            a.pb(nw_a);
        }
    }

    sort(rall(a));
    for (auto [mx, l, r]: a) {
        auto it = s.lower_bound(l);
        set<int> er;
        while (it != s.end() && (*it) <= r) {
            pref[(*it)]= mx ;
            er.insert(*it);
            it ++ ;
        }
        for (auto x: er) s.erase(x);
    }

    //possible transitions to the right
    for (int i = 0; i < N; i++) {
        ans = min(ans, i + pref[i]);
    }

}

void Solve() {

    cin >> n >> m;
    robbers.resize(n);
    searchlights.resize(m);
    for (auto &x: robbers) cin >> x.F >> x.S;
    for (auto &x: searchlights) cin >> x.F >> x.S;

    overlaps();
    cost();

    cout << ans << endl;

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt", "r", stdin);
    freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}