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

const ll N = 1e3 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;
 
ll dp [10][300001], C [300001][10] ; 
vector <ll> mp (300001) , cnt (300001); 


void solve(){ 
    ll n , ans = 0 ;
    cin >> n; 
    vector <ll> v(n) ; 
    memset(dp,0 , sizeof(dp)) ;

    for (auto &x : v ) {
        cin >> x ; 
        mp[x]++ ; 
    }
    for (ll i= 1 ; i<= 300000 ; i++)
        for (ll j = i ; j<= 300000; j+=i)
            cnt[i]+= mp[j] ;

    C[0][0]=1 , C[1][0]=1; 

    for (ll i= 1 ; i<= 300000 ; i++){
        C[i][0]  =  1; 
        if ( i <10 )C[i][i] = 1 ; 
        for (ll j= 1 ; j < 10 && j <=i ; j++){
            C[i][j] = C[i-1][j] + C[i-1][j-1] ; 
        }
    }

    for (ll j= 1 ;j<10 ;j++){
        for (ll i= 300000 ;i>=1;i--){
            dp[j][i]= C[cnt[i]][j] ;
                for (ll k= 2 ; i*k<=300000 ;k++){
                    dp[j][i]-=dp[j][i*k] ;
                }
        }
    }
    for (ll i=1 ; i<10 ; i++){
        if ( dp[i][1] ) {cout << i << endl; return;} 
    }
    cout << -1 << endl;
}

int32_t main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
   #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;

}