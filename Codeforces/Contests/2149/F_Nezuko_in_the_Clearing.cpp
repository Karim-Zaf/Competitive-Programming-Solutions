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

int get(int h, int d){
    int l = 1, r = d + 4, ans = 1;
    // md : how many tanguiza had he made ;

    auto arith = [&](int x){ return x * (x + 1) / 2; };
    while (l <= r){
        int md = l + (r - l) / 2;

        int cnt = d / (md);
        int reste = d % (md);
        // the reste we will distrubte it into some blocks
        // a prefix will now have (a+1) size and the others (a) size

        int need = arith(cnt) * md;
        need += reste * (cnt + 1);
        if (need <= h + md - 1 - 1){
            ans = md;
            r = md - 1;
        }
        else l = md + 1;
    }
    return ans + d - 1;
}

void Solve(){
    int h, d;
    cin >> h >> d;

    cout << get(h, d) << endl;
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
