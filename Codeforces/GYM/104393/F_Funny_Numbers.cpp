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

const ll N =1e6+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

vector <int> dp(N ,-1);

int work (int n ){
    if (dp[n]!=-1) return dp[n] ;
    int one = n ;
    string ch = to_string (n) ;
    int res = 0 ;
    for (auto c : ch ) res += (c-'0')*(c-'0');
    n = res ;
    dp[one] = work(n);
    return dp[one] ;
}

void solve(){
    dp[0]=0 ;
    dp[1]=1 ;
    dp[2]=2 ;
    dp[3]=3 ;
    dp[4]=4 ;
    for (int i= 5 ; i< N ;i++)
        if (dp[i] == -1)  work(i);


    int sum = 0 ;
    int a , b ; cin >> a >> b ;
    for (int i= a ; i<= b;i++) sum += dp[i] ;
    cout << sum << endl;
}
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}