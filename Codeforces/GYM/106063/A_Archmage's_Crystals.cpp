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
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    int sum = 0;
    for(int x : a) sum += x;

    vector<int> dv;
    for(ll d = 1; d * d <= sum; d++){
        if(sum % d == 0){
            dv.push_back(d);
            if(sum / d != d)
            dv.push_back(sum/d);
        }   
    }
    
    int mx = 1;
    for(int d : dv)
        if(d <= n)
            mx = max(mx, d);
    
    cout << n - mx << endl;
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
