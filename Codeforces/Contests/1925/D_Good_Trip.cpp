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

int fact[N] {1};

int arith (int n){
    return n*(n+1)/2%mod ;
}

int nbpairs (int n){
    return arith(n-1);
}

int C(int n ,int k ){
    return divide (fact[n], mult(fact[n-k],fact[k]));
}

void Solve() {
    int n , m , k , sum =0, ans = 0;
    cin >> n >> m >> k ;
    vector<array<int,3>> v (m);
    vector<int> cnt(k+10);
    for (auto &x: v){
        cin >> x[0]>> x[1] >> x[2] ;
        sum += x[2];
    }

    for (int i= 1; i<=k;i++){
        int nb = mult (C(k,i),binpow(nbpairs(n)-1,k-i));
        int suite = arith(i-1);
        int curr = mult (m, nb);
        int one = mult (suite ,curr);
        int two = mult(mult(i,sum) ,nb);

        ans = add (ans, one);
        ans = add (ans,two);
    }

    ans =divide(ans, binpow(nbpairs(n),k));

    cout << ans << endl;
}


void preprocess(){
    for (int i=1 ;i<N;i++)
        fact[i]= mult(fact[i-1],i);
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    preprocess();

    cin >> Test_case;
    while (Test_case--) Solve();
}