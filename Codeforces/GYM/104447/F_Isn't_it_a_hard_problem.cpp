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
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
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

const int N = 1e5 + 5 ;
string a[N] ;
ll s[N] , v[N] ;

int work(string& s)
{
    int ret = 0 ;
    int n = s.size() ;
    for(int i = 0 ; i<n/2 ; i++){
        int j = n-i-1 ;
        ret += s[i] != s[j] ;
    }
    return ret ;
}

template<class T> struct Seg { // comb(ID,b) = b
	const T ID = -1e18; T comb(T a, T b) { return max(a , b); }
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


void solve() {
    int n , k ; cin>>n>>k ;
    Seg<ll> st ; st.init(n+5) ;
    for(int i = 1 ; i<=n ; i++){
        cin>>a[i] ;
        s[i] = work(a[i]) ;
    }
    for(int i = 1 ; i<=n ; i++) cin>>v[i] ;
    ll l = 1 , r = 1 , curr = 0;
    vector<int> nex(n+1) ;
    while(l<=n){
        if(l>=r) r = l-1 , curr = 0 ;
        while(r+1<=n && curr + s[r+1] <=k){
            curr += s[r+1] ;
            r++ ;
        }
        nex[l] = r ;
        curr -= s[l] ;
        l++ ;
    }
//    for(int i = 1 ; i<=n ; i++) cout<<s[i]<<' ';cout<<endl;
//    for(int i =1 ; i<=n ; i++){
//        cout<<i<<' '<<nex[i]<<endl;
//    }
    for(int i = 1 ; i<=n ; i++){
        v[i] += v[i-1] ;
        st.upd(i  , v[i]) ;
    }
    ll ans = 0 ;
    for(int i = 1 ; i<=n ; i++){
        if(nex[i]<i) continue;
        ll y = st.query(i , nex[i]) ;
        ckmax(ans , y - v[i-1]) ;
    }
    cout<<ans<<endl;
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