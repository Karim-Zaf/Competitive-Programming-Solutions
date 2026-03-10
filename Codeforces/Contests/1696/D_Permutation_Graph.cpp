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

void Solve() {
    int n ;
    Seg<int> mx , mn ;
    cin >> n ;
    mx.comb = [](int a,int b){return max(a,b);};
    mn.comb =[](int a,int b){return min(a,b);};
    mx.build(n+5);mn.build(n+5);mx.ID= -INF,mn.ID = INF;

    vector<int> v(n+4), pos(n+5);

    for (int i= 1;i<=n;i++){
        cin >> v[i];
        pos[v[i]]=i;
        mx.upd(i,v[i]);
        mn.upd(i,v[i]);
    }

    auto nxtmx=[&](int pos)->int{

        int l = pos+1 , r = n ,ret = pos;
        while(l<=r){
            int md = l+ (r-l)/2 ;
            if (mx.query(pos,md)==v[pos]){
                ret =md ;
                l = md+1 ;
            }else r = md-1;
        }
        return ret;
    };

    auto nxtmn=[&](int pos)->int{

        int l = pos+1 , r = n ,ret = pos;

        while(l<=r){
            int md = l+ (r-l)/2 ;
            if (mn.query(pos,md)==v[pos]){
                ret =md ;
                l = md+1 ;
            }else r = md-1;
        }
        return ret;
    };

    function <int(int)> work =[&](int x)->int{
        if (x==n)return 0 ;

        int one = nxtmn(x);
        one = mx.query(x,one);
        one = pos[one];

        int two = nxtmx(x);
        two = mn.query(x,two);
        two = pos[two];

        int nxt = max (one,two);
        return 1 + work(nxt);
    };

    cout << work(1) <<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}