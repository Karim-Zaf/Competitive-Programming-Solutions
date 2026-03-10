/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

int ask(int i, int x){
    cout << "? " << i << " " << x << endl;
    cout.flush();
    int cur;
    cin >> cur;
    return cur;
}

void ans(int x){
    cout << "! " << x << endl;
    cout.flush();
}

void Solve(){
    int n;
    cin >> n;

    vector<int> poss, indexes;
    for (int i = 1; i <= n; i++) poss.push_back(i);
    for (int i = 1; i < n; i++) indexes.push_back(i);

    int bit = 1;
    while (poss.size() > 1){
        assert(bit <= 1e9);

        array<int, 2> curr{0,0}, expected{0,0};
        array<vector<int>, 2> arr;
        for (auto x : indexes){
            int ans = ask(x, bit);
            arr[ans].pb(x);
            curr[ans]++;
        }

        for (auto x : poss){
            int act = bit & x;
            act = (act == 0 ? 0 : 1);
            expected[act]++;
        }

        int hachti = 0;
        if (expected[1] == curr[1]) hachti = 1;

        vector<int> nw_poss;

        indexes = arr[hachti ^ 1];
        for (auto x : poss){
            int act = bit & x;
            act = (act == 0 ? 0 : 1);

            if (act == (hachti ^ 1)) nw_poss.push_back(x);
        }

        poss = nw_poss;

        bit *= 2ll;
    }

    ans(poss.back());
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
