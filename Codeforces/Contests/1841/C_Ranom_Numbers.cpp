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
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define non cout<<"-1\n";
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}

const ll N = 1e6 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0; T comb(T a, T b) { return  max (a,b); }
    ll n; vector<T> seg;
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


Seg<int> st ;
vector <int> cost {1,10,100,1000,10000}, v , mp1(5,-1),mp2(5,-1); 
int n ; 

ll costt(){
    ll res= 0 ;
    for (int i= 0 ;i<n ; i++){
        if ( i<n-1 && v[i]< st.query(i+1,n-1))
            res -= cost[v[i]];
        else  
            res += cost[v[i]];
    }   
    return res ;
}

void solve(){
    string ch ; 
    cin>> ch ;
    n = ch.size(); 
    int  i= 0 ;
    v.clear();
    v.resize(n);
    st.build(n);
    for (int i= 0 ;i<5 ; i++)mp1[i]=-1;
    for (int i= 0 ;i<5 ; i++)mp2[i]=-1;
    for (int i= 0 ;i<n ;i++){
        st.upd(i, ch[i]-'A');
        v[i]= ch[i]-'A';
        if (mp1[ch[i]-'A']==-1) mp1[ch[i]-'A']= i ;
        mp2[ch[i]-'A']= i ;
    }
    ll ans = -INF;
    for (auto i : mp1){
        if (i==-1) continue;
        ll stock = v[i];
        for (int j= 0 ;j<5 ;j++){
            st.upd(i,j);
            v[i]= j ;
            ans = max (ans,costt());
        }
        st.upd(i,stock);
        v[i] = stock ; 
    }
    for (auto i : mp2){
        if (i==-1) continue;
        ll stock = v[i];
        for (int j= 0 ;j<5 ;j++){
            st.upd(i,j);
            v[i]= j ;
            ans = max (ans,costt());
        }
        st.upd(i,stock);
        v[i] = stock ; 
    }
    cout << ans << endl;
}

int32_t main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
   #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;

}