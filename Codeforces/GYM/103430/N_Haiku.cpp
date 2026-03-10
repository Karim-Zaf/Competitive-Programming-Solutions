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
    vector<int> word(3), vowel(3), cnt(3);
    vector<vector<int>> s(3);
    vector<string> a(3);
    for (int i = 0; i < 3; i++) cin >> word[i];
    cin.ignore();
    for (int i = 0; i < 3; i++){
        string s;
        getline(cin, a[i]);
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < (int)a[i].size(); j++){
            char c = tolower(a[i][j]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowel[i]++;
        }
        for (int j = 0; j < (int)a[i].size(); j++){
            char c = tolower(a[i][j]);
            if (c == 'y') cnt[i]++;
        }
    }
    if (vowel[0] > 5 || vowel[1] > 7 || vowel[2] > 5){
        no
        return;
    }
    for (int i = 0; i < 3; i++) vowel[i] += cnt[i];
    if (vowel[0] >= 5 && vowel[1] >= 7 && vowel[2] >= 5)
        yes
    else no
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}