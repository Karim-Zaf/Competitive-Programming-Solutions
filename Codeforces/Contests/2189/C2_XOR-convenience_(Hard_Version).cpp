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
    vector<int> v;

    if (n % 2){
        v.pb(1);
        for (int i = 2; i <= n; i++){ v.pb(i ^ 1); }
        swap(v[n - 1], v[0]);
        for (auto x : v) cout << x << " ";
        cout << endl;
        return;
    }

    v.resize(n + 1);
    int pos = n ^ 1;
    for (int i = 40; i >= 0; i--){
        if ((1ll << i) & n){
            pos ^= (1ll << i);
            break;
        }
    }
    if (pos > n) return void(cout << -1 << endl);

    v[n] = 1;
    v[1] = n;
    for (int i = n - 1; i >= 2; i--){ v[i] = i ^ 1; }

    swap(v[pos], v[1]);

    set<int> s{1};

    for (int i = n - 1; i >= 1; i--){
        if (s.find(v[i] ^ i) == s.end())
            return void(cout << -1 << endl);
        s.insert(v[i]);
    }
    for (int i = 1; i <= n; i++) cout << v[i] << " ";
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
