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

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> mpa(N), mpb(N);

void Solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    sort(all(a));
    sort(all(b));

    if (a == b) return void(cout << "1000000000\n");
    if (accumulate(all(b), 0ll) == 0ll) return void(cout << "1\n");

    auto verif = [&](int x){
        bool ret = true;
        for (auto curr : a) mpa[curr % x]++;
        for (auto curr : b) mpb[curr % x]++;

        for (auto curr : a) ret &= (mpa[curr % x] == mpb[curr % x]);

        for (auto curr : a)mpa[curr % x] = 0;
        for (auto curr : b)mpb[curr % x] = 0;
        return ret;
    };

    set<int> s;
    int mxb = *max_element(all(b));
    int mxa = *max_element(all(a));

    int diff = accumulate(all(a), 0ll) - accumulate(all(b), 0ll);

    vector<int> divi{diff};
    for (int d = 2; d * d <= diff; d++){
        if (diff % d) continue;
        divi.pb(d);
        divi.pb(diff / d);
    }
    for (auto x : divi){ if (x > mxb && x <= mxa && verif(x)) return void(cout << x << endl); }

    cout << -1 << endl;
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
