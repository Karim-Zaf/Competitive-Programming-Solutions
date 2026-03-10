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
const int N_Max = 1e5 + 5;
const int Nax = 1e6 + 7;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
vector<string> grid;
int N, M;
 
bool work(string s){
    vector<int> idx;
    for (int i = 0; i < M; i++)
        if (s[i] == '1') idx.pb(i);
    for (int r = 0; r < N; r++){
        vector<int> shift;
        int p = idx[0];
        for (int c = 0; c < M; c++){
            if (r == 0 && grid[r][c] == '0'){
                if (c < p) shift.pb(M - p + c);
                else shift.pb(c - p);
                continue;
            }
            if (grid[r][c] == '0' && grid[r - 1][c] == '0'){
                if (c < p) shift.pb(M - p + c);
                else shift.pb(c - p);
                continue;
            }
        }
        bool good = false;
        int d;
        for (int dec : shift){
            int cnt = 0;
            for (int pos : idx){
                int nxt = pos + dec;
                if (nxt >= M) nxt -= M;
                if (grid[r][nxt] == '0') cnt++;
            }
            if (cnt == idx.size()){
                good = true;
                d = dec;
                break;
            }
        }
        if (!good) return false;
        for (int i = 0; i < idx.size(); i++){
            idx[i] += d;
            if (idx[i] >= M) idx[i] -= M;
        }
    }
    return true;
}
 
void solve(){
    string s;
    cin >> N >> M >> s;
    grid.resize(N);
    for (int i = 0; i < N; i++) cin >> grid[i];
    if (s.find('1') == -1){
        cout << 'Y' << endl;
        return;
    }
    string s1 = s;
    reverse(s1.begin(), s1.end());
    cout << (work(s) || work(s1) ? 'Y' : 'N') << endl;
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