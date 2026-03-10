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

const int  N=2e5+8,MOD=1e9+7,mod=1e9+7,INF=1e17;


void Solve() {
    int n,p;
    cin >> n >>  p  ;
    vector <array <int,3>> v(n) ;
    set <int> s ;
    for (int i= 0;i<n;i++){
        cin >> v[i][1] ;
        v[i][2]=i ;
        s.insert(i) ;
    }
    for (int i= 0;i<n;i++)cin >> v[i][0] ;
    sort (all(v));
    if (p <= v[0][0]){cout << n*p << endl; return ;}
    int j= 0 , res = p ;
    s.erase(v[0][2]);
    kar (s);
    while (!s.empty()){
        auto  [cost,nb , curr ]= v[j];
        int nw = nb ;
        while (!s.empty() && nw){
            s.erase (*s.begin());
            res += min(p,cost) ;
            nw--;
        }
        j++ ;
    }
    cout << res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}