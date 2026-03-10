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
    int n ;
    string s;
    cin >> n >> s ;
 
 
    int cnt = 0 ;
    char lst = '#';
    vector<pair<char,int>> vp;
 
    for (auto x: s){
        if ( x!=lst && cnt > 0){
            vp.pb({lst, cnt});
            cnt = 0 ;
        }
 
        lst = x ;
        cnt++;
    }
    vp.pb( {lst, cnt });
 
    if ( vp.size() == 1) return void ( cout << n << endl);
    if ( vp.size() == 2) return void ( cout << max (vp[0].S,vp[1].S) << endl);
 
    int ans = 0 ;
    for (auto [c , cnt]: vp){
        ans = max (ans ,cnt);
    }
    for (int i= 1 ;i<vp.size() ;i++){
        if ( vp[i].F == vp[0].F) ans = max (ans ,vp[0].S + vp[i].S);
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