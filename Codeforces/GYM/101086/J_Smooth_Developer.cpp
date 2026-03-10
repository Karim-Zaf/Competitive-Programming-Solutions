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

map<string, vector<string>> graph;
map<string, int> visited, apprearance;
vector<pair<int, string>> ans;

void dfs(string Node){
    ans.push_back({apprearance[Node], Node});
    visited[Node]++;
    for (string child : graph[Node]){
        if (visited[child] == 0)
            dfs(child);
    }
}

bool comp(pair<int, string> p1, pair<int, string> p2){
    return p1.F < p2.F;
}

void solve(){
    int N, K;
    cin >> N >> K;
    for (auto x : graph)
        graph[x.F].clear();
    visited.clear();
    apprearance.clear();
    ans.clear();
    int cnt = 1;
    for (int i = 0; i < N; i++){
        string s;
        int c;
        cin >> s >> c;
        if (apprearance[s] == 0)
            apprearance[s] = cnt++;
        for (int j = 0; j < c; j++){
            string t;
            cin >> t;
            if (apprearance[t] == 0)
                apprearance[t] = cnt++;
            graph[s].push_back(t);
        }
    }
    for (int i = 0; i < K; i++){
        string s;
        cin >> s;
        if (visited[s] == 0)
            dfs(s);
    }
    sort(ans.begin(), ans.end(), comp);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].S << endl;
}

int main(){
    FAST
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //#endif
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
