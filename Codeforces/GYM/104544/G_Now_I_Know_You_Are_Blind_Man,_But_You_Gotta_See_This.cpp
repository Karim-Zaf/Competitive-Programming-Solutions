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

const long long N=2e5+47,MOD=1e9+7,mod=1e9+7,INF=1e18;


long long binpow(long long a, long long k){
    long long res = 1;
    while (k){
        if (k % 2)
            res = (res * a)%MOD;
        a = (a*a)%MOD ;
        k/=2 ;
    }
    return res;
}

void Solve(){
    ll n ;
    cin >> n ;
    vector <ll> v(n ) , mp(n+6) , suff(n+6);
    for (ll i= 0;i<n; i++){
        cin >> v[i] ;
        if (i<N) mp[v[i]]++;
    }
    ll res = 0, curr =1;
    for (ll i=n+4 ; i>=0; i--) suff[i]= mp[i]+suff[i+1];

    for (ll i=0 ; i<n+4; i++){
        if (!mp[i])break;
        curr *= binpow(2,mp[i])-1+mod;
        curr %= mod ;
        res += (i+1)*curr%mod*binpow (2,suff[i+2])% mod;
        res %= mod ;
    }
    cout << res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}