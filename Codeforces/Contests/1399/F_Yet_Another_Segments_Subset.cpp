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
#define endl '\n'

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return max(a,b); }
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
    int n , cnt = 0, ans=1;
    cin >> n ;
    Seg<int> sg[n+5];
    map<int,int> mp ;

    vector<array<int,3>> v(n),v2 ;
    for (int i= 0 ;i<n ;i++){
        cin >> v[i][0] >> v[i][1];
        mp[v[i][0]]=1 ;
        mp[v[i][1]]=1;
        v[i][2]=i;
    }
    for (int i= 0 ;i<=n ;i++) sg[i].build(2*n+3);
    for (auto x : mp ) mp[x.F]=++cnt;
    for (int i=0;i<n;i++)v[i][0]=mp[v[i][0]],v[i][1]= mp[v[i][1]];
    v.pb({0,cnt,n});
    v2=v;
    sort (all(v2),[](array<int,3>a , array<int,3> b){
        if (a[1] <b[1]) return true ;
        else if (a[1] ==b[1] && a[0] <b[0]) return true; return false ;
    });
    sort (all(v),[](array<int,3>a , array<int,3> b){
        if (a[1] -a[0] < b[1] -b[0]) return true;
        if (a[1] -a[0] == b[1] - b[0] ) return a[1]<b[1];
        return false;
    });


    for (auto [l1,r1,i1]:v){
        for (auto [l2,r2,i2]:v2){
            if(i1==i2)continue;
            if (!(l1<=l2 && r2<=r1))continue;
            int curr = sg[i2].query(0,2*n+2);
            int wraya = sg[i1].query(0,l2-1);
            int nw = curr+wraya+1;
            nw = max(nw,sg[i1].query(r2,r2));
            sg[i1].upd(r2,nw);
        }
        ans = max (sg[i1].query(0,2*n+2)+1,ans);
    }

    cout << ans-1 << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}