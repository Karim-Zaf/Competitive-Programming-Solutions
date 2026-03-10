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


void solve(){
    string s;
    cin >> s;
    int N = s.size();
    vector<pair<int, int>> a;
    int bal = 0;
    for (int i = 0; i < N; i++){
        bal += (s[i] == '(' ? 1 : -1);
        int j = i + 1;
        while (j < N && bal != 0){
            bal += (s[j] == '(' ? 1 : -1);
            j++;
        }
        assert(!bal);
        a.push_back({i, j - i});
        i = j - 1;
    }
    int ind = -1;
    for (int i = 1; i < (int)a.size(); i++){
        if (a[i].S != a[0].S){
            ind = a[i].F;
            break;
        }
        assert(a[i].S == a[0].S);
        int i1 = a[0].F, i2 = a[i].F;
        for (int c = 0; c < a[i].S; c++){
            if (s[i1] != s[i2]){
                ind = a[i].F;
                break;
            }
            i1++, i2++;
        }
        if (ind != -1) break;
    }
    if (ind == -1){
        cout << "no" << endl;
        return;
    }
    string ans = "";
    for (int i = ind; i < N; i++) ans += s[i];
    for (int i = 0; i < ind; i++) ans += s[i];
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