#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define clean(v) (v).resize(distance((v).begin(), unique(all(v))));
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
 
void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
 
template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
 
void nop() {
    cout << -1 << endl;
    return;
}
 
 
const int N = 1e5+5 ;
int a[N] , b[N] , pos[N] ;
 
template<class T> struct Seg { // comb(ID,b) = b
	const T ID = 0; T comb(T a, T b) { return a+b; }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};
 
int work(string s){
    ll h = stoi(s.substr(0 , 2)) ;
    ll m = stoi(s.substr(3 , 2)) ;
    return h*60 + m ;
}
 
void solve() {
    int n , m ; cin>>n>>m ;
    m*= 60 ;
    int tot = 0 ;
    for(int i = 1 ; i<=n ; i++){
        string s , t ; cin>>s>>t ;
        tot += work(t) - work(s) ;
    }
    if(tot>=m){
        yes ;
    }
    else no ;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    io();
    ll tt = 1;
    cin>>tt ;
    while (tt--) {
        solve();
    }
 
    return 0;
}