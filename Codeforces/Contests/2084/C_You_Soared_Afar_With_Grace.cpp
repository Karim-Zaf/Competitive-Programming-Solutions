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
    vector<int> a(n + 1), b(n + 1);
    map<pair<int,int>,int> mp;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) mp[{a[i], b[i]}]++;

    int doubl = 0;
    for (auto [p, cnt] : mp){
        auto [x,y] = p;

        if (mp[{y, x}] != 1) return void(cout << -1 << endl);
        doubl += (x == y);
    }

    if (doubl != n % 2) return void(cout << -1 << endl);

    vector<pair<int,int>> ans;
    set<int> nb;
    map<int,int> rev;
    vector<int> pos(n + 1);

    for (int i = 1; i <= n; i++) pos[a[i]] = i;

    for (int i = 1; i <= n; i++){
        if (a[i] == b[i]) continue;
        rev[min(a[i], b[i])] = max(a[i], b[i]);
        nb.insert(min(a[i], b[i]));
    }

    for (auto x : nb){
        int p1 = pos[x], p2 = pos[rev[x]];
        if (n % 2 && p1 == (n + 1) / 2) swap(p1, p2);
        int desired = n + 1 - p1;
        if (p2 == desired)continue;
        ans.pb({p2, desired});

        int one = a[p2], two = a[desired];
        swap(pos[one], pos[two]);
        swap(a[p2], a[desired]);
    }

    kar(a);
    cout << ans.size() << endl;
    for (auto [x,y] : ans) cout << x << ' ' << y << endl;
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
