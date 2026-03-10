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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

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

Seg<int> mn , gc ;
int n, p;

set <int> le , ri;

int bsr(int i){
    int l = i , r= *le.lower_bound(i) , ans = i ;
    while (l<=r){
        int md = l + (r-l)/2 ;
        if (mn.query(i,md)==gc.query(i,md)){
            ans = md ;
            l = md +1 ;
        }else r= md -1 ;
    }
    return ans ;
}

int bsl(int i){
    int l = *prev(ri.upper_bound(i)) , r = i , ans = i ;
    while (l<=r){
        int md = l + (r-l)/2 ;
        if (mn.query(md,i)==gc.query(md,i)){
            ans = md ;
            r = md -1 ;
        }else l= md +1 ;
    }
    return ans ;
}

void init(){
    le.clear() ;ri .clear() ; le.insert(n-1) ,ri.insert(0) ;
    mn.comb =[](int a, int b ){return min(a,b);};
    gc.comb =[](int a, int b ){return __gcd(a,b);};
    mn.build(n) ;gc.build(n); mn.ID = INF ; gc.ID = 0;

}

void Solve() {
    cin >> n >> p;

    init();

    vector<int> v(n) , vis(n);
    vector<pair<int,int>> vp (n) ;
    for (int i= 0 ;i<n ;i++){
        cin >> v[i] ;
        vp[i]={v[i],i};
        mn.upd(i,v[i]); gc.upd(i,v[i]);
    }

    sort (all(vp));

    int ans = 0 , cnt = n-1 ;
    for (auto [x,pos] : vp){
        if (vis[pos]||x>p) continue;

        int righ = bsr (pos) , lef = bsl(pos);
        ri.insert(righ) ;
        le.insert(lef);
        for (int i= lef ; i<= righ ; i++) vis[i]= 1 ;

        ans += (righ-lef)*x;
        cnt -= righ -lef ;
    }

    cout << ans+ cnt *p  << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}