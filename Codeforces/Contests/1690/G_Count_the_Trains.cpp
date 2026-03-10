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
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    map<int, int> lst_pos;
    set<pair<int, int>> s;

    for (int i = 1; i <= n; i++)cin >> v[i];

    s.insert({n + 1, -INF});

    for (int i = n; i >= 1; i--) {
        while (v[i] <= s.begin()->S) s.erase(*s.begin());
        s.insert({i, v[i]});
    }
    s.insert({0, INF});


    while (q--) {
        int k, d;
        cin >> k >> d;

        v[k] -= d;

        pair<int, int> p = {k, -INF};
        auto it = s.lower_bound(p);

        set<pair<int,int>> er ;

        while(it->S >= v[k])er.insert(*it++);

        for (auto x: er) s.erase(x) ;

        if (v[k] < prev(it)->S) s.insert({k, v[k]}) ;
        cout << s.size() -2<< " ";
    }
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