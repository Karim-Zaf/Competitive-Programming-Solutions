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
 
const ll N = 1e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18 ;
void solve(){
    int n,m , diff =INF ;
    cin >> n >> m ;
    int t[n+2][m+2] ;
    int pref[4][n+2][m+2];
 
    for (int i= 1;i<=n ;i++)
        for (int j= 1 ; j<=m ;j++)
            cin >> t[i][j];
    for (int k = 0 ; k<4 ;k++)
        for (int i= 0;i<=n+1 ;i++)
            for (int j= 0 ; j<=m+1 ;j++)
                pref[k][i][j]= 0;
    for (int i= 1;i<=n ;i++)
        for (int j= 1 ; j<=m ;j++){
            pref[0][i][j]  = max (t[i][j],pref[0][i-1][j]);
            pref[0][i][j]  = max (pref[0][i][j],pref[0][i][j-1]);
        }
 
    for (int i= 1;i<=n ;i++)
        for (int j= m ; j>=1 ;j--){
            pref[1][i][j] = max (t[i][j],pref[1][i-1][j]);
            pref[1][i][j] = max (pref[1][i][j],pref[1][i][j+1]);
        }
    for (int i= n;i>=1 ;i--)
        for (int j= 1 ; j<=m ;j++){
            pref[2][i][j] = max (t[i][j],pref[2][i+1][j]);
            pref[2][i][j] = max (pref[2][i][j],pref[2][i][j-1]);
        }
    for (int i= n;i>=1 ;i--)
        for (int j= m ; j>=1 ;j--){
            pref[3][i][j] = max (t[i][j],pref[3][i+1][j]);
            pref[3][i][j] = max (pref[3][i][j],pref[3][i][j+1]);
        }
    for (int i = 2 ; i<n ;i++){
        for (int j= 2 ;j<m ;j++){
            int mx = max ({pref[0][i-1][j-1],pref[1][i-1][j+1],pref[2][i+1][j-1],pref[3][i+1][j+1]});
            int mn = min ({pref[0][i-1][j-1],pref[1][i-1][j+1],pref[2][i+1][j-1],pref[3][i+1][j+1]});
            diff = min (diff , mx-mn);
        }
    }
    cout <<diff << endl;
}
 
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}
 
// Failure gives you two choices: You stay down or You get up ;)