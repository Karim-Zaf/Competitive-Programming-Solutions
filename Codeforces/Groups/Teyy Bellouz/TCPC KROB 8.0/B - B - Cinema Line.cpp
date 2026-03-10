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
#define pi pair<long long,long long>
#define vi vector<long long>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define non cout<<"-1\n";
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}

const ll N = 2e5+5 , MOD =1e9+7, mod=1e9+7, Q =2e5+3 ;



void solve (){
    int n , ok = 1; 
    cin >> n; 
    vi v(n) ,mp (102,0);
    for (int i = 0 ;i<n ;i++ ) cin >> v[i];
    for (int i = 0 ;i<n ;i++ ) {
        if (v[i]==50 && !mp[25]) ok = 0 ;
        if (v[i]==50 && mp[25]) mp[25]-- ;
        if (v[i]==100 && mp[50] && mp[25]) {mp[50]--; mp[25]--;} 
        else if (v[i]==100 && mp[25]>=3 ) mp[25]-=3 ; 
        else if (v[i]==100) ok = 0 ;
        mp[v[i]]++;
    }
    if (ok ) {yes }
    else {no}
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}