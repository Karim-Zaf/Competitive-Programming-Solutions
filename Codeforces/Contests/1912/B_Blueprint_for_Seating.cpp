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

const int  N=2e5+30,MOD=998244353,mod=998244353,INF=1e18+10;

int fact[N] ;

ll binpow(ll a, ll k){
    ll res = 1;
    while (k){
        if (k % 2)
            res = (res * a)%MOD;
        a = (a*a)%MOD ;
        k/=2 ;
    }
    return res ;
}

ll modinv(ll a){return binpow(a,MOD-2);}
ll mult(ll a, ll b){return a%MOD*b%MOD;}
ll add (ll a, ll b){ return ((a%mod + b%mod)%mod + mod)%mod;}
ll divide(ll a, ll b){
    a %= MOD;
    b = modinv(b) % MOD;
    ll c = (a*b)%MOD;
    return c;
}

int c ( int n , int k ){
    if (k>n) return 0 ;
    if (n<0 ||k<0) return 0 ;
    return divide (fact[n],fact[k]*fact[n-k]%mod) ;
}

void Solve() {
    int n , k ,ways = 0;
    cin >> n >> k ;
    int reste = n % (2*k) , numb = n/(2*k)+1;
    int ans = k*(numb-2)*(numb-1) + reste* (numb-1) ;

    for (int x = 0 ;2*x<=reste&&x<=k-1; x++){
        int g = (reste-2*x)/(k+1-x) ;
        if (g!=1&&n<2*k) continue;
        ways += c(k-1,x) * c (k+1-x,reste-2*x)%mod;
        ways %= mod ;
    }

    cout << ans << " " << ways << endl;
}

void preprocess(){
    fact[0]= 1 ;
    for (int i= 1; i<N ; i++ ) fact[i]= (fact[i-1] * i ) % mod ;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif

    preprocess();
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}