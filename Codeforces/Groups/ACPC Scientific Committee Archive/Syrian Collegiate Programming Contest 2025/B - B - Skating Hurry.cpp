#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
const int mod = 1e9 + 7;
const long double EPS = 1e-10;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<int> a(n);
    for(auto &x : a) cin >> x;
 
    int ans = (int)2e9;
    for(int i = 0; i < n; i++){
        int cur = a[i] - 2 * i;
        if(cur >= k) 
            ans = min(ans, cur);
    }
 
    cout << (ans == (int)2e9 ? -1 : ans) << endl;
}
 
 
int main()
{
    FAST
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}