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

const ll N = 5e5 + 8 , MOD =1e9+7, mod=1e18+7, INF = 1e18 ;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = make_pair (INF,INF);    ll n; vector<T> seg;
    T comb(T a, T b) { if (a.F<b.F) return a ; return b ;}
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

int prec[N], ans[N];

void solve(){
    int n ;
    cin >> n;
    Seg <pair<int,int>> sg ;
    sg.build(n+1);
    vector <int> v(n+1);
    for (int i= 1 ; i<=n ;i++) cin >>v[i];
    int q ;
    cin >> q ;
    vector <array<int,3>> queries(q);
    for (int i= 0 ;i< q ; i++) {
        cin >> queries[i][0]>> queries[i][1];
        queries[i][2]= i;
    }
    sort (all(queries),[](array<int,3> a ,array<int,3> b){
        if (a[1]<b[1]) return true;
        if (a[1] == b[1] && a[0] <b[0]) return true;
        return false ;
    });
    kar (queries);
    int right = 1;
    for (int i = 0 ;i<q ;i++){
        for (int j = right ; j<= queries[i][1] ; j++){
            if (prec[v[j]]) sg.upd(prec[v[j]], {INF,INF});
            sg.upd (j, {prec[v[j]], v[j]});
            prec[v[j]]=j;
        }
        pair<int,int> mn = sg.query(queries[i][0],queries[i][1]);
        if (mn.F <queries[i][0]) ans[queries[i][2]]=mn.S;
        else  ans[queries[i][2]]=0;
//        for (int i= 1 ; i<= n ;i++) cout << sg.query(i,i).F << " ";cout << endl;
        right = queries[i][1]+1;
    }
    for (int i= 0 ; i<q ; i++)
        cout << ans[i] << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}

// Failure gives you two choices: You stay down or You get up ;)