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
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define nop cout<<"-1"<<endl;

const ll N = 1e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = make_pair(0,0);    ll n; vector<T> seg;
    T comb(T a, T b) { if (a.F>= b.F) return a; return b; }
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


pair <int,int> merge (pair <int,int> a , pair <int,int> b){
    if (a.F>= b.F) return a;
    return b;
}

void solve(){
    int n ;
    ll d ;
    cin >> n >> d ;
    Seg <pair<int,int>> sg ;
    vector <ll> v(n+1) , temp (n+1);
    vector <int> prec (n+1);
    map <ll,int> id ;
    for (int i= 1 ;i<=n ;i++) {
        cin >> v[i];
        temp[i]=v[i];
    }
    sort (all(temp));
    for (int i= 1 ;i<=n ;i++)
        id[v[i]]= lower_bound(all(temp),v[i]) -temp.begin();
    prec[1]=-2;
    sg.build(n+4);
    for (int i= 1 ;i<=n ;i++){
        ll akber = v[i]+d ;
        ll asgher = v[i]-d ;
        akber = lower_bound (all(temp),akber) -temp.begin();
        asgher = upper_bound(all(temp),asgher) -temp.begin();
        asgher --;
        pair<int,int> p =  merge (sg.query(0,asgher),sg.query(akber,n+1));
        if (p.S==0) {
            sg.upd(id[v[i]],make_pair(1,i));
            prec[i] = -2 ;
            continue;
        }
        sg.upd(id[v[i]],merge(sg.query(id[v[i]],id[v[i]]),make_pair(p.F+1,i)));
        prec [i]= p.S;
    }
    pair <int,int> p = sg.query(1,n);
    vector <int> res;
    int i=p.S , j= 0 ;
    while (i!=-2){
        res .pb(i);
        i = prec[i];
    }
    cout << res.size()<< endl;
    reverse(all(res));
    for (auto x : res) cout << x << " "; cout << endl;
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