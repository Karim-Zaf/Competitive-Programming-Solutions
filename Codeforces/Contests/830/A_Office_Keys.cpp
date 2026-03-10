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

const ll N = 1e8 + 1 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;


long long n , k , idara , dp[1001][2001]; 
vector <long long> pos_p , pos_k ;

long long work ( long long person , long long key ){
    if (k-key+1 < n-person+1) return INF;
    if (person == n || key == k) return 0 ; 
    long long &ret = dp[person][key];
    if (ret != -1 ) return ret ;    
    long long curr = abs (pos_p[person]-pos_k[key]) + abs(pos_k[key] -idara);
    ret = work(person , key+1);
    ret = min ( ret , max( curr , work (person +1 , key+1 ) ));
    return ret ;
}

void solve(){
    cin >> n >> k >> idara ;
    pos_p.resize(n);  
    pos_k.resize(k);
    memset(dp,-1 ,sizeof(dp));
    for (auto &x :pos_p) cin >> x;   
    for (auto &x :pos_k) cin >> x;  
    sort (all(pos_p));
    sort (all(pos_k));
    cout << work(0,0) << endl; 
}

int32_t main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
   #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;

}