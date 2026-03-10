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
 
const int  N=2e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;
 
void Solve(){
    int n , a, b , sum = 0 ;
    cin >> n >> a >> b ;
    vector <int> x(n) , y (n) , vis(n);
    priority_queue<pair<int,int>> pq;
    for (int i= 0 ; i<n ;i++) {
        cin >> x[i];
        sum += x[i] ;
    }for (int i= 0 ; i<n ;i++) {
        cin >> y[i];
        pq.push({-x[i]+y[i],i});
    }
    for (int i= 0;i<b;i++){
        sum += pq.top().F;
        vis[pq.top().S]=1 ;
        pq.pop();
    }
    int cnt = n - b ;
 
    while(cnt >a &&!pq.empty()&&pq.top().F>=0){
        sum += pq.top().F;
        vis[pq.top().S]=1 ;
        pq.pop();
        cnt-- ;
    }
    cout << sum << endl;
    for (int i= 0;i<n;i++){
        cout << (vis[i]?"P":"T") << " ";
    }
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while(Test_case--)Solve();
}