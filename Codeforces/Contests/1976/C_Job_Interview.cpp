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
    int n, m;
    cin >> n >> m;
    int n_emp = n + m + 1;
    vector<int> v(n_emp + 1), a(n_emp + 1), b(n_emp + 1), res(n_emp + 1), pref(n_emp + 2);
    vector<int> suff_test(n_emp + 2), suff_prog(n_emp + 2), pref_test(n_emp + 2), pref_prog(n_emp + 2);
    for (int i = 1; i <= n_emp; i++) cin >> a[i];
    for (int i = 1; i <= n_emp; i++) cin >> b[i];

    map<int, int> mp_prog, mp_test;
    for (int i = 1; i <= n_emp; i++) {
        if (a[i] > b[i]) {// you are programmer
            pref_prog[i]++;
            pref[i] += a[i];
        } else {
            pref_test[i]++;
            pref[i] += b[i];
        }
        pref_prog[i] += pref_prog[i - 1];
        pref_test[i] += pref_test[i - 1];
        pref[i] += pref[i - 1];
    }
    for (int i = 0; i <= n_emp; i++) {
        if (!mp_prog[pref_prog[i]]) mp_prog[pref_prog[i]] = i;
        if (!mp_test[pref_test[i]]) mp_test[pref_test[i]] = i;
    }
    for (int j = pref_test[n_emp] + 1; j <= n_emp + 1; j++)mp_test[j] = INF;
    for (int j = pref_prog[n_emp] + 1; j <= n_emp + 1; j++)mp_prog[j] = INF;

    for (int i = n_emp; i >= 1; i--) {
        suff_prog[i] += a[i];
        suff_test[i] += b[i];
        suff_prog[i] += suff_prog[i + 1];
        suff_test[i] += suff_test[i + 1];
    }


    for (int i = 1; i <= n_emp; i++) {
        int needed_prog = n;
        int needed_test = m;

        if (a[i] > b[i]) {// you are programmer
            if (mp_prog[n] >= i) needed_prog++;
        } else {
            if (mp_test[m] >= i) needed_test++;
        }


        int ans_prog = mp_prog[needed_prog], ans_test = mp_test[needed_test];

        if (needed_test == 0) ans_test = 0;
        if (needed_prog == 0) ans_prog = 0;

        int pos = min(ans_prog, ans_test);

        if (ans_prog <= ans_test) {
            res[i] += pref[pos] + suff_test[pos + 1];
            if (pos >= i) res[i] -= max(a[i], b[i]);
            if (i >= pos + 1) res[i] -= b[i];
        } else {
            res[i] += pref[pos] + suff_prog[pos + 1];
            if (pos >= i) res[i] -= max(a[i], b[i]);
            if (i >= pos + 1) res[i] -= a[i];
        }
    }

    for (int i = 1; i <= n_emp; i++) cout << res[i] << " ";
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