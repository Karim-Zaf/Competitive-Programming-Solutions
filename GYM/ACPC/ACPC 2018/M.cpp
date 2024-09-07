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
    int N, M;
    cin >> N >> M;
    ordered_set st;
    vector<int> ans;
    set<pair<int, int>> s;
    vector<array<int, 3>> a(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    int ind = 1;
    for (int i = 1; i <= M; i++){
        int y, d;
        cin >> y >> d;
        while (!s.empty() && (*s.begin()).F < y){
            auto [x, idx] = *s.begin();
            s.erase(s.begin());
            st.erase({a[idx][1] - a[idx][0], idx});
        }
        while (ind <= N && a[ind][0] <= y){
            if (a[ind][0] + a[ind][2] >= y){
                s.insert({a[ind][0] + a[ind][2], ind});
                st.insert({a[ind][1] - a[ind][0], ind});
            }
            ind++;
        }
        int cnt = (int)st.size() - st.order_of_key({d - y, (int)-2e9});
        ans.pb(cnt);
    }
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int main(){
    FAST
    freopen("business.in","r",stdin);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}
