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
    string s, res = "";
    cin >> n >> s;
    res = s;
    map<char, int> mp;
    for (auto c: s) {
        mp[c]++;
    }

    if (abs(mp['S'] - mp['N']) % 2 || abs(mp['W'] - mp['E']) % 2) {
        cout << "NO\n";
        return;
    }


    int &louta = mp['S'], &fouk = mp['N'];

    int mn = min(louta, fouk), cnt1 = 0, cnt2 = 0;

    for (int i = 0, indx1 = 0, indx2 = 0; i < n; i++) {
        if (s[i] == 'N' && cnt1 < mn) {
            if (indx1) res[i] = 'R';
            else res[i] = 'H';
            indx1 ^= 1;
            cnt1++;
        }
        if (s[i] == 'S' && cnt2 < mn) {
            if (indx2) res[i] = 'R';
            else res[i] = 'H';
            indx2 ^= 1;
            cnt2++;
        }
    }

    louta -= mn;
    fouk -= mn;
    cnt1 = cnt2 = 0;
    kar (cnt1);
    for (int i = 0; i < n; i++) {
        kar ((res[i] == 'S' || res[i] == 'N'));
        if (fouk && cnt1 < fouk / 2 && (res[i] == 'S' || res[i] == 'N')) res[i] = 'H', cnt1++;
        else if (fouk && (res[i] == 'S' || res[i] == 'N')) res[i] = 'R', cnt1++;

        if (louta && cnt1 < louta / 2 && (res[i] == 'S' || res[i] == 'N')) res[i] = 'H', cnt1++;
        else if (louta && (res[i] == 'S' || res[i] == 'N')) res[i] = 'R', cnt1++;
    }

// ------------------------------------------------------------------------------

    louta = mp['E'], fouk = mp['W'];

    mn = min(louta, fouk), cnt1 = 0, cnt2 = 0;

    for (int i = 0, indx1 = 1, indx2 = 1; i < n; i++) {
        if (s[i] == 'E' && cnt1 < mn) {
            if (indx1) res[i] = 'R';
            else res[i] = 'H';
            indx1 ^= 1;
            cnt1++;
        }
        if (s[i] == 'W' && cnt2 < mn) {
            if (indx2) res[i] = 'R';
            else res[i] = 'H';
            indx2 ^= 1;
            cnt2++;
        }
    }

    louta -= mn;
    fouk -= mn;
    cnt1 = cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (fouk && cnt1 < fouk / 2 && (res[i] == 'E' || res[i] == 'W')) res[i] = 'H', cnt1++;
        else if (fouk && (res[i] == 'E' || res[i] == 'W')) res[i] = 'R', cnt1++;
        if (louta && cnt1 < louta / 2 && (res[i] == 'E' || res[i] == 'W')) res[i] = 'H', cnt1++;
        else if (louta && (res[i] == 'E' || res[i] == 'W')) res[i] = 'R', cnt1++;
    }

    if (count(all(res), 'R') == res.size()) {
        cout << "NO\n";
        return;
    }
    if (count(all(res), 'H') == res.size()) {
        cout << "NO\n";
        return;
    }
    cout << res << endl;
}

// NSWE

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}