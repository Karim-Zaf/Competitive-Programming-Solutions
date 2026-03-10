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

const int BG = 1e9;

int ask(char c, int x){
    cout << "? " << c << " " << x << endl;
    cout.flush();
    int xx;
    cin >> xx;
    return xx;
}

void Solve(){
    int n;
    cin >> n;

    vector<pair<int,int>> vp(n);
    for (auto& [x,y] : vp) cin >> x >> y;

    int mna = INF, mnb = INF;

    for (auto [x,y] : vp) mna = min(mna, abs(BG - x) + abs(BG - y));
    for (auto [x,y] : vp) mnb = min(mnb, abs(BG - x) + abs(-BG - y));

    ask('U', BG);
    ask('U', BG);
    ask('R', BG);
    int a = ask('R', BG);

    ask('D', BG);
    ask('D', BG);
    ask('D', BG);
    int b = ask('D', BG);

    a -= mna;
    a -= 2 * BG;
    b -= 2 * BG;
    b -= mnb;

    cout << "! " << (a + b) / 2 << " " << a - (a + b) / 2 << endl;
    cout.flush();
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
