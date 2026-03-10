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

const int B = 9973 ;

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

vector<int> pref , fn;
string s ;
int n ;

void build(){
    pref.resize(n+7);
    fn.resize(n+7);
    for (int i=1 ; i<=n ;i++)
        pref[i]=add(pref[i-1], mult(s[i],binpow(B,i)));
}

int query (int l , int r){
    return divide (add(pref[r],-pref[l-1]),binpow(B,l));
}


void Solve() {
    cin >> s ;
    n= s.size() ;
    s='#'+s ;
    build();

    for (int i= 1 ; i<=n ;i++){
        int l = 1 , r= n-i+4 , ans = 0 ;
        while (l<=r){
            int md = l + (r-l)/2 ;
            if (query (i,i+md-1)==query (1,md)) {
                l = md + 1;
                ans = md;
            }else r = md -1 ;
        }
        fn[0]++;
        fn[ans+1] -- ;
    }

    for (int i= 1 ;i<=n ; i++) fn[i]+= fn[i-1] ;

    vector<pair <int,int>> ekh ;

    for (int i= 1 ;i<=n ; i++) {
        if (query(1,i)!=query(n-i+1,n))continue;
        ekh.pb({i,fn[i]});
    }
    cout << ekh.size() << endl;
    for (auto x: ekh) cout << x.F << " " << x.S << endl;


}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}