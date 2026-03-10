/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
 
const ll N = 1.5e7 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;
 
vector <int>  occ(N), vis (N); 

void solve(){ 
    int n , res = 1e9 , g , x  ; 
    cin >> n; 
    for (int i= 0 ;i<n ;i++ ) {
        cin >> x; 
        occ [x]++; 
        if ( g ==-1 )g = x;
        g= __gcd (g,x);
    }  

    for (int i= g+1 ; i<N ; i++ ){
        if ( vis[i] ) continue;
        int curr = 0 ; 
        for (int j= i ; j<N  ; j+= i){
            curr+= occ[j];
            vis[j]= 1 ;
        }
        res = min (n-curr,res);
    }
     
    cout << (res == n ? -1 : res ) << endl;

}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}