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
const int Nax = 1e6 + 7;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
 
void solve(){
    int N, M;
    cin >> N;
    vector<string> a(N + 1);
    vector<int> pos(N + 1), ans(N + 1, -1), seen(N + 1);
    set<int> need[N + 1], c[N + 1];
    map<string, int> id;
    for (int i = 1; i <= N; i++){
        cin >> a[i];
        id[a[i]] = i;
    }
    cin >> M;
    for (int i = 1; i <= M; i++){
        int K, W;
        cin >> K >> W;
        set<int> p;
        for (int j = 0; j < K; j++){
            string s;
            cin >> s;
            p.insert(id[s]);
            pos[id[s]] = max(pos[id[s]], W); 
        }
        if (need[W].size() == 0){
            need[W].swap(p);
            continue;
        }
        set<int> res;
        for (int i = 1; i <= N; i++){
            if (need[W].find(i) != need[W].end() && p.find(i) != p.end())
                res.insert(i);
        }
        need[W].swap(res);
    }
    for (int i = 1; i <= N; i++){
        vector<int> erase;
        for (int x : need[i]){
            if (pos[x] != i) erase.pb(x);
        }
        for (int x : erase) need[i].erase(x);
    }
    for (int i = 1; i <= N; i++)
        if (pos[i] > 0 && need[pos[i]].find(i) == need[pos[i]].end())
            c[pos[i]].insert(i);
    for (int i = 1; i <= N; i++){
        if (need[i].size()){
            ans[i] = *need[i].begin();
            seen[ans[i]]++;
            need[i].erase(need[i].begin());
            for (int x : need[i]) c[i].insert(x);
            continue;
        }
        if (c[i].size()){
            ans[i] = *c[i].begin();
            seen[ans[i]]++;
            c[i].erase(c[i].begin());
        }
    }
    for (int i = 1; i <= N; i++){
        for (int j = i + 1; j <= N; j++){
            if (c[i].size() == 0) break;
            if (ans[j] == -1){
                ans[j] = *c[i].begin();
                seen[ans[j]]++;
                c[i].erase(c[i].begin());
            }
        }
        assert(c[i].size() == 0);
    }
    int ind = 1;
    for (int i = 1; i <= N; i++){
        if (ans[i] > 0) continue;
        while (ind <= N && seen[ind]) ind++;
        seen[ind]++;
        ans[i] = ind;
    }
    for (int i = 1; i <= N; i++)
        cout << a[ans[i]] << " ";
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