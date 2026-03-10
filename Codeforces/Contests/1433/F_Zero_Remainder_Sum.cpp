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

const ll N = 1e7 + 5 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;


int t[75][75] , dp[75][75][75][75] , dppp[75][75];

void solve() {

    int n , m , k ,res = 0 ; 
    cin >> n >> m >> k ;

    memset(dp,0,sizeof(dp));
    memset(dppp,0,sizeof(dppp));

    for (int i= 0 ;i<n ;i++)
        for (int j = 0 ;j < m ; j++){
            cin >> t[i][j]; 
            dp[1][i][j][t[i][j]%k] = max(dp[1][i][j][t[i][j]%k],t[i][j]) ;
        }

    for (int i=0 ;i<n ;i++)
        for (int r= 0 ; r<k ;r++)
            for (int j= 1 ; j<m ;j++)
                dp[1][i][j][r]= max (dp[1][i][j][r],dp[1][i][j-1][r]);
    
    

    for (int i = 0 ; i<n ;i++)
        for (int kk = 2 ; kk<=m/2 ;kk++)
            for (int j= 0 ;j<m ; j++)
                for (int r = 0 ; r < k ; r++){
                    if(j) dp[kk][i][j][r]= max (dp[kk][i][j-1][r],dp[kk][i][j][r]);
                    dp[kk][i][j][r]= max (dp[kk-1][i][j][r],dp[kk][i][j][r]);
                    if ((dp[kk-1][i][j-1][(r-t[i][j]%k+k)%k]+t[i][j])%k==r && j )
                        dp[kk][i][j][r]= max (dp[kk][i][j][r],dp[kk-1][i][j-1][(r-t[i][j]%k+k)%k]+t[i][j]);
                }

    for (int j = 0 ; j< k ; j++) dppp[0][j]=dp[m/2][0][m-1][j];

    for (int ii = 1 ;ii< n ; ii++)
        for (int r = 0 ;r<k ;r++){
            dppp[ii][r]=dp[m/2][ii][m-1][r] ;
            for (int rem = 0 ; rem < k ; rem++){
                if ((dp[m/2][ii][m-1][rem]+ dppp[ii-1][(r-rem+k)%k])%k == r)
                    dppp[ii][r]= max (dppp[ii][r] , dp[m/2][ii][m-1][rem]+ dppp[ii-1][(r-rem+k)%k]);
            }
        }
    cout << dppp[--n][0] <<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}