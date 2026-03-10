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

    int a, b, c, res = 0;
    cin >> a >> b >> c;
    multiset<int> s;

    if (a)s.insert(a);
    if (b)s.insert(b);
    if (c)s.insert(c);

    while (s.size() >=2 ) {
        int one = *prev(s.end());
        int two = *prev(prev(s.end()));

        s.erase(s.find(one));
        s.erase(s.find(two));
        one--;
        two--;
        if (one != 0) {
            s.insert(one);
        }
        if (two != 0) {
            s.insert(two);
        }
        res++;
    }
    if (s.empty() || *s.begin() % 2 == 0) {
        cout << res << endl;
    } else cout << -1 << endl;
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