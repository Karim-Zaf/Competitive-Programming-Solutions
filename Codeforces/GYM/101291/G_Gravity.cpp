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

const ll N =2e6+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

void solve(){
    int n , m ;
    cin >> n >> m ;
    char t[n][m] ;
    for (int i= 0 ; i<n;i++)
        for (int j= 0 ; j<m ;j ++)
            cin >> t[i][j] ;
    for (int k = 0 ; k<200; k++)
        for (int j= 0 ; j<m ;j ++){
            for (int i= 1 ; i<n ;i++){
                if (t[i][j]=='.' && t[i-1][j]=='o')
                    swap (t[i][j],t[i-1][j]);
            }
        }
    for (int i= 0 ; i<n;i++) {
        for (int j = 0; j < m; j++)
            cout <<  t[i][j];
        cout << endl;
    }
}
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}