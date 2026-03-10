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

const int  N=1e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;


void Solve() {
    int n ;
    cin >> n ;
    vector <int> v(n ) , dist(n-1 ), need(n) , check[2];
    for (int i= 0;i<n;i++){
        cin >> v[i];
        if (i==1) dist[i-1]= v[i]-v[i-1] ;
        if (i>=2)dist[i-1]= (v[i]-v[i-1] -dist[i-2]) ;
        if (i) {
            check[(i+1)%2].pb(dist[i-1]) ;
        }
    }
    kar (dist);
    kar (check[0]);
    for (auto &x: need) cin >> x;
    sort(all(need));

    auto ok =[&] (int x){
        vector <int> nw = dist ;
        for (int i= 0 ;i<n-1 ; i++){
            if (i%2) nw[i] += x ;
            else nw[i] -= x ;
        }
        nw.pb(x);
        sort(all(nw));
        for (int i= 0 ;i<n-1 ; i++)
            if (nw[i]!= need[i])return false ;
        return true ;
    };

    sort(all(check[0]));
    sort(all(check[1]));
    int x = check[0].back()-need.back();
    if (ok(need.back())){
        x = need.back();
        cout << x << " " ;
        for (int i= 0 ;i<n-1 ; i++){
            if (i%2) cout << dist[i] + x << " " ;
            else cout <<  dist[i] - x << " " ;
        }
        return ;
    }
    if (ok(x)){
        cout << x << " " ;
        for (int i= 0 ;i<n-1 ; i++){
            if (i%2) cout << dist[i] + x << " " ;
            else cout <<  dist[i] - x << " " ;
        }
        return ;
    }
    x = need.back()- check[1].back() ;
    kar (need);
    kar (x);
    cout << x << " " ;
    for (int i= 0 ;i<n-1 ; i++){
        if (i%2) cout << dist[i] + x << " " ;
        else cout <<  dist[i] - x << " " ;
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