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
    int n, q;
    cin >> n >> q;
    vector<int> b(n + 1);
 
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<array<int, 3>> qr(q);
 
    for (auto& x : qr){
        for (int i = 0; i < 3; i++)
            cin >> x[i];
    }
    vector<int> a = b;
 
    reverse(all(qr));
 
    for (auto& [x,y,z] : qr){
        int temp =  a[z];
        a[z]= 0 ;
        a[x] = max(a[x], temp);
        a[y] = max(a[y], temp);
    }
 
    auto verif = [&](vector<int> a){
        reverse(all(qr));
        for (auto [x,y,z] : qr){ a[z] = min(a[x], a[y]); }
        return a == b;
    };
    if (!verif(a)) return void(cout << -1 << endl);
 
    for (int i = 1; i <= n; i++) cout << min((ll)1e9, a[i]) << " ";
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