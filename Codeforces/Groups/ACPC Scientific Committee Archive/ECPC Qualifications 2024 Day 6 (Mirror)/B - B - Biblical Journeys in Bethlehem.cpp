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
const int N_Max = 1e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

int a[N_Max], x[N_Max], y[N_Max], id[N_Max];
int nxt[33 * N_Max][2];
int sub[33 * N_Max][2];
map<int, int> mp;
ll ans[N_Max];
int N, Q, K, l, r, cnt;
ll tot;

void ins(int x){
    int curr = 1;
    for (int i = 29; i >= 0; i--){
        int c = (x >> i) & 1;
        if (nxt[curr][c] == -1) nxt[curr][c] = cnt++;
        sub[curr][c]++;
        curr = nxt[curr][c];
    }
}

void dlt(int x){
    int curr = 1;
    for (int i = 29; i >= 0; i--){
        int c = (x >> i) & 1;
        assert(curr != -1);
        sub[curr][c]--;
        curr = nxt[curr][c];
    }
}

void add(int x){
    tot += mp[(x ^ K)];
    int curr = 1;
    for (int i = 29; i >= 0; i--){
        if (curr == -1) break;
        int cx = (x >> i) & 1;
        int ck = (K >> i) & 1;
        if (ck == 1) tot += sub[curr][cx];
        curr = nxt[curr][(cx ^ ck)];
    }
    ins(x);
    mp[x]++;
}

void rmv(int x){
    dlt(x);
    mp[x]--;
    int curr = 1;
    for (int i = 29; i >= 0; i--){
        if (curr == -1) break;
        int cx = (x >> i) & 1;
        int ck = (K >> i) & 1;
        if (ck == 1) tot -= sub[curr][cx];
        curr = nxt[curr][(cx ^ ck)];
    }
    tot -= mp[(x ^ K)];
}

void update(int curr_id){
    while (r < y[curr_id]) add(a[++r]);

    while (l > x[curr_id]) add(a[--l]);

    while (l < x[curr_id]) rmv(a[l++]);

    while (r > y[curr_id]) rmv(a[r--]);
}

void mo(){
    int B = sqrt(N);
    sort(id + 1, id + Q + 1, [B](int a, int b){return make_pair(x[a] / B, y[a]) < make_pair(x[b] / B, y[b]);});
    l = 1, r = 0;
    for (int i = 1; i <= Q; i++){
        int curr_id = id[i];
        update(curr_id);
        ans[curr_id] = tot;
    }
}

void solve(){
    cin >> N >> K >> Q;
    cnt = 2;
    mp.clear();
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= Q; i++){
        cin >> x[i] >> y[i];
        id[i] = i;
    }
    tot = 0;
    mo();
    for (int i = 1; i <= Q; i++) cout << ans[i] << " ";
    cout << endl;
    for (int i = 0; i <= cnt; i++){
        nxt[i][0] = nxt[i][1] = -1;
        sub[i][0] = sub[i][1] = 0;
    }
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    memset(nxt, -1, sizeof(nxt));
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}