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
    int N, x;
    cin >> N >> x;
    vector<int> a;
    for (int i = 0; i < N; i++){
        int c;
        cin >> c;
        bool good = true;
        for (int mask = 0; mask < 30; mask++){
            int v1 = x & (1 << mask);
            int v2 = c & (1 << mask);
            if (v1 && !v2) good = false;
        }
        if (good) a.pb(c);
    }
    if (!(int)a.size()){
        cout << -1 << endl;
        return;
    }
    for (int mask = 0; mask < 30; mask++){
        if (x & (1 << mask)) continue;
        bool good = false;
        for (int val : a){
            int v = val & (1 << mask);
            if (!v) good = true;
        }
        if (!good){
            cout << -1 << endl;
            return;
        }
    }
    cout << (int)a.size() << endl;
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}