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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

int pref[N], n, q;

int get(int l, int r) {
    return pref[r] - pref[l - 1];
}

int arith(int x) {
    return x * (x - 1) / 2;
}

int work(int pos, int u) {
    int l = pos, r = n, ans = -1;
        int md2 = l + 2 * (r - l) / 3;
    while (l <= r) {
        int md1 = l + (r - l) / 3;
        int md2 = l + 2 * (r - l+1) / 3;
        int one = get(pos, md1);
        int two = get(pos,md2);
        one = u *one - arith (one) ;
        two = u *two - arith (two) ;
        if (one >= two) {
            r = md2 - 1;
            ans = md2;
        } else {
            l = md1 + 1;
            ans = md1;
        }
    }
    return ans;
}

void Solve() {
    cin >> n;
    vector<int> v(n + 20);
    for (int i= 0 ; i<= n +40; i++ )pref[i]= 0 ;
    for (int i = 1; i <= n+10; i++) {
        if (i<=n )cin >> v[i];
        pref[i] = pref[i - 1] + v[i];
    }
    cin >> q;
    while (q--) {
        int l, u;
        cin >> l >> u;
        cout << work(l, u) << " ";
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