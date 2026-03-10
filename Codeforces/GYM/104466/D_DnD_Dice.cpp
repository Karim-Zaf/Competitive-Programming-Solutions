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

long double dp[505][105];

void solve(){
    cout << setprecision(30);
    vector <int> v , f{4,6, 8,12,20};
    int l = 0, r = 0;
    for (int i= 0; i<= 4 ; i++){
        int x ; cin >> x;
        l += x;
        r += x * f[i];
        for (int j= 0 ; j<x ;j ++)
            v.pb(f[i]);
    }
    int n = v.size() ;
    for(int j = 1; j<= v[0]; j++) dp[j][0]= 1;
    for (int i= 1 ; i<n ;i++){
        long double P = (long double)1.0 / (long double)v[i];
        for (int sum = 1 ; sum<= 500; sum++){
            for (int k = 1 ; k<= v[i] ;k++) {
                if (sum - k >= 0)
                    dp[sum][i] += dp[sum - k][i - 1] * P;
            }
        }
    }
    vector <pair <long double,int>> vp ;
    for (int sum = l; sum<= r; sum++)
        vp.push_back({dp[sum][n-1],sum});
    sort(vp.rbegin(), vp.rend());
    for (auto [val , x ] : vp)
        cout << x << " " ;
    cout << endl;
 
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