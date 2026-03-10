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
#define int ll
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

vector<pair<int, int>> a(N_Max);
int N;

bool work(int x){
    if (2 * x > N) return false;
    vector<pair<int, int>> vec;
    set<pair<int, int>> curr_mx, mn_p, used, not_used;
    ll S = 0;
    for (int i = 1; i <= x; i++){
        S += a[i].F;
        curr_mx.insert({a[i].F + a[i].S, i});
    }
    for (int i = x + 1; i <= N; i++) vec.push_back({a[i].S, i});
    sort(vec.begin(), vec.end());
    for (int i = 0; i < x; i++){
        S -= vec[i].F;
        int ind = vec[i].S;
        used.insert({vec[i].F, vec[i].S});
        mn_p.insert({a[ind].F + a[ind].S, ind});
    }
    for (int i = x; i < (int)vec.size(); i++) not_used.insert({a[vec[i].S].F, vec[i].S});
    if (S >= 0) return true;
    for (int rep = 1; rep <= x; rep++){
        auto [mn, ind1] = *curr_mx.begin();
        curr_mx.erase(curr_mx.begin());
        // case 1
        auto [mx, ind2] = *mn_p.rbegin();
        ll best1 = S - mn + mx;

        // case 2
        auto [mx_p, ind3] = *used.rbegin();
        not_used.insert({a[ind3].F, ind3});
        auto [mx_m, ind4] = *not_used.rbegin();
        ll best2 = S - mn + mx_p + mx_m;
        not_used.erase({a[ind3].F, ind3});

        if (best1 >= best2){
            S = best1;
            used.insert({a[ind1].S, ind1});
            mn_p.insert({mn, ind1});

            mn_p.erase({mx, ind2});
            used.erase({a[ind2].S, ind2});
            curr_mx.insert({mx, ind2});
        }
        else{
            S = best2;
            used.insert({a[ind1].S, ind1});
            mn_p.insert({mn, ind1});

            used.erase({mx_p, ind3});
            mn_p.erase({a[ind3].F + a[ind3].S, ind3});
            not_used.insert({a[ind3].F, ind3});
            
            auto [maxi, ind5] = *not_used.rbegin();
            not_used.erase({maxi, ind5});
            curr_mx.insert({a[ind5].F + a[ind5].S, ind5});
        }
        if (S >= 0) return true;
    }
    return false;
}

void solve(){
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i].F;
    for (int i = 1; i <= N; i++) cin >> a[i].S;
    sort(a.begin() + 1, a.begin() + N + 1);
    reverse(a.begin() + 1, a.begin() + N + 1);
    int l = 1, r = N, ans = 0;
    while (l <= r){
        int mid = l + (r - l) / 2;
        if (work(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
}

int32_t main(){
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