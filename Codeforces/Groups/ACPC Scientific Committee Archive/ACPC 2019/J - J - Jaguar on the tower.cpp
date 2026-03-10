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

    int n, x, y, ans = 0;
    cin >> n >> x >> y;
    vector<array<int, 3>> v(n);
    for (auto& i : v) cin >> i[0] >> i[1] >> i[2];

    map<double, vector<array<int, 3>>> mp;

    for (auto [xx,yy,h] : v) {
        double fouk = (yy - y);
        double louta = (xx - x);

        if (louta == 0) {
            mp[INF].pb({xx, yy, h});
        } else {
            double pente = fouk / louta;
            mp[pente].pb({xx, yy, h});
        }
    }


    auto inc = [](vector<int>& v)-> int {
        int mx = -INF, cnt = 0;
        for (auto x : v) {
            if (x > mx) {
                mx = x;
                cnt++;
            }
        }
        return cnt;
    };

    for (auto [p , vect] : mp) {
        vector<int> p1, p2;
        if (p == INF) {
            sort(all(vect), [](array<int, 3> a, array<int, 3> b) {
                if (a[1] < b[1]) return true;
                return false;
            });

            for (auto [xx,yy,h] : vect) {
                if (yy < y) p1.pb(h);
                else p2.pb(h);
            }
        } else {
            sort(all(vect));
            for (auto [xx,yy,h] : vect) {
                if (xx < x) p1.pb(h);
                else p2.pb(h);
            }
        }
        reverse(all(p1));

        ans += inc(p1);
        ans += inc(p2);
    }

    cout << ans << endl;

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
#endif
    freopen("jaguar.in", "r",stdin);
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
