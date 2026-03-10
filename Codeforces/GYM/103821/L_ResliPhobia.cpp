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
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const int N_Max = 1e5 + 5;
const ll mod = 1e9 + 7;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<int> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<int, int> p){cout << p.F << " " << p.S << endl;}
void dbgpi(vector<pair<int, int>> v){for (auto x : v) dbgg(x);}


void solve(){
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (auto &x : v)
        cin >> x;
    int ans = 0;
    for (int i = 0; i < N; i++){
        int p = v[i] % 2, j = i;
        priority_queue<int> q;
        while (j < N && v[j] % 2 == p){
            q.push(v[j]);
            j++;
        }
        for (int l = 0; l < K; l++){
            if (q.size() == 0)
                break;
            ans += q.top();
            q.pop();
        }
        i = j - 1;
    }
    cout << ans << endl;
}
 
int main(){
    FAST
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
 
/*
Think outside the box
int overflow
check initialization of the answer
check corner cases(small values)
stay focused ans organized
*/