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
const int N_Max = 2050;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

vector<array<int, 4>> a;
int dp[N_Max][N_Max];
int N, mx = 0;

int work(int i, int mask){
    if (i >= (int)a.size()) return (mask == (1 << N) - 1 ? 0 : -1e9);
    int &ret = dp[i][mask];
    if (ret != -1) return ret;
    ret = work(i + 1, mask);
    array<int, 4> p = {a[i][1], (int)-2e9, (int)-2e9, (int)-2e9};
    int j = lower_bound(a.begin(), a.end(), p) - a.begin();
    ret = max(ret, a[i][2] + work(j, mask | (1 << a[i][3])));
    return ret;
}

void solve(){
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++){
        int M;
        cin >> M;
        for (int j = 1; j <= M; j++){
            int l, r, c;
            cin >> l >> r >> c;
            a.push_back({l, r, c, i - 1});
        }
    }
    sort(a.begin(), a.end());
    int ans = work(0, 0);
    cout << (ans > 0 ? ans : -1) << endl;
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