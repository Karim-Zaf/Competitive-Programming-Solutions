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


void solve() {
    int n;
    cin >> n;

    vector<string> c(n), s(n), v(n), p(n);
    vector<int> a(n), b(n), g(n);

    for(int i = 0; i < n; i++)
        cin >> c[i] >> s[i] >> v[i] >> p[i] >> a[i] >> b[i] >> g[i];

    int ans = -1;
    for(int i = 1; i < n; i++)
        if(c[i] == c[0] && s[i] != s[0] && v[i] == v[0])
            ans = max(ans, (p[i] != p[0] ? 1000 : 0) + a[i] * a[0] + b[i] * b[0] + g[i] * g[0]);

    cout << ans << endl;
}  

int main() {
    FAST
    // freopen("nocross.in","r",stdin);
    // freopen("nocross.out","w",stdout);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
   
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}