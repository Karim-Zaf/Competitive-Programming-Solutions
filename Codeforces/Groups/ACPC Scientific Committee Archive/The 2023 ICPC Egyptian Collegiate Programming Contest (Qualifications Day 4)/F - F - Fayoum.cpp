/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

template<class T> struct Seg_mn {  /*CHANGE THE ID YA KARIM !!*/
    const T ID = INF; int n; vector<T> seg;
    T merge(T a, T b){ return  min ( a , b )  ; }
    Seg_mn(int _n){ n = _n ,seg.assign(2*n,ID); }
    void pull(int p){ seg[p] = merge(seg[2 * p],seg[2*p + 1]); }
    void upd(int p, T val){ seg[p+=n] = val; for(p/=2 ; p ; p/=2) pull(p); }
    T query(int l, int r) { T ra= ID, rb= ID; for(l+= n, r+= n + 1 ; l<r ; l/=2,r/=2){
            if(l&1) ra = merge(ra,seg[l++]); if(r&1) rb = merge(seg[--r],rb);
        }return merge(ra,rb);
    } void print(int i=-1){
        while(++i < n) cout<<(i==0?"sg : ":"")<<query(i,i)<<(i==n-1?"\n":" ");}
};
template<class T> struct Seg_mx {  /*CHANGE THE ID YA KARIM !!*/
    const T ID = -INF; int n; vector<T> seg;
    T merge(T a, T b){ return  max ( a , b )  ; }
    Seg_mx(int _n){ n = _n ,seg.assign(2*n,ID); }
    void pull(int p){ seg[p] = merge(seg[2 * p],seg[2*p + 1]); }
    void upd(int p, T val){ seg[p+=n] = val; for(p/=2 ; p ; p/=2) pull(p); }
    T query(int l, int r) { T ra= ID, rb= ID; for(l+= n, r+= n + 1 ; l<r ; l/=2,r/=2){
            if(l&1) ra = merge(ra,seg[l++]); if(r&1) rb = merge(seg[--r],rb);
        }return merge(ra,rb);
    } void print(int i=-1){
        while(++i < n) cout<<(i==0?"sg : ":"")<<query(i,i)<<(i==n-1?"\n":" ");}
};

void Solve(){
    int n , q ;
    cin >> n >> q ;
    vector<int> v(n+1) ;
    for (int i= 1 ;i<=n ; i++) cin >> v[i] ;
    Seg_mn<int> mn (n+1) ;
    Seg_mx<int> mx (n+1) ;
    for (int i= 1 ;i<=n ; i++) mn.upd(i,v[i]);
    for (int i= 1 ;i<=n ; i++) mx.upd(i,v[i]);

    while (q--){
        int l, r, w ;

        cin >> l >> r >> w ;
        int ans = 0;
        ans ^= mx.query(l,r);
        ans ^= mn.query(l,r);
        ans ^= w;

        cout << (ans == 0 ? "NO": "YES") << endl;

    }

}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
