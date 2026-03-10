#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define F first
#define S second
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const int mod = 998244353;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
long double dist(long double x1, long double y1, long double x2, long double y2) {
    return sqrtl(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2)); 
}
 
void solve() {
    long double x, y;
    cin >> x >> y;
 
    long double ac = y, ab = x, bd = x, be = y;
    long double ae = be - ab;
    long double ag = ae * bd / be;
 
    long double xf = y / (x / y + y / x);
    long double yf = xf * (-x / y);
    long double fc = dist(xf, yf, y, -x);
    long double angle = atan(x / y);
    long double xg = ag;
    long double yg = -x;
    long double fg = dist(xf, yf, xg, yg);
    long double fh = fg * cos(angle);
    long double a1 = angle/2*fh*fh;
    
    long double gh = sqrtl(fg * fg - fh * fh);
    long double a2 = fh * gh / 2;
    cout << a2 - a1 << endl;
}  
 
int main() {
    FAST
    // freopen("nocross.in","r",stdin);
    // freopen("nocross.out","w",stdout);
    cout << fixed << setprecision(6) ;
 
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
   
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}