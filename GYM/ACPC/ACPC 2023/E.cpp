/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    string s = "";
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) s += "-";
        else if (v[i] == v[i + 1]) s += "|";
        else s += "+";
    }

    reverse(s.begin(), s.end());
    vector<int> curr = z_function(s);

    sort(curr.begin(), curr.end());

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        x--;
        cout << n - (lower_bound(curr.begin(), curr.end(), x) - curr.begin()) << endl;
    }
}


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
