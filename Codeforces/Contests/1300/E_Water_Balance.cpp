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
#define ld long double
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;


void Solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++) cin >> v[i];

    vector<ld> ans(n + 4);

    vector<pair<ld, int>> st{{0, n + 1}};

    for (int i = n; i >= 1; i--) {
        int nxt = i;
        ld sum = v[i], curr = v[i];

        while (st.size() > 1 && curr >= st.back().F) {
            auto [val, ind] = st.back();

            int indx = st.size() - 2;
            nxt = st[indx].S - 1;

            sum += val * (nxt - ind + 1);

            curr = sum / (nxt - i + 1);

            st.pop_back();
        }

        sum /= (nxt - i + 1);

        st.pb({sum, i});
    }


    ld prv = -1;
    for (int i = 1; i <= n; i++) {
        if (st.back().S == i) {
            prv = st.back().F;
            st.pop_back();
        }
        ans[i] = prv;
    }
    for (int i = 1; i <= n; i++)
        cout << fixed << setprecision(9) << ans[i] << endl;
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