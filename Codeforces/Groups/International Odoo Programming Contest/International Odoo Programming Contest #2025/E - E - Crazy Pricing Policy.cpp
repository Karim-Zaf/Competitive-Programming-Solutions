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

void Solve(){
    int n, m;
    cin >> n >> m;

    map<string,int> mp;

    vector<pair<int,int>> vp(n), quer(m);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        mp[s] = i;
        cin >> vp[i].F >> vp[i].S;
    }

    for (int i = 0; i < m; i++){
        string curr;
        cin >> curr;

        string nw = "";

        for (auto x : curr){
            if (x == '_'){
                mp[nw];
                quer[i].F = mp[nw];
                nw = "";
                continue;
            }
            nw += x;
        }
        quer[i].S = mp[nw];
    }

    int res = INF;
    kar(quer);

    for (int mask = 0; mask < (1 << n); mask++){
        int curr_res = 0;
        for (int j = 0; j < n; j++){ if ((1 << j) & mask){ curr_res += vp[j].S; } }
        set<int> seti;
        for (auto [one, two] : quer){
            if ((1 << one) & mask) continue;
            if ((1 << two) & mask) continue;

            seti.insert(one);
            seti.insert(two);
        }
        for (auto x : seti) curr_res += vp[x].F;
        res = min(res, curr_res);
    }
    cout << res << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
