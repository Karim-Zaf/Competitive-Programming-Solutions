/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
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
#define endl '\n'
#define int long long
 
const long long N=505+8,MOD=1e9+7,mod=1e9+7,INF=1e18;

char t[N][N] , res [N][N];
vector <int> ver(N), hor(N) , cnt_ver(N) , cnt_hor(N);

void Solve() {
    int n , m ;
    cin >> n >> m ;
    for (int i= 1 ; i<= n;i++)hor[i]=0;
    for (int i= 1 ; i<= m;i++)ver[i]=0;
    for (int i= 1; i<=n;i++) {
        for (int j = 1; j <= m; j++) {
            cin >> t[i][j];
            res[i][j]='.';
        }
    }
    for (int i= 1 ; i<=n ; i++){
        for (int j= 1; j<=m ; j++)
            hor[i] += (t[i][j]=='U'||t[i][j]=='D');
        if (hor[i]%2) {cout << -1 << endl; return;}
    }
    for (int j= 1; j<=m ; j++){
        for (int i= 1 ; i<=n ; i++)
            ver[j] += (t[i][j]=='L'||t[i][j]=='R');
        if (ver[j]%2) {cout << -1 << endl; return;}
    }
    for (int i= 1 ; i<=n ; i++){
        int cnt = 0 ;
        for (int j= 1; j<=m ; j++)
            if (t[i][j]=='U'){
                if (cnt>=hor[i]/2)res[i][j]='W';
                else res[i][j]='B';
                if (t[i][j]=='U' && res[i][j]=='B')res[i+1][j]='W';
                if (t[i][j]=='U' && res[i][j]=='W')res[i+1][j]='B';
                if (t[i][j]=='U')hor[i+1]--;
                cnt++;
            }
    }
    for (int j= 1; j<=m ; j++){
        int cnt = 0 ;
        for (int i= 1 ; i<=n ; i++)
            if (t[i][j]=='L'){
                if (cnt>=ver[j]/2)res[i][j]='W';
                else res[i][j]='B';
                if (t[i][j]=='L' && res[i][j]=='B')res[i][j+1]='W';
                if (t[i][j]=='L' && res[i][j]=='W')res[i][j+1]='B';
                if (t[i][j]=='L')ver[j+1]--;
                cnt++;
            }
    }
    for (int i= 1; i<=n;i++) {
        for (int j = 1; j <= m; j++)
            cout <<res[i][j];
        cout << endl;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}