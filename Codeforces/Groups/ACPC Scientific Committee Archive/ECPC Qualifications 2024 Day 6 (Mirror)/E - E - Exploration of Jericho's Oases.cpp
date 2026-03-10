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

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 1e9;    ll n; vector<T> seg;
    T comb(T a, T b) { return  min(a, b);}
    void init(ll _n) { n = _n; seg.assign(2*n,ID); }
    void pull(ll p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }return comb(ra,rb);
    }
};

void solve(){
    int N, Q;
    cin >> N;
    vector<vector<int>> comp;
    Seg<int> st; st.init(N + 5);
    vector<int> a(N + 1), p(N + 1), vis(N + 1), root(N + 1), pos(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> p[i];
    for (int i = 1; i <= N; i++) st.upd(i, a[i]);
    int cnt = 0;
    for (int i = 1; i <= N; i++){
        if (vis[p[i]]) continue;
        vector<int> vec;
        int j = p[i];
        while (!vis[j]){
            pos[j] = (int)vec.size();
            root[j] = cnt;
            vec.pb(j);
            vis[j]++;
            j = p[j];
        }
        comp.push_back(vec);
        cnt++;
    }
    cin >> Q;
    for (int q = 1; q <= Q; q++){
        int t;
        cin >> t;
        if (t == 1){
            int K;
            cin >> K;
            vector<int> new_a(N + 1);
            for (int i = 1; i <= N; i++){
                int ind = root[i];
                int sz = comp[ind].size();
                int shift = K % sz;
                new_a[i] = a[comp[ind][(pos[i] + shift) % sz]];
                st.upd(i, new_a[i]);
            }
            a.swap(new_a);
        }
        else{
            int M;
            cin >> M;
            for (int i = 1; i <= M; i++){
                int l, r;
                cin >> l >> r;
                cout << st.query(l, r) << endl;
            }
        }
    }
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