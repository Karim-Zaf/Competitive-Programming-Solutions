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

const ll N =2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

int pref[N], dp[N] ;

void solve() {
    int n ,res = 0 ;
    cin>> n;
    vector <int> v(n);
    for (auto &x: v) cin >> x;
    for (int i= 0; i<n ;i++){
        ll mx = max(0ll,dp[v[i]]);
        for (int j= 1 ; j*j<N ;j++){
            int y = j*j -v[i], x = j*j;
            if (y<=0 || dp[y]<0) continue;
            mx= max (mx, dp[y]-pref[y] +pref[j*j] -pref[v[i]] );
        }
        mx = max (0ll,mx);
        dp[v[i]]=max (dp[v[i]],mx);
        res = max (res , mx);
    }
    cout << res << endl;
    for (int i= 0 ;i<n ; i++) dp[v[i]] = -INF;
}

void preprocess(){
    for (int i= 1; i<N;i++)
        pref[i] = pref[i-1] + (int)sqrt(i);
    for (int i= 0; i<N;i++) dp[i]= -INF ;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    preprocess();
    while (test_case--)  solve() ;
}