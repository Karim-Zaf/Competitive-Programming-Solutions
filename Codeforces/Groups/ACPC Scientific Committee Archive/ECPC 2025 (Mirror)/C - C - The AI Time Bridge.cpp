#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define F first
#define S second
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const int mod = 998244353;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
 
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    int lst = -1, bad = n;
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '1'){
            if(lst != -1 && lst - i - 1 < k)
                bad = lst;
            lst = i;
        }
        ans += bad - i;
    }
 
    cout << ans << endl;
}  
 
int main() {
    FAST
    // freopen("nocross.in","r",stdin);
    // freopen("nocross.out","w",stdout);
 
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
   
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}