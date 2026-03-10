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
    vector<int> v(n), res(n);

    for (int i = 0; i < n; i++)cin >> v[i];

    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] == -1)continue;
        if (prev == -1) prev = i;
        if (prev == i-1){
            res[i]=v[i];
            prev = i ;
            continue;
        }
        if (i==prev) continue;
        vector<int> curr;
        map<int, int> mp;
        int tkabel = 1;
        int x = v[i];
        curr.pb(v[i]);
        while (x / 2 >= 1) {
            x /= 2;
            curr.pb(x);
        }
        x = v[prev];
        vector<int> nw;
        nw.pb(x);
        while (x / 2 >= 1) {
            x /= 2;
            nw.pb(x);
        }
        for (auto x: nw) mp[x]++;
        for (auto x: curr) mp[x]++;
        for (auto x: mp) {
            if (x.S >= 2) {
                tkabel = x.F;
            }
        }

        while (!curr.empty() && curr.back() <= tkabel)curr.pop_back();
        while (!nw.empty() && nw.back() <= tkabel)nw.pop_back();
        curr.pb(tkabel);
        reverse(all(nw));
        int indx = 0;
        array<int, 2> alternate = {tkabel * 2, tkabel};
        if (alternate[0] > 1e9) alternate[0] = tkabel / 2;
        while (curr.size() + nw.size() < (i - prev + 1)) {
            curr.pb(alternate[indx] );
            indx ^= 1;
        }
        for (auto x: nw) curr.pb(x);
        reverse(all(curr));

        if (curr.size() > (i - prev + 1) || curr.empty()) {
            cout << -1 << endl;
            return;
        }
        for (int j = prev, indx = 0; j <= i; j++) {
            int pos = j - prev;
            if (pos < curr.size()) res[j] = curr[pos];
            else {
                res[j] = alternate[indx];
                indx ^= 1;
            }
        }

        prev = i;
    }

    int pos = 0;

    while (pos < n && v[pos] == -1)pos++;

    if (pos == n) {
        for (int i = 1; i <= n; i++)cout << (i % 2 + 1) << " ";
        cout << endl;
        return;
    }
    array<int, 2> alternate{v[pos], v[pos] * 2};
    if (alternate[1] > 1e9) alternate[1] = v[pos] / 2;
    for (int i = pos, indx = 0; i >= 0; i--) {
        res[i] = alternate[indx];
        indx ^= 1;
    }
    pos = n - 1;
    while (pos >= 0 && v[pos] == -1) {
        pos--;
        assert (pos >= 0);
    }

    alternate = {v[pos], v[pos] * 2};
    if (alternate[1] > 1e9) alternate[1] = v[pos] / 2;
    for (int i = pos, indx = 0; i < n; i++) {
        res[i] = alternate[indx];
        indx ^= 1;
    }
    for (int i = 0; i < n; i++) {
        if (v[i]!=-1) res[i]=v[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (res[i] == (res[i + 1] / 2) || res[i + 1] == (res[i] / 2)) continue;
        cout << -1 << endl;
        return;
    }
    for (auto x: res) cout << x << " ";

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