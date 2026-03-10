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
const int N_Max = 1e6 + 5;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
int dp[N_Max][4];
string a[N_Max];
int N;
 
bool is_vowel(char c){
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}
 
int work(int i, int lst){
    if (i > N) return 0;
    int &ret = dp[i][lst];
    if (ret != -1) return ret;
    ret = 2e9;
    int sz = min((int)a[i].size(), 3);
    int new_lst = lst;
    for (int j = 0; j < sz; j++){
        if (new_lst > 3) break;
        if (is_vowel(a[i][j])) new_lst = 0;
        if (new_lst + 1 <= 3) ret = min(ret, j + 1 + work(i + 1, new_lst + 1));
        new_lst++;
    }
    return ret;
}
 
void solve(){
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++) cin >> a[i];
    int ans = work(1, 1);
    if (ans < 2e9) cout << ans << endl;
    else cout << '*' << endl;
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