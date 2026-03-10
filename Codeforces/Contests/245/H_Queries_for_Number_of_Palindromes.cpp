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

const ll N = 1e6 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 , INF = 1e18 ;

int q , dp[5001][5001] , palindrome[5001][5001]; 

void solve (){
    string ch ; 
    cin >> ch >> q; 
    int n = ch.size() ;
    
    for (int r = 0 ; r <n ; r++){
        palindrome[r][r]=1 ;
        for (int l= 0 ;l<r;l++){
            palindrome [l][r] =palindrome[l+1][r-1] && ch[l]==ch[r]; 
            if (r-l==1 && ch[l]==ch[r]) palindrome[l][r]=1 ; 
        }
    }
    for (int r = 0 ; r <n ; r++){
        for (int l= r ;l>=0 ;l--){
            if (l<r) dp[l][r]+= dp[l+1][r]+ dp[l][r-1]-dp[l+1][r-1];
            dp[l][r]+= palindrome[l][r];
        }
    }

    for (int i= 0 ;i<q ;i++){
        int l , r ; 
        cin >> l >> r ; 
        l-- ; r-- ;  
        cout << dp[l][r] << endl;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}