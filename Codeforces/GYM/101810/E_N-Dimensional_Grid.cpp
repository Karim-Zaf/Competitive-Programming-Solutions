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

const ll N = 1e6+ 7 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

#define int ll

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

void solve(){
    ll n , prd = 1 , res = 0 ; 
    cin >> n; 
    vector <ll> v(n);
    for (auto &x: v)  {
        cin >> x; 
        prd *= x ;
        prd %= MOD ;
    }
    for (int i= 0 ;i<n ;i++){
        ll curr = divide(prd,v[i]);
        curr *=  (v[i]-1) ;
        curr %= MOD ;
        res += curr;
        res %= MOD ;
    }

    cout << res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}




// Failure gives you two choices: You stay down or You get up ;)