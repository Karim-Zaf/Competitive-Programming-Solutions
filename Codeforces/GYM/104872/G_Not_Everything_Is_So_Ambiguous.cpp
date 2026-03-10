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
 
const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;
 
int query (int value ){
    cout << "? " << (ll)value << endl;
    cout.flush() ;
    ll x ;
    cin >> x;
    return x ;
}
 
int pow (int x, int n ){
    int res =1 ;
    for (int i= 0; i<n ;i++) {
        res*= x;
        if (res>1e18|| res<=0) return -INF ;
    }
    return res ;
}
 
 
void Solve(){
	int base=-1 , sz , ans = -1;
    ll z ;
    cin >> z ; sz =z ;
 
    int l = 1 , r = 1e18 ;
    while (l<=r){
        int md= l + (r-l)/2 ;
        int curr= query(md) ;
        if (curr>=sz+1) {
            r= md- 1;
            ans = md;
        }else l=md+1;
    }
    assert(ans!=-1);
 
    l = 2 , r = 2023 ;
    while (l<=r){
        int md = l + (r-l)/2 ;
        int sum =ans + pow (md, sz )*(md -1) ;
        if (sum <1||sum>1e18|| query (sum) >= sz +2 ){
            base = md;
            r = md -1;
        }else l=  md +1;
    }
    assert(base!=-1);
 
    int ans2 = pow (base ,sz) - ans ;
    cout <<"! "<< (ll)ans2 << " " << (ll)base << endl ;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}