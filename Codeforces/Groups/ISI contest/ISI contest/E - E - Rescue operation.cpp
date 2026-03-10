/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
 
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
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'
#define ld long double
#define pi 3.14159265359
const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;
 
void Solve() {
    ld x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
 
    //calculating alpha
    ld CE = x2 - x1;
    ld KE = r2 - r1;
    ld alpha = asin(KE / CE);
 
    //calculating xA ;
    ld IE = r2;
    ld AE = IE / sin(alpha);
    ld xA = x2 - AE;
 
    // calculating xH
    ld AC = x1 - xA;
    ld HC = r1;
    ld AH = sqrtl(AC * AC - HC * HC);
    ld AN = cos(alpha) * AH;
    ld xH = AN + xA;
 
    // calculating xI
    ld AI = sqrtl(AE * AE - IE * IE);
    ld AM = cos(alpha) * AI;
    ld xI = AM + xA;
 
    //verifing the points ;
 
    int ans = 0, m;
    cin >> m;
 
    for (int i = 0; i < m; i++) {
        ld x, y;
        cin >> x >> y; // let's name it P(x,y)
 
        // let Z be the projeté orthogonale of P sur X-axis
        // calculating the angle between [Ax) & [AP)
        ld AZ = x - xA;
        ld beta = atan(y / AZ);
 
        // distange betwen P and center of Circle1
        ld dx = abs(x1 - x);
        ld dy = abs(y1 - y);
        ld BC = sqrtl(dx * dx + dy * dy);
 
        // distange betwen P and center of Circle2
        dx = abs(x2 - x);
        dy = abs(y2 - y);
        ld BE = sqrtl(dx * dx + dy * dy);
 
        ans += (
            abs(beta) <= abs(alpha) && // 1)
            xH <= x && x <= xI && // 2)
            BC >= r1 && BE >= r2 // 3)
        );
    }
    cout << ans << endl;
}
 
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}
