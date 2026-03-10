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

const ll N =2e5+ 8 ,  MOD =1e9+7 , mod=1e9+7 , INF = 1e18;

void solve(){
    int n ;
    cin >> n ;
    vector< vector<int >> v ;
    int mn = INF ;
    for (int i= 0 ; i<n;i++){
        vector <int> curr ;
        int m ;
        cin >> m ;
        for (int j= 0 ;j<m ;j++){
            int x ;
            cin >> x;
            curr .pb(x) ;
            mn = min (mn , x) ;
        }
        sort (all(curr));
        v.pb(curr) ;
    }
    int sum = 0 , mn1 = INF , mn2 = INF;
    for (int i= 0;i<n; i++) {
        sum += v[i][1];
        mn1 = min (mn1 , v[i][0]) ;
        mn2 = min (mn2 , v[i][1]) ;
    }
    cout << sum - mn2 + mn1 << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}