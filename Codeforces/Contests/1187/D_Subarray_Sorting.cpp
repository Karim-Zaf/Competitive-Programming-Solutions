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

const ll N = 2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 5e18 ;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 4e5;    ll n; vector<T> seg;
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
    }void print (){
        for (int i= 0 ; i<n ;i++)
        cout << query(i,i) << " " ;cout << endl;
    }
};

void solve(){
    int n ;
    cin >> n;
    vector <int> a(n) , b(n);
    set <int> mp[n+1];
    Seg <int> sg ;
    sg.build(n);
    for (int i= 0 ;i<n ;i++){
        cin >> a[i];
        sg.upd(i,a[i]);
        mp[a[i]].insert(i);
    }
    for (auto &x: b) cin >> x ;
    for (int i= 0 ;i<n;i++){
        if (mp[b[i]].empty()){cout << "NO\n"; return;}
        int next = *mp[b[i]].begin();
        mp[b[i]].erase(next);
        if (b[i]> sg.query(0,next)){cout << "NO\n"; return;}
        sg.upd(next, INF);
//        sg.print();
    }
    cout << "YES\n";


}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}

// Failure gives you two choices: You stay down or You get up ;)