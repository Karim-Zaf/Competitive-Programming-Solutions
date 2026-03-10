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
    vector<int> v(n + 4);
 
    for (int i = 1; i <= n; i++) cin >> v[i];
 
    // zero
 
    int l1 = 0, r1 = -1, l2 = -1, r2 = -1;
    for (int i = 1; i <= n; i++){
        if (v[i] == 0) break;
        r1 = i;
    }
 
    array<int, 3> cnt, pos;
 
    for (int i = 0; i < 3; i++) cnt[i] = pos[i] = 0;
 
    for (int i = n; i >= 1; i--){
        if (v[i] < 3) cnt[v[i]]++;
        if (cnt[0] && cnt[1] && !cnt[2]){
            l2 = i;
            if (r2 == -1) r2 = i;
        }
    }
 
    auto ok = [&](int x, int l, int r){ return l <= x && x <= r; };
 
    for (int i = 1; i <= n; i++){
        if (v[i] < 3) pos[v[i]] = i;
        if (pos[1] < pos[0]){
            if (ok(i + 1, l2, r2) && ok(r1, pos[1], pos[0]))
                return void(cout << "YES\n");
        }
    }
    cout << "NO\n";
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