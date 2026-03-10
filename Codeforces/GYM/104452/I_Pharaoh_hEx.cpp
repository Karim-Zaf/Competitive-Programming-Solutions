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
#define int ll
#define ld long double
const ll N =1e7+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;
 
vector <pair <int,int>> factorise (int n ){
    vector <pair<int,int>> vp;
    for (int p = 2 ; p*p <= n; p++){
        if (n%p) continue;
        int cnt = 0 ;
        while (n%p==0){ n/=p;cnt ++ ;}
        vp.pb({p,cnt});
    }if (n>1) vp.pb({n,1});
    return vp;
}
 
void solve(){
    int n ; cin >> n;
    vector <pair <int,int>> vp = factorise(n) ;
    int cmp = 1 ;
    for (auto [prime ,coeff] : vp){
        if (coeff%2==0) continue;
        cmp *= prime;
    }
    int sq = sqrtl(ceil(double(n)/double(cmp))) +1 ;
    cmp *=sq*sq ;
 
    cout << cmp-n << endl;
 
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}