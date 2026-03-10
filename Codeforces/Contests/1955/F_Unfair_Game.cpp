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
    int one, two, three, four, ans = 0;
    cin >> one >> two >> three >> four;
//
//    string s = "";
//    s += char(one % 2 + '0');
//    s += char(two % 2 + '0');
//    s += char(three % 2 + '0');
//    s += char(four % 2 + '0');
    if (one % 2 && two % 2 && three % 2) ans++;

    one -= one % 2;
    two -= two % 2;
    three -= three % 2;
    four -= four % 2;

//    if (!one && !two && !three && !four) ans++;
    kar (one,two,three);
    int mn = min({one, two, three});
    ans += four / 2;
//    ans += mn ;
    kar (ans);

//    one -= mn;
//    two -= mn;
//    three -= mn;

    ans += one / 2;
    ans += two / 2;
    ans += three / 2;

    cout << ans << endl;

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