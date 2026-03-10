/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define kar(...)
#endif
#define int long long
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

#define ld long double

ld binpow(ld a, int k, ld res = 1){
    while (k){
        if (k % 2)res = (res * a);
        a = (a * a);
        k /= 2;
    }
    return res;
}

void Solve(){
    int h_st, h_tr;
    ld B;
    cin >> h_st >> h_tr >> B;
    int ans = -1;
    ld terme = (ld)(B - 1) / B;

    int l = 0, r = 6e6;
    while (l <= r){
        int md = l + (r - l) / 2;
        ld cnt = h_st * binpow(terme, md);
        if (cnt <= h_tr){
            ans = md;
            r = md - 1;
        }
        else{ l = md + 1; }
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
