/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
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
#define int ll

const ll N =2e5+ 8 ,  MOD =1e9+7 , mod=1e9+7 , INF = 1e18;

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

void solve(){
    int n ;
    cin >> n ;
    Seg <int> sg  ;
    sg.build(n);
    vector <array<int,3>> intr (n) , a(n) ;
    multiset <pair <int,int>> vp ;
    vector <pair <int,int>> vpp ;

    for (int i= 0 ;i< n ;i++){
        cin >> intr[i][1] >> intr[i][0] >> a[i][1]>> a[i][0] ;
        intr[i][0]= a[i][0] ;
    }
    sort (rall(a));
    sort (all(intr));
    for (int i= 0 ;i<n;i++) sg.upd(i,intr[i][1]) ;
    for (int i= 0 ; i<n ;i++){
        array<int,3> curr = {a[i][1],0,0}  ;
        int pos = lower_bound (all(intr) ,curr) - intr.begin() ;
        int cc= a[i][1] ;
        if (pos <n) {
            cc = min (cc ,sg.query (pos , n-1)) ;
        }
        vp.insert( {cc,a[i][0]});
    }
    for (auto x : vp ) vpp.pb(x);

    sort (all(vpp));
    for (int i=1 ; i<vpp.size();i++){
        vpp[i].S = max(vpp[i].F ,max (vpp[i].S , vpp[i-1].S )) ;
    }
    int q ;
    cin >> q ;
    vector<int> ans(vpp.size(),-1) ;
    ans[vpp.size()-1]= vpp.back().S ;
    function<ll(ll, vector<ll>&)> work =[&](int x,vector<int> &ans )-> ll {
        pair <int,int> p = {x,INF};
        int pos = upper_bound (all(vpp),p)-vpp.begin();
        if (pos <= 0 ) return x ;
        if (pos >= vpp.size()) return max (vpp[pos-1].S , x);
        if (ans[pos-1]==-1 && x< vpp[pos - 1].S ){
            ans[pos - 1] = max(vpp[pos-1].S, work(vpp[pos - 1].S, ans));
        }
        return max (x ,ans[pos-1]);
    };
    while (q--){
        int x ; cin >> x ;
        cout << work(x, ans)<< " ";
    }
    cout << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}