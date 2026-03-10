/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
 
const int N=3e5+30,mod=998244353,MOD=mod,INF=1e18+10;
 
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
 
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/
int fact[N]={1} ;
 
int comb (int n ,int k ){
    if (k>n) return 0 ;
    return divide (fact[n], mult (fact[k],fact[n-k]));
}
 
void Solve() {
    int n ,k, ans = 0, id = 0;
    cin >> n >> k;
    for (int i= 1; i<N ;i++) fact[i]=fact[i-1]*i%mod ;
    vector<pair<int,int>> vp (n) ;
    for (auto &x: vp) cin >> x.F >>x.S;
 
 
    sort (all(vp));
    indexed_set s ;
    for (auto [l,r] : vp ){
        int curr = s.size() - s.order_of_key({l,-INF});
        ans = add (ans,comb(curr,k-1));
        s.insert({r,++id});
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