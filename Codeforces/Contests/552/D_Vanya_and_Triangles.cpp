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
#define int long long
#define ld long double
const long long N=2e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;

__int128 equation (pair <int,int> a , pair <int,int> b){
    array <int,4> ret ;
    if (a.F == b.F)return -a.F;
    ret[0] = (a.S -b.S)/ __gcd((a.F -b.F),(a.S -b.S));
    ret[1]=(a.F -b.F)/ __gcd((a.F -b.F),(a.S -b.S));
    ret[2] = b.S*ret[1] - ret[0] * b.F ;
    ret[3] = ret[1] ;
    int g = __gcd (ret[2],ret[3]);
    ret[2]/=g ;
    ret[3]/=g;
    __int128 res = 0 , fl =1, cst =10000;
    if (ret[0]<=0) res+= abs(ret[0])*fl;
    fl*=cst ;
    if (ret[0]>0) res+= abs(ret[0])*fl;
    fl*=cst ;
    if (ret[1]<=0) res+= abs(ret[1])*fl;
    fl*=cst ;
    if (ret[1]>0) res+= abs(ret[1])*fl;
    fl*=cst ;
    if (ret[2]<=0) res+= abs(ret[2])*fl;
    fl*=cst ;
    if (ret[2]>0) res+= abs(ret[2])*fl;
    fl*=cst ;
    if (ret[3]<=0) res+= abs(ret[3])*fl;
    fl*=cst ;
    if (ret[3]>0) res+= abs(ret[3])*fl;
    return res;
}

void Solve() {
    int n , res = 0 ;
    cin >> n ;
    vector <pair <int,int>> v (n) ;
    map<__int128,set<int>>mp ;
    for (int i= 0 ;i<n ; i++)cin >> v[i].F >> v[i].S ;
    for (int i= 0 ; i<n;i++){
        for (int j= 0 ; j<i ; j++){
            mp[equation(v[i],v[j])].insert(i) ;
            mp[equation(v[i],v[j])].insert(j) ;
        }
    }
    auto cnt =[&](int n )->int{
        return n*(n-1)*(n-2)/6;
    };
    for (auto &x: mp) {
        res += (x.S.size()*(x.S.size()-1)/2)*(n - x.S.size());
    }
    cout << res/3 << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}