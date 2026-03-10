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


void Solve() {
    Seg<int> sg ;
    int n , k , flag = 1,lst=-1;
    cin >> n >> k;
    map <int,int> mp ;
    sg.build(10*n);
    vector<int> a(n+5),pref(n+4);
    pref[1]=2*n+5;
    for (int i= 2; i<=n+1;i++){
        cin >> a[i] ;
        pref[i]=(a[i]>=k? 1: -1)+pref[i-1];
        flag&=(a[i]==k);
        mp[a[i]]++;
    }
    if (flag){cout <<"yes\n";return;}
    sg.upd(2*n+5,1);

    for (int i= 3 ; i<=n+1; i++)
        if (a[i-1]>=k&& a[i]==k){cout<<"yes\n";return;}
        else if (a[i]>=k&& a[i-1]==k){cout<<"yes\n";return;}

        
    for (int i= 2 ; i<=n+1; i++){
        int curr = sg.query(0,pref[i]-1);
        if (curr<i-1&&mp[k]){cout << "yes\n";return;}
        sg.upd(pref[i],min(sg.query(pref[i],pref[i]),i));
    }

    cout << "no\n";
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}