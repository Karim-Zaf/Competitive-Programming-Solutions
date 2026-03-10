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
#define endl '\n'
#define int ll


const long long N=21,MOD=998244353,mod=998244353,INF=1e18;


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

void Solve(){
    int n,m ;
    cin >> n;
    vector <pair<int,int>> a(n),v;
    map <int,int>mp ;
    map <int,int>mp2 ;
    for (int i= 0 ;i<n;i++)cin >> a[i].F ;
    for (int i= 0 ;i<n;i++)cin >> a[i].S ;
    for (auto [prime,exp]: a) mp[prime]=exp ;
    cin >> m;
    vector <pair<int,int>> b(m);
    for (int i= 0 ;i<m;i++)cin >> b[i].F ;
    for (int i= 0 ;i<m;i++)cin >> b[i].S ;
    for (auto [prime,exp]: b) {
        if (mp[prime]<exp){cout << 0 << endl;return;}
        mp2[prime]=exp;
    }
    for (auto [prime,exp]: a) {
        if (exp - mp2[prime]<=0)continue;
        v.pb({prime,exp - mp2[prime]});
    }
    cout << binpow(2,v.size())<< endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}