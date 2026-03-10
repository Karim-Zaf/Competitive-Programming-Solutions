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
    /*
     *
       if we repeat x 2 times
        double_x = x + 10^(nbofdigitesofx)*x
                  = x * ( 1 + 10^(nbdigitsofx))
                            ^
                            |
                            y
     */

    auto prime = [&](int x){
        for (int d = 2; d * d <= x; d++){
            if (x % d == 0)
                return false;
        }
        return true;
    };

    int n, k;
    cin >> n >> k;
    if (n == 1 && k == 1) return void(cout << "NO\n");
    if (k == 1){ return void(cout << (prime(n) ? "YES" : "NO") << endl); }
    if (n == 1){
        int x = 0;

        while (k--){
            x *= 10;
            x += 1;
        }
        cout << (prime(x) ? "YES" : "NO") << endl;
        return;
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
