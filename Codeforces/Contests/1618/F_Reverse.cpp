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

int x, y;

bool work(int x, bool flag) {
    if (x==y) return true;

    int nw_x = x;
    for (int i = 0; i <= 61; i++) {
        if (!flag && i==0){
            nw_x*=2 ; nw_x++ ;
        }

        int lg;
        for (int k = 0; k <= 60; k++) {
            if ((1ll << k) & nw_x) lg = k;
        }
        int nw_nw_x = nw_x;
        for (int j = lg + 1; j <= 61; j++) {
            if (nw_nw_x == y) return true;
            nw_nw_x += (1ll << j);
        }
        nw_x *= 2;
        nw_x++;// 1 at the right
        if (nw_x == y) return true;
    }

    return false;
}

void Solve() {
    cin >> x >> y;
//
//    cout << bitset<60>(x) << endl;
//    cout << bitset<60>(y) << endl;

    if (work(x,x%2!=0)) {
        cout << "YES\n";
        return;
    }

    string xx = "";
    for (int i = 60; i >= 0; i--) {
        if ((1ll << i) & x) xx += "1";
        else xx += "0";
    }
    while (xx.back() == '0') xx.pop_back();
    reverse(all(xx));
    while (xx.back() == '0') xx.pop_back();

    int nw_x = 0;
    for (int i = 0; i < xx.size(); i++) {
        nw_x += (1ll << i) * (xx[i] - '0');
    }
    if (work(nw_x,1)) {
        cout << "YES\n";
        return;
    }

    reverse(all(xx));

    nw_x = 0;
    for (int i = 0; i < xx.size(); i++) {
        nw_x += (1ll << i) * (xx[i] - '0');
    }
    if (work(nw_x,1)) {
        cout << "YES\n";
        return;
    }


    x*=2 ;
    x++ ;
    xx = "";
    for (int i = 60; i >= 0; i--) {
        if ((1ll << i) & x) xx += "1";
        else xx += "0";
    }
    while (xx.back() == '0') xx.pop_back();
    reverse(all(xx));
    while (xx.back() == '0') xx.pop_back();
    reverse(all(xx));

    nw_x = 0;
    for (int i = 0; i < xx.size(); i++) {
        nw_x += (1ll << i) * (xx[i] - '0');
    }
    if (work(nw_x,1)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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