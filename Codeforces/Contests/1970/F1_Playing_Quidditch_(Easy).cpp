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
const int N_Max = 105;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

map<string, vector<pair<int, int>>> pos;
map<string, pair<int, int>> mp;
string a[N_Max][N_Max];
string player;
int N, M, T;
int r = 0, b = 0;

bool good1(string s){
    string goal = "";
    int addr = 0, addb = 0;
    if (s[0] == 'B') goal = "RG", addb = 1;
    else goal = "BG", addr = 1;
    for (auto [i, j] : pos[goal]){
        if (mp[s].F == i && mp[s].S == j){
            r += addr;
            b += addb;
            return true;
        }
    }
    return false;
}

string get1(string s){
    string ret;
    if (s[0] == 'B') ret = "BLUE";
    else ret = "RED";
    ret += " GOAL";
    return ret;
}

bool good2(string s){
    string goal = "";
    int addr = 0, addb = 0;
    if (s[0] == 'B') goal = "BG", addr = 1;
    else goal = "RG", addb = 1;
    for (auto [i, j] : pos[goal]){
        if (mp[s].F == i && mp[s].S == j){
            r += addr;
            b += addb;
            return true;
        }
    }
    return false;
}

string get2(string s){
    string ret;
    if (s[0] == 'B') ret = "RED";
    else ret = "BLUE";
    ret += " GOAL";
    return ret;
}

void solve(){
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            string s;
            cin >> s;
            if (s[1] == 'G') pos[s].push_back({i, j});
            else mp[s] = {i, j};
        }
    }
    cin >> T;
    for (int i = 0; i < T; i++){
        string e, m, s;
        cin >> e >> m;
        if (m == "C") cin >> s;
        if (m == "C") player = e;
        else if (m == "T" && good1(e)) cout << i << " " << get1(e) << endl;
        else if (m == "T" && good2(e)) cout << i << " " << get2(e) << endl;
        else if (m == "U") mp[e].F--;
        else if (m == "D") mp[e].F++;
        else if (m == "L") mp[e].S--;
        else if (m == "R") mp[e].S++;
    }
    cout << "FINAL SCORE: " << r << " " << b << endl;
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