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

const int  N=1e7+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  a+b; }
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

void Solve() {
    int n , m , q ;
    cin >> n >> m >> q ;

    vector<int> x(m),v(m) ,mp(n+5);
    set<int> s ;
    Seg<int> sg ;
    sg.build(n+4) ;

    for (auto &e:x)cin >> e ;
    for (int i= 0;i<m ;i++){
        cin >> v[i] ;
        mp[x[i]]= v[i];
    }

    for (auto e : x) s.insert(e);

    auto kodemi=[&](int x){
        auto it = s.upper_bound(x);
        if (it == s.end()) return n;
        return *it;
    };
    auto cnt =[&] (int point, int r){
        int nxt = kodemi(point);

        int one = nxt - point -1;
        one = (one+1)*one/2 ;


        int two = nxt - r-1;
        two = (two+1)*two/2 ;

        int ret = one -two;
        ret *=mp[point] ;
        return ret;
    };

    s.insert(0);
    s.insert(n+1);


    sort(all(x));
    for (int i=0 ; i<m-1 ;i++){
        sg.upd(x[i],cnt(x[i],x[i+1]-1));
    }

    auto get =[&](int x){
        if (x==0) return 0ll ;
        int pos = *prev(s.upper_bound(x));
        int kablou = *prev(s.lower_bound(pos));
        return sg.query(0,kablou)+ cnt (pos,x);
    };


    auto update =[&](int x){
        int pos = *prev(s.lower_bound(x));
        sg.upd(pos,0);

        sg.upd(pos,cnt(pos,kodemi(pos)-1));
        sg.upd(x,cnt(x,kodemi(x)-1));
    };

    while(q--){
        int e , l , r , xx , vv; cin >> e ;
        if (e==1){
            cin >> xx >> vv ;
            mp[xx]=vv;
            x.pb(xx);
            s.insert(xx);

            update (xx);
        }
        else {
            cin >> l >> r ;
            cout << get (r) -get(l-1) << endl;
        }
    }

}

int32_t main(){
     #ifndef ONLINE_JUDGE
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
     #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}