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
#define endl '\n'
#define int ll
 
 
const long long N=2e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;
 
 
pair<int,int> equation (pair <int,int> a , pair <int,int> b){
pair<int,int> ret ;
    if (a.F == b.F)return {INF,INF};
    ret.F = (a.S -b.S)/ __gcd((a.F -b.F),(a.S -b.S));
    ret.S=(a.F -b.F)/ __gcd((a.F -b.F),(a.S -b.S));
    if (ret.S<=0){
        ret.S*=-1;
        ret.F*=-1;
    }
    return ret ;
}
 
int dist(pair <int,int> a , pair <int,int>b){
    return (a.F -b.F)*(a.F -b.F)+(a.S -b.S)*(a.S -b.S);
}
 
void Solve(){
    int n , res = 0; cin >> n ;
    vector <pair <int,int>> vp (n) ;
    map<array<int,3>,int> mp;
    for (int i= 0 ; i<n; i++) cin >> vp[i].F >> vp[i].S ;
    for (int i= 0 ;i<n ;i++){
        for (int j= 0 ;j<i ;j++){
            pair <int,int> p=equation(vp[i],vp[j]);
            mp[{p.F,p.S,dist(vp[i],vp[j])}]++;
        }
    }
    for (auto x: mp){
        res+= x.S*(x.S-1)/2;
    }
    cout << res/2 << endl;
}
 
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}