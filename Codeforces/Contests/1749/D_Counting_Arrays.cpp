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

const int  N=3e5+30,MOD=998244353,mod=998244353,INF=1e18+10;

ll binpow(ll a, ll k){
    ll res = 1;
    while (k){
        if (k % 2) res = (res * a)%MOD;
        a = (a*a)%MOD ;
        k/=2 ;
    }
    return res ;
}

ll mult(ll a, ll b){return a%MOD*b%MOD;}
ll add (ll a, ll b){ return ((a%mod + b%mod)%mod + mod)%mod;}

void Solve() {
    int n , m , lcm =1 ;
    cin >> n >> m ;
    int ans = 0, minus=0, prd =1;

    for (int i= 1 ;i<=n;i++){
        ans = add (ans,binpow (m%mod,i));
        if (__gcd (lcm,i)==1 &&lcm <= m) lcm *=i ;
        prd =mult(m/lcm,prd) ;
        minus = add(minus,prd);
    }
    cout << add (ans ,-minus) << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}