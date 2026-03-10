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

void solve (){
    int n , res = 0 ; cin >>n ;
    int t[n][n];
    vector <int >right(n) , left(n), pref(n) ;
    for (int i= 0 ;i<n ;i++)
        for (int j= 0 ;j<n ;j++){
            char x ; cin >> x ;
            t[i][j]=x-'0' ;
        }
    for (int i= 0 ;i<n ;i++) {
        for (int j= 0; j<n-1;j++)left[j]=left[j+1];
        for (int j= n-1 ; j>=1 ;j--)right[j]= right[j-1] ;
        left[n-1]=right[0]=0 ;
        for (int j= 0  ; j<n ;j++) pref[j]+=right[j]+ left[j];
        for (int j = 0; j < n; j++) {
            if (t[i][j]^(pref[j]%2)==1){
                right[j]++ ;
                left[j]++ ;
                pref[j]++ ;
                res ++ ;
            }
        }
    }
    cout << res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}