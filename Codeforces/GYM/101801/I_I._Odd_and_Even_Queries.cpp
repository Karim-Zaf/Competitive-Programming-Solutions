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
const int N_Max = 1e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

ll po[N_Max];

void preprocess(){
    po[0] = 1;
    for (int i = 1; i < N_Max; i++)
        po[i] = po[i - 1] * 2 % mod;
}

void solve(){
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N + 1);
    array<vector<int>, 2> pos;
    for (int i = 1; i <= N; i++){
        cin >> a[i];
        pos[a[i] % 2].pb(i);
    }
    for (int i = 1; i <= Q; i++){
        int l, r, t;
        cin >> l >> r >> t;
        if (t == 0){
            int low = lower_bound(pos[0].begin(), pos[0].end(), l) - pos[0].begin();
            int hig = upper_bound(pos[0].begin(), pos[0].end(), r) - pos[0].begin();
            ll even = po[hig - low] - 1;
            low = lower_bound(pos[1].begin(), pos[1].end(), l) - pos[1].begin();
            hig = upper_bound(pos[1].begin(), pos[1].end(), r) - pos[1].begin();
            ll odd = po[hig - low] - 1;
            ll ans = even * (odd + 1) % mod;
            cout << ans << endl;
        }
        else{
            int low = lower_bound(pos[1].begin(), pos[1].end(), l) - pos[1].begin();
            int hig = upper_bound(pos[1].begin(), pos[1].end(), r) - pos[1].begin();
            ll ans = po[hig - low] - 1;
            cout << ans << endl;
        }
    }
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    preprocess();
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}