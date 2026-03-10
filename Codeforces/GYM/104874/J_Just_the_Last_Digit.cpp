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

const int N=5e2+30,mod=1e9+7,MOD=mod,INF=1e18+10;

int t[N][N] , n, graph[N][N], ans[N][N];

void update ( int Node, int child ){
    vector<int> nw (n+3) ;

    for (int i = 1; i<=n ;i++){
        ans[Node][i]+=ans[child][i] ;
        ans[Node][i]%= 10 ;
    }

}

void Solve() {
    cin >> n ;
    for (int i= 1; i<=n ;i++ )
        for (int j= 1; j<=n ;j++){
            char c ; cin >> c ;
            t[i][j] =c-'0' ;
        }

    for (int Node= n ; Node>=1 ; Node--){
        for (int j= Node+1 ; j<=n ;j++){
            if (ans[Node][j]==t[Node][j])continue;
            graph[Node][j]=1 ;
            ans[Node][j]++;
            ans[Node][j]%=10;
            update(Node,j);
        }
    }

    for (int i= 1; i<=n ;i++){
        for (int j= 1; j<=n ;j++)
            cout << graph[i][j] ;
        cout << endl;
    }

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}