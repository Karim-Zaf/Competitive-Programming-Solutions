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

int n ;
map<int,int> id ;
vector<int> v , pref;
set<pair<int,int>> ss ;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = INF;    ll n; vector<T> seg;
    T comb(T a, T b) { return  min(a,b); }
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
    }void print(){
        for(int i=0;i<n;i++)cout<<query(i,i)<<" ";cout<<'\n';}
};

int get (int val){
    pair<int,int> p={val,-INF};
    int ret = ss.lower_bound(p)->S ;
    return ret;
}

bool ok (int x){
    Seg<int> sg ;
    sg.build(n+10) ;
    sg.upd(id[0],0) ;
    for (int i= 1; i<=n;i++){
        int curr =get (pref[i]-v[i]-x);
        int mn = v[i]+ sg.query(curr,n+9);
        sg.upd(id[pref[i]],mn);

    }

    int curr =get (pref[n]-x);
    int mn = sg.query(curr,n+9);

    if (mn>x)return false ;
    return true;
}

void init(){
    cin >> n ;
    v.resize(n+4);
    pref.resize(n+4);
    ss.clear();
    id.clear();
    id[0]=1 ;
}

void Solve() {
    init() ;

    for (int i=1 ;i<=n ;i++){
        cin >> v[i] ;
        pref[i]= pref[i-1]+ v[i] ;
        id[pref[i]]=1 ;
    }

    int cnt = 0 ;
    for (auto x: id) {
        id[x.F]=++cnt ;
        ss.insert({x.F,cnt});
    }


    int l =0 , r = 1e15 , ans =-1 ;
    while (l<=r){
        int md = l + (r-l)/2 ;
        if (ok(md)){
            r= md-1 ;
            ans = md ;
        }else l = md +1 ;
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}