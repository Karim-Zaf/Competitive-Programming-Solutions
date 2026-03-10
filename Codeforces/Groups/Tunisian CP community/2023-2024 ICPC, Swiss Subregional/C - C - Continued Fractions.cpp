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
#define int __int128
#define endl '\n'

const int  N=1e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

using ul = uint64_t;
using db = long double;
ul modMul(ul a, ul b, const ul mod) {
    ll ret = a*b-mod*(ul)((db)a*b/mod);
    return ret+((ret<0)-(ret>=(ll)mod))*mod; }
ul modPow(ul a, ul b, const ul mod) {
    if (b == 0) return 1;
    ul res = modPow(a,b/2,mod); res = modMul(res,res,mod);
    return b&1 ? modMul(res,a,mod) : res;
}

bool prime(ul n) { // not ll!
    if (n < 2 || n % 6 % 4 != 1) return n-2 < 2;
    ul A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n-1), d = n>>s;
    for(auto a : A) {   // ^ count trailing zeroes
        ul p = modPow(a,d,n), i = s;
        while (p != 1 && p != n-1 && a%n && i--) p = modMul(p,p,n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}
ul pollard(ul n) { // return some nontrivial factor of n
    auto f = [n](ul x) { return modMul(x, x, n) + 1; };
    ul x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || __gcd(prd, n) == 1) { /// speedup: don't take gcd every it
        if (x == y) x = ++i, y = f(x);
        if ((q = modMul(prd, max(x,y)-min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
void factor_rec(ul n, map<ul,ll>& cnt) {
    if (n == 1) return;
    if (prime(n)) { ++cnt[n]; return; }
    ul u = pollard(n);
    factor_rec(u,cnt), factor_rec(n/u,cnt);
}

int p ;


void work (vector<pair<int,int>>&vp,vector<int>&ans,int x=1,int pos=0){
    if (pos>=vp.size()){
        int b = x -1 ;
        if (b>=1 && ((b*p+1)%(b+1))==0 && ((b*p+2)%(b+2))==0)ans.pb(b);
        return;
    }
    for (int i= 0 ; i<=vp[pos].S; i++){
        work(vp,ans,x,pos+1);
        x*=vp[pos].F;
    }
}

void Solve() {
    ll a ;
    cin >> a ;
    p = a ;
    map<ul,ll> mp ;
    vector<int> ans ;
    vector<pair<int,int>> vp ;
    factor_rec(p-1,mp);
    for (auto x:mp) vp.pb(x);
    work(vp,ans);
    sort (all(ans));
    cout << ans.size() << endl;
    for (auto x: ans ) cout << (ll)x << " " ; cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);ll Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
