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

const int N=3e5+30,mod=1e9+7,INF=1e18+10;

ll binpow(ll a, ll k,ll MOD, ll res =1){
    while (k){
        if (k % 2) res = (res * a)%MOD;
        a = (a*a)%MOD;k/=2 ;
    }return res ;
}

ll modinv(ll a,ll MOD){return binpow(a,MOD-2,MOD);}
ll mult(ll a, ll b,ll MOD){b%=MOD;return a%MOD*b%MOD;}
ll add (ll a, ll b,ll MOD){ return ((a%mod + b%mod)%mod + mod)%mod;}
ll divide(ll a, ll b,ll MOD){
    a %= MOD; b = modinv(b,MOD) % MOD;
    return (a*b)%MOD;
}

void Solve() {
    int n, prod=1, ans =1, j=0,prd=1;
    cin >> n ;
    vector<int>v(n),suff(n+4,1);
    vector<pair<int,int>> vp;
    map<int,int> mp ;
    for(auto &x:v){
        cin >> x;
        mp[x]++;
    }

    for (auto x : mp) {
        prod= mult (prod,x.S+1,mod-1);
        vp.pb(x);
    }

    for (int i= vp.size()-1;i>=0;i--){
        suff[i]= mult (suff[i+1],vp[i].S+1,mod-1);
    }


    for (auto x: mp){
        int curr = (x.S)*(x.S+1)/2 ;
        int cnt = mult(prd,suff[++j],mod-1);
        prd = mult (prd,x.S+1,mod-1);
        cnt = mult (curr,cnt,mod-1);
        ans = mult (ans,binpow(x.F,cnt,mod),mod);
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}