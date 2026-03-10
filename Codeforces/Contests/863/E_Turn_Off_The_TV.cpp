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

const ll N = 2e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

template<class T> struct Seg { // comb(ID,b) = b
    T ID ;
    ll n; vector<T> seg; function <T(T,T)> comb ;
    void build(ll _n) { n = _n; seg.assign(2*n,ID); }
    void pull(ll p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

void solve(){
    int n ;
    cin >> n ;
    map <pair<int,int>, array<int,3>> mp ;
    map <pair<int,int>, int > cnt ;
    vector <pair<int,int>> v(n);
    Seg <int> sg_mn , sg_mx;
    sg_mn.comb= [](int a,int b ){ return min (a,b);};
    sg_mx.comb= [](int a,int b ){ return max (a,b);};
    sg_mn.build(n); sg_mx.build(n); sg_mn.ID = 1e9 ; sg_mx.ID = 0 ;
    for (int i= 0 ; i<n ; i++) {
        int l , r ;
        cin >> l >> r ;
        v[i]= make_pair(l,r);
        mp[v[i]]= {i,0,0};
    }
    sort(all(v),[](pair<int,int> a , pair<int,int> b){
        if (a.F<b.F)return true;
        if (a.F == b.F && a.S >b.S) return true; return false ;
    });
    for (int i= 0;i<n ;i++) {
        if (cnt[v[i]]){cout << mp[v[i]][0] +1 << endl; return;}
        cnt [v[i]]++;
        mp[v[i]][1]= i;
        sg_mx.upd(i,v[i].S);
    }
    sort(all(v),[](pair<int,int> a , pair<int,int> b){
        if (a.S<b.S)return true;
        if (a.S == b.S && a.F >b.F) return true; return false ;
    });
    for (int i= 0;i<n ;i++) {
        mp[v[i]][2] = i;
        sg_mn.upd(i,v[i].F);
    }
    for (auto [p , a] : mp ){
        int l =1e9+4 , r=-1e9 ;
        if (a[1] -1 >=0)
            r = sg_mx.query(0, a[1]-1);
        if (a[2]+1 <n)
            l = sg_mn.query(a[2]+1,n-1);
        if (l<=r+1) {cout <<a[0]+1 << endl; return;}
    }
    cout << -1 << endl; return;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    //cin >> test_case ;
    while (test_case--)  solve() ;
}



// Failure gives you two choices: You stay down or You get up ;)