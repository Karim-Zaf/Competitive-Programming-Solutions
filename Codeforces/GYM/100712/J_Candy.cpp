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
const ll mod = 1e9 + 7;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<int> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<int, int> p){cout << p.F << " " << p.S << endl;}
void dbgpi(vector<pair<int, int>> v){for (auto x : v) dbgg(x);}


void solve(){
    int N, M;
    cin >> N >> M;
    vector<int> v(N), a(M);
    vector<pair<int, int>> ages, candy;
    map<int, int> mp1, mp2;
    for (auto &x : v){
        cin >> x;
        mp1[x]++;
    }
    for (auto &x : a){
        cin >> x;
        mp2[x]++;
    }
    for (auto x : mp1)
        ages.push_back({x.F, x.S});
    for (auto x : mp2)
        candy.push_back({x.F, x.S});
    sort(ages.rbegin(), ages.rend());
    sort(candy.rbegin(), candy.rend());
    int index = 0;
    for (int i = 0; i < ages.size(); i++){
        bool good = false;
        while (index < candy.size()){
            if (candy[index].S >= ages[i].S){
                good = true;
                break;
            }
            index++;
        }
        if (good == false){
            no
            return;
        }
        index++;
    }
    yes
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
a + b = a ^ b + 2 * (a & b)
THINK ABOUT : dp, bs, st, pf, bitmask, dfs, mo, two pointers
Think outside the box
int overflow
check initialization of the answer
check corner cases(small values)
stay focused ans organized
*/
