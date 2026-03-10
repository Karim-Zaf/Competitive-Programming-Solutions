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
 
const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10, lg = 32;
 
 
void Solve(){
    int n ,m ,y1 ,  y2;
    cin >> n >> y1 ;
    vector <int> a (n),b;
    for (auto &x:a)  cin >> x ;
    cin >> m >> y2 ;
    b.resize(m);
    for (auto &x:b)  cin >> x ;
    int res = 2 ;
 
    for (int j= 1 ;j<lg ; j++){
        map <int,int> aa , bb ;
        for (int i= 0 ;i<n ;i++) aa[a[i]%(1<<j)]++ ;
        for (int i= 0 ; i<m ; i++) bb[b[i]%(1<<j)]++;
        for (int i= 0 ;i<n ;i++) res = max (res , aa[a[i]%(1ll<<j)]+ bb[(a[i]+ (1ll<<(j-1)))%(1ll<<j)]);
        for (int i= 0 ;i<m ;i++) res = max (res , bb[b[i]%(1ll<<j)]+ aa[(b[i]+ (1ll<<(j-1)))%(1ll<<j)]);
 
    }
    cout << res << endl;
 
}
 
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}