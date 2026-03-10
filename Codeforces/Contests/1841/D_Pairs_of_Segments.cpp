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
#define INFF (ll)(1e9+5)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}

const ll N = 1e3 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;

vector <pair<int,int>> v ,best;
map<int,int> dp[2002] ; 
int n ; 


int work (int curr , int pos ) {
    if (curr == n ) return 0 ;
    if (dp[curr].count(pos)) return dp[curr][pos];
    if (v[curr].F> pos && best[curr].S!=INFF) dp[curr][pos] = 2  + work ( curr + 1 , max (v[curr].S,best[curr].S));
    dp[curr][pos] = max (dp[curr][pos], work (curr+1 , pos)) ;
    return dp[curr][pos] ; 
}


void solve(){
    cin >> n; 
    v.resize(n);
    best.resize(n);
    for (int i= 0 ;i<2002 ; i++) dp[i].clear(); 
    for( int i= 0 ;i<n ;i++)
        cin >> v[i].F >> v[i].S ; 
    fill( all(best),make_pair(INFF, INFF)) ;
    sort (all(v));
    for (int i= 0 ;i<n ; i++)
        for (int j= i+1 ;j<n ; j++)
            if ( v[j].S < best[i].S && v[j].F <= v[i].S) 
                best[i]= v[j];
    cout << n - work (0,-1) << endl; 
}

int32_t main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
   #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;

}