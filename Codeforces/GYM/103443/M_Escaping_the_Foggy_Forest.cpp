#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
int a[105][105];
int N, M, S, F, R;
 
void solve(){
    cin >> N >> M;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) cin >> a[i][j];
    cin >> S >> F >> R;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            if (a[i][j] != S) continue;
            if (a[i - 1][j] == F && a[i][j + 1] == R) ans.push_back({i - 1, j - 1});
            else if (a[i][j + 1] == F && a[i + 1][j] == R) ans.push_back({i - 1, j - 1});
            else if (a[i + 1][j] == F && a[i][j - 1] == R) ans.push_back({i - 1, j - 1});
            else if (a[i][j - 1] == F && a[i - 1][j] == R) ans.push_back({i - 1, j - 1});
        }
    }
    for (auto [x, y] : ans) cout << x << " " << y << endl;
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}