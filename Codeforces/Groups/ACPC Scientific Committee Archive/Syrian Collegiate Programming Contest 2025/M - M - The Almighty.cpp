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
    int N, Q;
    cin >> N >> Q;
    vector<vector<ll>> pref;
    vector<ll> a(N), currentList;
    for (int i = 0; i < N; i++) cin >> a[i];
    
    currentList = a;
    while ((int)currentList.size() > 1){
        pref.push_back(currentList);
        for (int i = 1; i < (int)pref.back().size(); i++)
            pref.back()[i] += pref.back()[i - 1];
 
        vector<ll> nxtList;
        for (int i = 0; i < (int)currentList.size(); i += 2)
            nxtList.pb(currentList[i]);
        currentList = nxtList;
    }
    pref.push_back(currentList);
 
    for (int q = 1; q <= Q; q++){
        ll M;
        cin >> M;
        ll ans = 0;
        for (int l = 0; l < (int)pref.size(); l++){
            if (M >= pref[l].back()){
                M -= pref[l].back();
                ans += (int)pref[l].size();
                continue;
            }
 
            int ind = upper_bound(pref[l].begin(), pref[l].end(), M) - pref[l].begin();
            ans += ind;
            break;
        }
        cout << ans << endl;
    }
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