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

const ll N =2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

int fact[N];

long long binpow(long long a, long long k){
    long long res = 1;
    while (k){
        if (k % 2)
            res = (res * a)%MOD;
        a = (a*a)%MOD ;
        k/=2 ;
    }
    return res ;
}

ll modinv(long long a){return binpow(a, MOD-2);}

ll divide(ll a, ll b){
    a %= MOD;
    b = modinv(b) % MOD;
    long long c = a*b;
    c%=MOD;
    return c;
}

void solve() {
    int n , k , res = 1 ;
    cin >> n>> k ;
    vector <int>v ;
    v.pb(0);
    for (int i= 0 ;i<k ;i++){
        int x ;
        cin >> x ;
        v.pb(x);
    }
    sort (all(v));
    v.pb(n);
    function <int(int,int)> Comb = [&] (int a ,int b ){
        return divide (fact[a],fact[a-b]*fact[b]%mod);
    };
    int beki = n ;
    for (int i= 1;i<k+2 ;i++){
        int diff = v[i] - v[i-1] ;
        if (diff==1) continue;
        res *= Comb (beki, diff);
        res %= mod ;
        beki -= diff ;
    }
    res *= fact [beki];
    res %= mod ;
    cout << res << endl;
}

void preprocess(){
    fact[0]=1 ;
    for (int i= 1; i<N;i++){
        fact[i] = fact[i-1]*i;
        fact[i]%= mod ;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    preprocess();
    while (test_case--)  solve() ;
}