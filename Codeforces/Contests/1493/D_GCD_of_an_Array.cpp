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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

vector<int> spf(N) ;

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

void sieve (){
    for (int i= 2 ;i<N ;i++){
        if (spf[i]) continue;
        for (int j= i; j<N ; j+=i)
            spf[j]= i ;
    }

}

map <int,int> fact (int x){
    map <int,int> ret ;
    while (x!=1){
        ret[spf[x]]++;
        x/= spf[x] ;
    }
    return ret ;
}

map<int,int> mrg (map <int,int> a , map <int,int> b){
    map<int,int> ret ;
    for (auto x :b) ret[x.F]+= x.S ;
    for (auto x :a) ret[x.F]+= x.S ;
    return ret ;
}

void Solve() {
    int n , q; cin >> n >> q;
    sieve();
    vector<pair<int,int>> query(q+3) ;
    vector<int> ans(q+2,1);
    map <int,int> mp[n+2] ;
    for (int i= 1 ; i<=n ; i++){
        int x ; cin >> x;
        mp[i]=mrg (mp[i],fact(x));
    }

    for (int qq = 1 ; qq<=q ; qq++ ){
        int i , x;
        cin >> i >> x;
        for (auto xx : fact(x))mp[i][xx.F]+=xx.S;
        query[qq]={i,x};
    }

    map <int,int> gcd =mp[1] ;
    for (int i=1 ;i<=n ;i++){
        for (auto x: gcd ){
            gcd[x.F]= min (gcd[x.F],mp[i][x.F]);
        }
    }
    for (auto x: gcd) ans[q]= mult (ans[q], binpow(x.F ,x.S));

    for (int i= q-1; i>=1 ; i--){
        auto [pos,val]=query[i+1] ;
        ans [i]= ans[i+1] ;
        map <int,int> fct = fact (val);
        for (auto x : fct){
            mp[pos][x.F]-= fct[x.F] ;
            if (mp[pos][x.F]<gcd[x.F]){
                int diff = gcd[x.F]- mp[pos][x.F] ;
                ans[i]=divide(ans[i],binpow(x.F,diff));
                gcd[x.F]=mp[pos][x.F];
            }
        }
    }
    for (int i =1 ; i<=q ;i++)cout<< ans[i] << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}