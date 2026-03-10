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

const int  N=2e3+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int t[N][N] ;


void Solve() {
    int n;
    cin >> n ;
    vector <int> res (n+1) ;
    for (int i=1 ; i<=n ;i++){
        for (int j= 1; j<= n ; j++){
            cin >> t[i][j] ;
        }
    }
    if (n==1){
        cout << "YES\n" << t[1][1]<< endl;return;
    }
    for (int i = 1;  i<= n; i++){
        for (int bit = 30; bit>=0 ; bit--){
            int ok = 1;
            for (int j= 1 ; j<=n ; j++){
                if (i==j) continue;
                if (!((1ll<<bit)&t[i][j]))ok = 0;
            }
            if (ok) res[i]+= (1ll<<bit) ;
        }
    }
    for (int i= 1; i<= n; i++){
        for (int j=i+1 ; j<=n; j++){
            int curr = res[i]|res[j];
            if (curr!=t[i][j] || curr!=t[j][i]){
                cout << "NO\n";
                return ;
            }
        }
    }
    cout << "YES\n";
    for (int i=1 ; i<= n ;i++)cout << res[i]<< " " ; cout<< endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}