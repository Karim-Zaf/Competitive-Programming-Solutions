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

int n, k;

bool verif(vector<int>& v) {
    int pref = 0;
    for (auto x : v) {
        pref += x;
        if (pref == k) return false;
    }
    return true;
}

void print(vector<int>& v) {
    for (auto x : v) cout << x << " ";
    cout << endl;
}

void Solve() {
    cin >> n >> k;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    if (verif(v)) return void(print(v));
    sort(all(v));
    if (verif(v)) return void(print(v));
    swap(v[0], v[n - 1]);
    if (verif(v)) return void(print(v));

    sort(all(v));
    int pref = 0;
    for (int i = 0; i < n; i++) {
        pref += v[i];
        if (pref == k) {
            swap(v[i], v[n - 1]);
            break ;
        }
    }

    if (verif(v)) return void(print(v));
    sort(rall(v));
    if (verif(v)) return void(print(v));
    swap(v[0], v[n - 1]);
    if (verif(v)) return void(print(v));

    sort(rall(v));
    pref = 0;
    for (int i = 0; i < n; i++) {
        pref += v[i];
        if (pref == k) {
            swap(v[i], v[n - 1]);
            break ;
        }
    }
    if (verif(v)) return void(print(v));


    sort(all(v));
    pref = 0;
    for (int i = 0; i < n - 1; i++) {
        pref += v[i];
        if (pref == k) {
            swap(v[i], v[i + 1]);
            break ;
        }
    }
    if (verif(v)) return void(print(v));


    sort(rall(v));
    pref = 0;
    for (int i = 0; i < n - 1; i++) {
        pref += v[i];
        if (pref == k) {
            swap(v[i], v[i + 1]);
            break ;
        }
    }
    if (verif(v)) return void(print(v));

    cout << -1 << endl;
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
