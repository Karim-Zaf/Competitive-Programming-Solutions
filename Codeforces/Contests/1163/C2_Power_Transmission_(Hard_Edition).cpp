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

array <int,4> equation (pair <int,int> a , pair <int,int> b){
    array <int,4> ret ;
    if (a.F == b.F)return {INF,INF,a.F,INF};
    ret[0] = (a.S -b.S)/ __gcd((a.F -b.F),(a.S -b.S));
    ret[1]=(a.F -b.F)/ __gcd((a.F -b.F),(a.S -b.S));
    ret[2] = b.S*ret[1] - ret[0] * b.F ;
    ret[3] = ret[1] ;
    int g = __gcd (ret[2],ret[3]);
    ret[2]/=g ;
    ret[3]/=g;
    if (ret[1]<=0){
        ret[1]*=-1;
        ret[0]*=-1;
    }
    if (ret[3]<=0){
        ret[3]*=-1;
        ret[2]*=-1;
    }
    return ret ;
}


void Solve(){
    int n;
    cin >> n;
    vector<pair <int,int>> vp(n) ;
    map<pair<int,int>,int>mp ;
    set<array<int,4>>s ;
    for (int i= 0 ; i<n;i++) cin >> vp[i].F >> vp[i].S ;
    for (int i= 0;i<n;i++)
        for (int j= 0 ;j<i;j++)
            s.insert(equation(vp[i],vp[j]));

    int sum = 0, res= 0;

    for (auto x :s) {
        mp[{x[0],x[1]}]++;
    }
    for (auto x :s) {
        res+= s.size() - mp[{x[0],x[1]}];
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