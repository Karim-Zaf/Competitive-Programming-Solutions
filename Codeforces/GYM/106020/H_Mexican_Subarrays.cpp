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
    int n, ans = 0;
    cin >> n;
 
    vector<int> v(n + 1), pref(n + 1);
 
    map<int, vector<int>> mp;
    vector<int> prv(n + 1), nxt(n + 1);
 
    int lst = 0;
 
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i];
 
    for (int i = 1; i <= n; i++){
        prv[i] = lst;
        if (v[i] != 0) lst = i;
    }
 
    for (int i = 1; i <= n; i++){
        mp[v[i]].pb(i);
 
        //110
        auto ok1 = [&]()-> int{
            if (mp[1].size() < 2)return 0;
            if (mp[0].empty())return 0;
 
            int sz = mp[1].size();
            int mn = min({mp[1][sz - 2], mp[1].back(), mp[0].back()});
            int sum = pref[i] - pref[mn - 1];
 
            if (sum != 2) return 0;
            return mn - prv[mn];
        };
 
        //210;
        auto ok2 = [&]()-> int{
            if (mp[2].empty())return 0;
            if (mp[1].empty())return 0;
            if (mp[0].empty())return 0;
 
            int mn = min({mp[2].back(), mp[1].back(), mp[0].back()});
            int sum = pref[i] - pref[mn - 1];
 
            if (sum != 3) return 0;
            return mn - prv[mn];
        };
        ans += ok1() + ok2();
    }
    cout << ans << endl;
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