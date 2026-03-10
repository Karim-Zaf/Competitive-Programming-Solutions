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

int n, q;
int work1(int x, int y,int st_nb = 1, int sx = 1, int ex = (1ll << n), int sy = 1, int ey = (1 << n)){
    // cout << x << " " << y << " " << st_nb << " " << sx << " " << ex << " " << sy << " " << ey << endl;
    if (!(sx <= x && x <= ex && sy <= y && y <= ey))return -1;
    if (sx == ex && sy == ey) return st_nb;

    int mdx = (ex + sx) / 2;
    int mdy = (ey + sy) / 2;

    int ans = -1;
    int dx = (ey - sy + 1);
    int nb = dx * dx / 4;
    ans = max(ans, work1(x, y, st_nb + 0 * nb, sx, mdx, sy, mdy));
    ans = max(ans, work1(x, y, st_nb + 1 * nb, mdx + 1, ex, mdy + 1, ey));
    ans = max(ans, work1(x, y, st_nb + 2 * nb, mdx + 1, ex, sy, mdy));
    ans = max(ans, work1(x, y, st_nb + 3 * nb, sx, mdx, mdy + 1, ey));

    return ans;
}

pair<int,int> work2(int x,int st_nb = 1, int sx = 1, int ex = (1ll << n), int sy = 1, int ey = (1 << n)){
    if (x == st_nb && sx == ex && sy == ey) return make_pair(sx, sy);

    int mdx = (ex + sx) / 2;
    int mdy = (ey + sy) / 2;

    pair<int,int> ans = {-1, -1};
    int dx = (ey - sy + 1);
    int nb = dx * dx / 4;

    if (!(st_nb <= x && x <= st_nb + 4 * nb - 1)) return {-1, -1};

    pair<int,int> p;
    p = work2(x, st_nb + 0 * nb, sx, mdx, sy, mdy);
    if (p.F != -1) return p;
    p = work2(x, st_nb + 1 * nb, mdx + 1, ex, mdy + 1, ey);
    if (p.F != -1) return p;
    p = work2(x, st_nb + 2 * nb, mdx + 1, ex, sy, mdy);
    if (p.F != -1) return p;
    p = work2(x, st_nb + 3 * nb, sx, mdx, mdy + 1, ey);
    if (p.F != -1) return p;

    return ans;
}

void Solve(){
    cin >> n >> q;

    while (q--){
        int x, y;
        string s;
        cin >> s;

        if (s == "->"){
            cin >> x >> y;
            cout << work1(x, y) << endl;
        }
        else{
            cin >> x;
            pair<int,int> p = work2(x);
            cout << p.F << " " << p.S << endl;
        }
    }
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
