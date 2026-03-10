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

const ll N = 2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 5e18 ;

void solve(){
    int n , m ;
    cin >> n >> m ;
    int t[n][28][2] ;
    for (int i= 0 ; i<n ; i++ ){
        for (int j = 0 ; j<28 ; j++)t[i][j][0]= t[i][j][1]= -1;
        for (int j= 0 ; j<m ;j ++){
            char x ; cin >> x;
            int i_char = x -'a';
            if (t[i][i_char][0]==-1)t[i][i_char][0]=j;
            t[i][i_char][1]= j ;
        }
    }


    int q ;
    cin >> q ;
    while (q--){
        int one , two , res = 0;
        cin >> one >> two ;
        one -- ; two -- ;
        for (int i= 0 ; i<27 ; i++){
            if (t[one][i][0]==-1 ||t[one][i][1]==-1 )continue;
            if (t[one][i][0]> t[two][i][1]|| t[one][i][1]<t[two][i][0]) continue;
            res +=  min (t[one][i][1],t[two][i][1]) - max  (t[one][i][0],t[two][i][0])+1 ;
        }
        cout << res << endl;
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

// Failure gives you two choices: You stay down or You get up ;)