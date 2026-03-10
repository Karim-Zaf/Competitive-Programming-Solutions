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

const ll N =30+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

void solve(){
    int n , k , m ,res = 0 ;
    cin >> n >> k >> m ;
    vector <vector<int>> v(m ) ;
    for (int i= 0 ; i<m;i++){
        int x ; cin>> x ;
        while (x--){
            int u ; cin >> u ;
            v[i].pb(u) ;
        }
    }
    for (int i= 0 ; i<(1<<m); i++){
        vector <int> mp (n+1);
        int cnt = 0 , sum = 0;
        for (int j = 0 ; j<m ;j ++){
            if (i& (1<<j)){
                for (auto x :v[j]){
                    if (!mp[x]) sum ++ ;
                    mp[x]++ ;
                }
                cnt ++ ;
            }
        }
        if (sum<=n-k){
            res= max (res ,cnt) ;
        }
    }
    cout <<res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}