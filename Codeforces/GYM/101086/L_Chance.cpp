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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const int N_Max = 1e5 + 5;
const ll mod = 1e8;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<int> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<int, int> p){cout << p.F << " " << p.S << endl;}
void dbgpi(vector<pair<int, int>> v){for (auto x : v) dbgg(x);}

int vis[N_Max], prefix[N_Max];
set<int> primes;

void sieve(){
    for (int i = 2; i <= 30; i++){
        if (vis[i] == 0){
            primes.insert(i);
            for (int j = i; j <= 30; j += i)
                vis[j] = 1;
        }
    }
}

void pre(){
    for (int i = 0; i < N_Max; i++){
        int cnt =  __builtin_popcount(i);
        if (primes.find(cnt) != primes.end())
            prefix[i] = 1 + (i == 0 ? 0 : prefix[i - 1]);
        else
            prefix[i] = (i == 0 ? 0 : prefix[i - 1]);
    }
}

void solve(){
    int l, r;
    cin >> l >> r;
    cout << prefix[r] - (l == 0 ? 0 : prefix[l - 1]) << endl;
}

int main(){
    FAST
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //#endif
    sieve();
    pre();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
a + b = a ^ b + 2 * (a & b)
THINK ABOUT : dp, bs, st, pf, bitmask, dfs, mo, two pointers
Think outside the box
int overflow
check initialization of the answer
check corner cases(small values)
stay focused ans organized
*/
