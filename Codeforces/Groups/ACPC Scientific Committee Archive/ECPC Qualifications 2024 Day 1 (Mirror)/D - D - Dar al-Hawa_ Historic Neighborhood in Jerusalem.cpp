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
#define  ld long double

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve() {

    double r;
    int n;
    cin >> r >> n;
    while (n && r >= 0.000001) {

        double hyp = r - sqrt(2) / 2 * r;
        double lef = 0, righ = hyp;

        while (righ - lef >= 0.0000001) {
            double md = lef + (righ - lef) / 2;
            double x = md * sqrt(2) / 2;
            if (md + x >= hyp) {
                righ = md;
                r = md;
            } else lef = md;
        }
        n--;
    }
    cout << fixed << setprecision(6) << r << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
