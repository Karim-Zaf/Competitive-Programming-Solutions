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
    int n;
    cin >> n;
 
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];    
    string s;
    cin >> s;
    s = "#" + s;
 
    vector<ll> rg(n + 2), lf(n + 2);
    for(int i = 1; i <= n; i++){
        if(s[i] == 'L') {
            lf[1] += a[i];
            lf[i + 1] -= a[i];
        }else {
            rg[i] += a[i];
        }
    }
 
    for(int i = 1; i <= n; i++){
        lf[i] += lf[i - 1];
        rg[i] += rg[i - 1];
    }
 
    ll ans = (ll)(1e15), idx = -1;
    for(int i = 1; i <= n; i++){
        ll cur = abs(rg[i] - lf[i]);
        if(ans > cur) 
            ans = cur, idx = i;
    }
 
    cout << idx << endl;
}
 
 
int main()
{
    FAST
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}