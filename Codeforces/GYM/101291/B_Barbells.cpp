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
 
const ll N =100+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;
 
void solve(){
    int n , m ;
    cin >> n >> m ;
    vector <int> a(n ) , b(m) ;
    vector <pair <int,int>> vp ;
    for (int i= 0 ; i<n;i++) cin >> a[i];
    for (int i= 0 ; i<m;i++) cin >> b[i];
    for (int i= 0 ;i<(1<<m); i++)
        for (int j= 0 ; j<=i ; j++)
            if ((i&j)==0) vp.pb({i, j});
    set<int> s , ans ;
    for (auto [one , two] : vp){
        int cnt1 = 0 , cnt2= 0;
        for (int i=0 ; i<m ;i++)if (one & (1<<i)) cnt1 += b[i] ;
        for (int i=0 ; i<m ;i++)if (two & (1<<i)) cnt2 += b[i] ;
        if (cnt1==cnt2) s.insert(2*cnt1);
    }
    for (int i= 0 ; i<n; i++){
        for (auto x : s)
            ans .insert(a[i]+x ) ;
    }
    for (auto x : ans ) cout << x << endl ;
}
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}