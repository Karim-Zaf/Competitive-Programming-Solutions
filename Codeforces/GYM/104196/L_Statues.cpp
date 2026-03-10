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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N + 1, vector<int>(M + 1));
    vector<int> a;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cin >> grid[i][j];
            if (grid[i][j] != -1) a.pb(grid[i][j]);
        }
    }
    sort(a.begin(), a.end());
    int ans1 = 0, ind = 0;
    for (int i = 1; i <= M; i++){
        int r = 1, cnt = 0;
        map<int, int> freq;
        for (int c = i; c >= 1; c--){
            if (r > N) break;
            if (grid[r][c] != -1) freq[grid[r][c]]++, cnt++;
            r++;
        }
        int lim = ind + cnt - 1;
        for (int j = ind; j <= lim; j++)
            freq[a[j]] = max(freq[a[j]] - 1, 0);
        for (auto [x, occ] : freq) ans1 += occ;
        ind = lim + 1;
    }
    for (int i = 2; i <= N; i++){
        int r = i, cnt = 0;
        map<int, int> freq;
        for (int c = M; c >= 1; c--){
            if (r > N) break;
            if (grid[r][c] != -1) freq[grid[r][c]]++, cnt++;
            r++;
        }
        int lim = ind + cnt - 1;
        for (int j = ind; j <= lim; j++)
            freq[a[j]] = max(freq[a[j]] - 1, 0);
        for (auto [x, occ] : freq) ans1 += occ;
        ind = lim + 1;
    }
 
    int ans2 = 0;
    ind = 0;
    for (int i = 1; i <= M; i++){
        int r = N, cnt = 0;
        map<int, int> freq;
        for (int c = i; c >= 1; c--){
            if (r < 1) break;
            if (grid[r][c] != -1) freq[grid[r][c]]++, cnt++;
            r--;
        }
        int lim = ind + cnt - 1;
        for (int j = ind; j <= lim; j++)
            freq[a[j]] = max(freq[a[j]] - 1, 0);
        for (auto [x, occ] : freq) ans2 += occ;
        ind = lim + 1;
    }
    for (int i = N - 1; i >= 1; i--){
        int r = i, cnt = 0;
        map<int, int> freq;
        for (int c = M; c >= 1; c--){
            if (r < 1) break;
            if (grid[r][c] != -1) freq[grid[r][c]]++, cnt++;
            r--;
        }
        int lim = ind + cnt - 1;
        for (int j = ind; j <= lim; j++)
            freq[a[j]] = max(freq[a[j]] - 1, 0);
        for (auto [x, occ] : freq) ans2 += occ;
        ind = lim + 1;
    }
 
    int ans3 = 0;
    ind = 0;
    for (int i = M; i >= 1; i--){
        int r = N, cnt = 0;
        map<int, int> freq;
        for (int c = i; c <= M; c++){
            if (r < 1) break;
            if (grid[r][c] != -1) freq[grid[r][c]]++, cnt++;
            r--;
        }
        int lim = ind + cnt - 1;
        for (int j = ind; j <= lim; j++)
            freq[a[j]] = max(freq[a[j]] - 1, 0);
        for (auto [x, occ] : freq) ans3 += occ;
        ind = lim + 1;
    }
    for (int i = N - 1; i >= 1; i--){
        int r = i, cnt = 0;
        map<int, int> freq;
        for (int c = 1; c <= M; c++){
            if (r < 1) break;
            if (grid[r][c] != -1) freq[grid[r][c]]++, cnt++;
            r--;
        }
        int lim = ind + cnt - 1;
        for (int j = ind; j <= lim; j++)
            freq[a[j]] = max(freq[a[j]] - 1, 0);
        for (auto [x, occ] : freq) ans3 += occ;
        ind = lim + 1;
    }
 
    int ans4 = 0;
    ind = 0;
    for (int i = M; i >= 1; i--){
        int r = 1, cnt = 0;
        map<int, int> freq;
        for (int c = i; c <= M; c++){
            if (r > N) break;
            if (grid[r][c] != -1) freq[grid[r][c]]++, cnt++;
            r++;
        }
        int lim = ind + cnt - 1;
        for (int j = ind; j <= lim; j++)
            freq[a[j]] = max(freq[a[j]] - 1, 0);
        for (auto [x, occ] : freq) ans4 += occ;
        ind = lim + 1;
    }
    for (int i = 2; i <= N; i++){
        int r = i, cnt = 0;
        map<int, int> freq;
        for (int c = 1; c <= M; c++){
            if (r > N) break;
            if (grid[r][c] != -1) freq[grid[r][c]]++, cnt++;
            r++;
        }
        int lim = ind + cnt - 1;
        for (int j = ind; j <= lim; j++)
            freq[a[j]] = max(freq[a[j]] - 1, 0);
        for (auto [x, occ] : freq) ans4 += occ;
        ind = lim + 1;
    }
    cout << min({ans1, ans2, ans3, ans4}) << endl;
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