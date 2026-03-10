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

int dp[N_Max];
int val[ALPHA];
int vis[ALPHA];

int add(ll a, ll b){return (a % mod + b % mod) % mod;}

int work(int sum){
    if (sum <= 0) return !sum;
    int &ret = dp[sum];
    if (ret != -1) return ret;
    ret = 0;
    for (int c = 0; c < ALPHA; c++)
        ret = add(ret, work(sum - val[c]));
    return ret;
}

void solve(){
    int N;
    string s;
    cin >> N >> s;
    memset(dp, -1, sizeof(dp));
    for (char c = 'a'; c <= 'z'; c++) val[c - 'a'] = (int)c;
    for (char c : s) vis[c - 'a']++;
    int ans = 0;
    for (int i = 0; i < ALPHA; i++)
        if (!vis[i]) ans = add(ans, work(N - val[i]));
    cout << ans << endl;
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