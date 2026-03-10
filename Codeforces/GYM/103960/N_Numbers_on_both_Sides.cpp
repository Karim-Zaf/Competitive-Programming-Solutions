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
const int N_Max = 2e5 + 5;
const int Nax = 1e9 + 7;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}


void solve(){
    int N, K, L;
    cin >> N;
    vector<int> A(N), B(N);
    multiset<int> have, need;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    cin >> K >> L;
    ll prev = 0;
    for (int i = 0; i < K; i++){
        prev += A[i];
        need.insert(B[i]);
    }
    for (int i = 0; i < L; i++){
        auto it = need.end();
        it--;
        prev += *it;
        have.insert(*it);
        need.erase(it);
    }
    // dbg(have);
    ll ans = prev;
    int j = K - 1;
    for (int i = N - 1; i >= N - K; i--){
        ll curr = prev;
        curr -= A[j];
        curr += A[i];
        need.insert(B[i]);
        if (have.find(B[j]) != have.end()){
            curr -= B[j];
            have.erase(have.find(B[j]));
            auto it = need.end();
            it--;
            curr += *it;
            have.insert(*it);
            need.erase(it);
        }
        else{
            need.erase(need.find(B[j]));
            auto it = need.end();
            it--;
            if (*it > *have.begin()){
                curr -= *have.begin();
                int val = *have.begin();
                have.erase(have.begin());
                curr += *it;
                have.insert(*it);
                need.erase(it);
                need.insert(val);
            }
        }
        prev = curr;
        ans = max(ans, curr);
        j--;
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