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

vector<array<int, 3>> ans;
int n, xr=0;
vector<int> v, p;
map<int, set<int>> mp;


void work(vector<int> &p) {
    int m = p.size();
    for (int i = 0; i + 2 < m; i += 2)
        ans.pb({p[i], p[i + 1], p[i + 2]});
    for (int i = 0; i + 2 < m; i += 2)
        ans.pb({p[i], p[i + 1], p[m - 1]});

    assert(ans.size() <= n);
    cout << "YES\n";
    cout << ans.size() << endl;
    for (auto [x, y, z]: ans)
        cout << x << " " << y << " " << z << endl;
    for (auto [x, y, z]: ans){
        int xr = v[x]^v[y]^v[z];
        v[x]=v[y]=v[z]=xr;
    }
    set<int>s;
    for (int i= 1; i<=n ; i++)s.insert(v[i]);
    assert(s.size()==1);
}

void Solve() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]].insert(i);
        xr^=v[i];
    }
    if (n % 2) {
        for (int i = 1; i <= n; i++)p.pb(i);
        work(p);
        return;
    }

    for (int i=1; i<=n; i++){
        if ((v[i]^xr)!=v[i])continue;
        for (int j= 1; j<=n ; j++)
            if(j!=i)p.pb(j);
        work(p);
        return;
    }
    cout << "NO\n";
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