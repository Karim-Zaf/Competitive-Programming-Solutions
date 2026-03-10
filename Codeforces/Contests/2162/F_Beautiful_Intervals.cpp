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
    /*
     * if intersection >= 1 : ans = 0 : put the 0 of the permutation in the intersection
     *
     * else ans= 2 ; place the 0 at the most left and the 1 in most right
     */
    int all_l = -INF, all_r = INF;

    int n, m;
    cin >> n >> m;
    vector<int> ans(n);
    vector<pair<int,int>> intervals(m);
    for (auto& [l,r] : intervals) cin >> l >> r;
    for (auto& [l,r] : intervals){
        l--;
        r--;
        all_l = max(all_l, l);
        all_r = min(all_r, r);
    }

    if (all_l <= all_r){
        // ans = 0 ;
        int cnt = 1;

        for (int i = 0; i < n; i++){
            if (i == all_l) continue;
            ans[i] = cnt++;
        }
        for (auto x : ans) cout << x << " ";
        cout << endl;
        return;
    }

    map<int,int> lef, righ;
    for (auto [l,r] : intervals){
        lef[l] = 1;
        righ[r] = 1;
    }

    // ans = 1 ;

    for (int i = 0; i < n; i++){ // choose 0 position
        // the position of 1 is either left either right
        // but it couldn't be booth ya haj ;)

        int cnt = 2;
        if (lef[i] && righ[i]) continue;
        if (lef[i]){ ans[i + 1] = 1; }
        else if (righ[i]) ans[i - 1] = 1;
        else cnt = 1 ;

        for (int j = 0; j < n; j++){
            if (ans[j] || j == i) continue;
            ans[j] = cnt++;
        }

        for (auto x : ans) cout << x << " ";
        cout << endl;
        return;
    }

    // ans = 2 ;

    for (int i = 0; i < n - 1; i++) ans[i] = i + 1;
    for (auto x : ans) cout << x << " ";
    cout << endl;
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
