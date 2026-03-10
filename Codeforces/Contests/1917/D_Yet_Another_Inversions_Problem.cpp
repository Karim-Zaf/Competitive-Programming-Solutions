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

const int N=6e5+30,mod=998244353,MOD=mod,INF=1e18+10;

ll binpow(ll a, ll k, ll res =1){
    while (k){
        if (k % 2) res = (res * a)%MOD;
        a = (a*a)%MOD;k/=2 ;
    }return res ;
}

ll modinv(ll a){return binpow(a,MOD-2);}
ll mult(ll a, ll b){b%=MOD;return a%MOD*b%MOD;}
ll add (ll a, ll b){ return ((a%mod + b%mod)%mod + mod)%mod;}
ll divide(ll a, ll b){
    a %= MOD; b = modinv(b) % MOD;
    return (a*b)%MOD;
}

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  add(a,b); }
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

int arith (int x){
    if (x<=0) return 0 ;
    return x*(x+1)/2 ;
}

Seg<int> pref[20];

void Solve() {
    int n , k ;
    cin >> n >> k ;

    vector<int> p(n+5) , q(k+5) ,pw(n+5);

    for (int i=1;i<=n ; i++)cin >> p[i] ;
    for (int i= 1; i<=k ; i++) cin >> q[i];

    Seg<int> lg [20],derr;

    for (int i=0; i<20; i++) lg[i].build(n+5);

    for (int i=1 ; i<=n ; i++){
        pw[i] = log2(p[i]);
        lg[pw[i]].upd(i,1);
        pref[pw[i]].upd(p[i],add(pref[pw[i]].query(p[i],p[i]),1ll));
    }

    int interne = 0;
    derr.build(k+1) ;
    for (int i=1 ;i<=k ;i++){
        interne= add(interne,derr.query(q[i],k));
        derr.upd(q[i],1);
    }

    int ans = mult (interne,n);

    for (int i=1; i<=n ; i++){

        for (int j= 0; j<pw[i]; j++){
            int cnt_inf = lg[j].query(i+1,n) ;
            int nwblasa = j+k-1;
            int diff = pw[i]-j, one =0;
            if (nwblasa>=pw[i]){
                int nb = nwblasa-pw[i]+1;
                one = add(arith (k-1),-arith(k-nb-1));
                assert (k-nb-1>=0);
            }
            int two = mult (min(diff,k),k);

            int nw =add (one,two);
            nw = mult (nw,cnt_inf);
            ans=add(ans,nw);
        }

        for (int j= pw[i]; j<20; j++){
            int nwblasa = pw[i]+k-1;
            if (nwblasa<=j)break;

            int cnt_sup = lg[j].query(i+1,n) ;
            int nw = arith (nwblasa-j);
            nw = mult (nw,cnt_sup);
            ans=add(ans,nw);
        }
    }

    for (int i= 1; i<=n ; i++){
        //same power

        pref[pw[i]].upd(p[i],add(pref[pw[i]].query(p[i],p[i]),-1ll));

        for (int j= 0 ; j<pw[i]; j++){
            int diff = pw[i]-j ;
            if (diff > k) continue;
            int curr = p[i]>> (pw[i]-j);
            if (curr>=N)continue;
            int cnt_inf = pref[j].query(0,curr);
            ans = add (ans,mult(cnt_inf,k-diff));
        }

        for (int j= pw[i] ; j<20; j++){
            int diff = j-pw[i] ;
            if (diff > k) continue;
            int curr = p[i]<<(j-pw[i]);
            if (curr>=N)continue;
            int cnt_sup = pref[j].query(0,curr);

            ans = add (ans,mult(cnt_sup,k-diff));
        }

    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    for (int i=0; i<20; i++)pref[i].build(N);
    while (Test_case--) Solve();
}