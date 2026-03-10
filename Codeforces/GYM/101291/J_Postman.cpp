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
 
 
void solve(){
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> a[2];
    for (int i = 0; i < N; i++){
        int x, m;
        cin >> x >> m;
        if (x > 0) a[0].push_back({x, m});
        else a[1].push_back({-x, m});
    }
    ll ans = 0;
    for (int i = 0; i < 2; i++){
        sort(a[i].rbegin(), a[i].rend());
        for (int j = 0; j < (int)a[i].size(); j++){
            if (!a[i][j].S) continue;
            int need = (a[i][j].S + K - 1) / K;
            if (a[i][j].S % K == 0){
                ans += 2LL * a[i][j].F * 1LL * need;
                continue;
            }
            ans += 2LL * a[i][j].F * 1LL * need;
            int r = K - a[i][j].S % K, ind = j + 1;
            while (ind < (int)a[i].size()){
                if (r == 0) break;
                int mn = min(r, a[i][ind].S);
                r -= mn;
                a[i][ind].S -= mn;
                ind++;
            }
        }
    }
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