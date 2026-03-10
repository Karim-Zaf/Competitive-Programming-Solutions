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
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define non cout<<"-1\n";
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}
 
const ll N = 1e6 + 1 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;
 
 
void solve(){
    int x ,y , z ; 
    cin >> x >> y >> z ;
    int nw_x = (x>=500? x-100 : x); 
    int nw_y = (y>=500? y-100 : y); 
    int nw_z = (z>=500? z-100 : z); 
    int res = nw_x + nw_y + nw_z ;
    int a = (x+y >=500 ? x+y-100: x+y);
    res = min (res , a+ nw_z );
    a = (x+z >=500 ? x+z-100: x+z);
    res = min (res , a+ nw_y );
    a = (y+z >=500 ? y+z-100: y+z);
    res = min (res , a+ nw_x );
    a = (x+y+z >=500 ? x+y+z -100 : x+y+z);
    res = min (res , a ) ;
    cout << res << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}