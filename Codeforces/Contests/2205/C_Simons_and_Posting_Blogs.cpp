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
    int n;
    cin >> n;

    vector<deque<int>> v(n);
    set<deque<int>> s;

    for (auto& x : v){
        int sz;
        cin >> sz;
        x.resize(sz);
        for (auto& y : x) cin >> y;
        reverse(x.begin(), x.end());
    }
    for (auto& x : v){
        map<int,int> curr;
        deque<int> nw;
        for (auto y : x){
            if (!curr[y])nw.push_back(y);
            curr[y] = 1;
        }
        x = nw;
        s.insert(x);
    }
    sort(all(v));

    vector<int> ans;
    map<int,int> mp;

    while (!s.empty()){
        auto dq = *s.begin();
        s.erase(*s.begin());

        for (auto x : dq){
            if (!mp[x]){ ans.push_back(x); }
            mp[x] = 1;
        }

        set<deque<int>> nw_s;
        for (auto& x : s){
            deque<int> nw;
            for (auto y : x){ if (!mp[y])nw.push_back(y); }
            nw_s.insert(nw);
        }
        s = nw_s;
    }

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
