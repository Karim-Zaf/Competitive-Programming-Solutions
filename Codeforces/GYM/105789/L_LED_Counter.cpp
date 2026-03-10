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
 
vector<int> vec = {119, 96, 62, 124, 105, 93, 95, 100, 127, 125};
map<int, int> mp;
 
void solve(){
    int N;
    cin >> N;
    for (int i = 0; i < 10; i++) mp[vec[i]] = i;
    string ans = "";
    for (int i = 1; i <= N; i++){
        string s;
        cin >> s;
        int cnt = 0;
        for (char c : s)
            if (c == '+' || c == '-') cnt++;
        set<int> st;
        for (int mask = 0; mask < (1 << cnt); mask++){
            int bit = 0, val = 0;
            for (int j = 0; j < 7; j++){
                if (s[j] == 'G' || s[j] == 'g'){
                    val += (1 << j) * (s[j] == 'G');
                    continue;
                }
                if (mask & (1 << bit)) val += (1 << j) * (s[j] == '-');
                else val += (1 << j) * (s[j] == '+');
                bit++;
            }
            if (mp.count(val)) st.insert(mp[val]);
        }
        assert(!st.empty());
        if ((int)st.size() > 1) ans += "*";
        else  ans += (char)(*st.begin() + '0');
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