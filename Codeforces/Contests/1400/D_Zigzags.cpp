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

const int  N=3e3+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int pref[2][N][N] ;

void Solve() {
    int n , res= 0;
    cin >> n;
    vector<int> v(n+1);
    for (int i= 1; i<=n; i++){
        cin>> v[i];
        pref[0][v[i]][i]=++pref[1][v[i]][i];
    }
    for (int i=1 ; i<=n; i++){
        if (pref[1][v[i]][0]) continue;
        for (int j= 1 ;j<=n; j++) pref[0][v[i]][j]+= pref[0][v[i]][j-1];
        for (int j=n ; j>=0 ; j--) pref[1][v[i]][j]+= pref[1][v[i]][j+1];
    }

    for (int i= 1 ; i<=n ; i++)
        for (int j=i+1 ; j<=n; j++)
            res += pref[0][v[j]][i-1]* pref[1][v[i]][j+1] ;


    cout << res << endl;

    for (int i= 1 ;i<=n  ;i++)
        for (int j= 0; j<= n+5 ;j++)
            pref[0][v[i]][j]=pref[1][v[i]][j] = 0;

}


int32_t main(){
     #ifndef ONLINE_JUDGE
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
     #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}