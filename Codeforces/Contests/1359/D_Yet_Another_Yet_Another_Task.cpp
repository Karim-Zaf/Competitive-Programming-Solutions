/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define kar(...)
#endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int  N=1e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

map <int,vector <int> > mp ;
int pref[N], v[N] ;

template<class T> struct Seg { // comb(ID,b) = b
    T ID ; ll n; vector<T> seg; function <T(T,T)> comb ;
    void build(ll _n) { n = _n; seg.assign(2*n,ID); }
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

void Solve() {
    int n , res = 0;
    cin >> n ;
    set <int> s ;
    Seg<int> mx ; Seg<int> mn ;
    mx.ID= -INF ; mn.ID = INF ;
    mx.comb= [](int a, int b) {return max(a,b);};
    mn.comb= [](int a, int b) {return min(a,b);};
    mx.build(n+5); mn.build(n+5);
    mn.upd(0,0); mx.upd(0,0);
    s.insert (0);
    s.insert (n+1);
    for (int i= 1 ; i<=n ; i++ ){
        cin >> v[i] ;
        pref[i]= v[i]+ pref[i-1] ;
        mp[v[i]].pb(i);
        mx.upd(i,pref[i]);
        mn.upd(i,pref[i]);
    }
    for (int i= 30; i>= -30; i--){
        for (auto pos : mp[i]) {
            auto it = s.lower_bound(pos);
            int one = *it , two = *prev(it);
            res = max (res , mx.query(pos,one-1)-mn.query(two,pos-1)-i);
        }
        for (auto pos : mp[i]) s.insert(pos);
    }
    cout << res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}