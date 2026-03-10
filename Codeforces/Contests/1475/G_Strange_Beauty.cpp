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
#define int ll
#define endl '\n'

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

vector<int> divisors[N] ;

int mp[N] ;
void Solve(){
    int n , ans = 0;
    cin >> n ;
    vector <int> v(n), dp(n,1) ;
    for (auto &x:v) cin >> x ;
    sort (all(v));



    for (int i= 0 ; i<n ;i++){
        for (auto d: divisors[v[i]]){
            if (mp[d]) dp[i]= max(dp[i],dp[mp[d]-1]+1);
        }
        mp[v[i]]= i+1 ;
    }
    for (int i= 0 ;i<n ;i++) {
        ans = max (ans , dp[i]);
        mp[v[i]]=0;
    }
    cout << n - ans << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    for (int i= 1; i<N; i++){
        for (int j= i; j<N ; j+=i ){
            divisors[j].pb(i);
        }
    }
    while (Test_case--) Solve();
}