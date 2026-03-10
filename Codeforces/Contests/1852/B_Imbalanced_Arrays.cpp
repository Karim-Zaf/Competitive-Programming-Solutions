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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

void Solve() {
    int n, sum  =0;
    cin >> n;
    vector<int> v(n + 1), ans(n + 1);
    set<pair<int, int>> vp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        vp.insert({v[i], i});
    }
    for (int i= n; i>=1 ; i--){
        int curr= sum + i ;
        auto it = vp.lower_bound({curr,-INF});
        auto it2 = vp.lower_bound({sum,-INF});
        if (it != vp.end() && it->F==curr){// adding positif
            ans[it->S]= i ;
            sum++;
            vp.erase(it);
        }else if (it2!=vp.end() && it2->F==sum){ // adding negatif;
            ans[it2->S]= -i;
            vp.erase(it2);
        }else {
            cout << "NO\n";return;
        }
    }

    cout << "YES\n";
    for (int i= 1; i<=n ;i++) cout << ans[i] << " " ; cout << endl;
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