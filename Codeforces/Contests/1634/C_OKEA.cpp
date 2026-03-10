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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

void Solve() {
    int n , m ;
    cin >> n >> m ;
    int impaires  = (n* m+1)/2 ;
    int paires = n* m - impaires;
    if (impaires % m || paires %m )  {cout << "NO\n"; return;}
    int cnt= 0;
    cout << "YES\n";
    for (int i= 1; i<=n*m; i+=2 ){
        cout << i << " " ;
        cnt ++;
        if (cnt % (m)==0) cout << endl;
    }

    for (int i= 2; i<=n*m; i+=2 ){
        cout << i << " " ;
    cnt ++;
        if (cnt % (m)==0) cout << endl;
    }
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