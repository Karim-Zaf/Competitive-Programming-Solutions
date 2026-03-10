#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
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
const ll mod = 998244353;
const int N_Max = 2e5 + 5;
const int Nax = 15;
const int LOG = 20;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
 

void solve() {  
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    if(a == c && b == d) {
        if(n & 1){
            cout << a + 1 << " " << b << endl;
            cout << a + 1 << " " << b + 1 << endl;
            cout << a << " " << b << endl;
            n -= 3;
        }
    }else if(a == c) {
        if(n & 1){
            cout << a + 1 << " " << d << endl;
            cout << a + 1 << " " << d + 1 << endl;
            cout << a << " " << d << endl;
            n -= 3;
        }else {
            cout << c + 1 << " " << d << endl;
            cout << c << " " << d << endl;
            n -= 2;
        }
    } else if(b == d) {
        if(n & 1){
            cout << c << " " << b + 1 << endl;
            cout << c + 1 << " " << b << endl;
            cout << c << " " << b << endl;
            n -= 3;
        }else {
            cout << c << " " << d + 1 << endl;
            cout << c << " " << d << endl;
            n -= 2;
        }
    }else {
        if(n & 1){
            cout << c << " " << b + 1 << endl;
            cout << c + 1 << " " << d << endl;
            cout << c << " " << d << endl;
            n -= 3;
        }else {
            cout << c + 1 << " " << b + 1 << endl;
            cout << c << " " << d << endl;
            n -= 2;
        }
    }

    while(n > 0){
        cout << c + 1 << " " << d << endl;
        cout << c << " " << d << endl;
        n -= 2;
    }
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