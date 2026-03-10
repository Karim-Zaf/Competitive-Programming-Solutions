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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 2e18 + 10;

const int LG = 62;

void Solve(){
    int m, s;
    cin >> s >> m;
    int l = 0, r = INF, ans = -1;

    auto work = [&](int md){
        vector<int> mp(2 * LG);

        for (int i = 0; i < LG; i++){ if ((1ll << i) & m) mp[i] = md; }
        // kar(mp);
        for (int i = 0; i < LG; i++){
            if ((1ll << i) & s){
                if (!mp[i])return false;
                mp[i]--;
            }
            mp[i + 1] += mp[i] / 2;
            mp[i + 1] = min(mp[i + 1], INF);
        }
        return true;
    };

    // cout << work(1)<< endl;
    while (l <= r){
        int md = l + (r - l) / 2;
        if (work(md)){
            ans = md;
            r = md - 1;
        }
        else l = md + 1;
    }

    cout << ans << endl;
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
