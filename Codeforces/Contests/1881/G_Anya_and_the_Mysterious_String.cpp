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

int Tree[4 * N], a[N];
int lazy[4 * N], n;
int upd[4 * N];

int merge (int a, int b){return a+b ;}

void unlazy(int id){
    if (upd[id]==0) return;
    int l = 2*id +1 , r = 2*id +2 ;
    Tree[id]+= lazy[id];
    Tree[id]%=26 ;
    lazy[l]+= lazy[id], lazy[r]+= lazy[id];
    upd[l]= upd[r]= 1 , upd[id]=lazy[id]=0;
}

void update (int qs , int qe , int val , int ns=0 , int ne=n-1 , int id =0){
    unlazy(id);
    if (qs >ne|| qe <ns) return ;
    if (qs <= ns && ne <= qe ){
        lazy[id]+=val, upd[id]=1;
        unlazy(id);
        return ;
    }
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    update (qs , qe , val , ns , md, l);update (qs ,qe, val , md+1 , ne ,r);
    Tree[id]=merge(Tree[l],Tree[r]);
}
int query (int qs , int qe ,  int ns=0 , int ne=n-1 , int id =0){
    unlazy(id);
    if (qs >ne|| qe <ns) return 0;
    if (qs <= ns && ne <= qe )return Tree[id];
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    return query (qs , qe , ns , md, l)+query (qs ,qe,  md+1 , ne ,r);
}


template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  max(a,b); }
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
Seg<int> sg1,sg2;


void Solve() {
    int q ;
    string s;
    cin >> n >> q >> s;
    sg1.build(n+5);
    sg2.build(n+5);

    for (int i= 0 ; i<n ;i++){
        if (i+1<n && s[i+1]==s[i])sg1.upd(i,1);
        if (i+2<n && s[i+2]==s[i])sg2.upd(i,1);
        update(i,i,-query(i,i)+s[i]-'a');
    }

    auto change =[&](int x){
        if (x<0||x>=n)return;
        sg1.upd(x,0);
        sg2.upd(x,0);
        if (x+1<n && query(x,x)==query(x+1,x+1))sg1.upd(x,1);
        if (x+2<n && query(x,x)==query(x+2,x+2))sg2.upd(x,1);
    };

    while(q--){
        int x , l , r;
        cin >> x >> l >> r ;
        l--;r--;
        if (x==1){
            cin >> x;
            update(l,r,x);
            change (l-2),change (l-1),change (r),change (r-1);
        }else {
            int ans = sg1.query(l,r-1) | sg2.query(l,r-2);
            cout << (ans? "NO": "YES") << endl;
        }
    }

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}