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

const int  N=2e3+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;



void Solve() {
    int n, c, left=-1 , right , cnt = 0;
    cin >> n >> c;
    vector<int> v(n+1), pref(3*n+1), dp(4*n+1,0), ans(n+1) , lst(3*n+5,-1);
    for (int i=1 ;i<=n ;i++)cin >> v[i] ;
    for (int i= 0; i<3*n ; i++) pref[i+1]= v[(i%n)+1]+ pref[i];


    function <int(int,int,int&)> get =[&] (int x, int final, int &ekher)->int {
        int &ret = dp[x];
        if (lst[x]!=-1&&lst[x]<final){
            ret += get (lst[x],final,ekher)+1;
            lst[x]= ekher;
            return ret ;
        }
        int pos = lower_bound( all(pref), pref[x]+c) -pref.begin();

        if (pos>= final ){

            ekher = pos;
            lst[x]= ekher ;
            return ret ;
        }
        ret=  1+get (pos,final,ekher);
        lst[x]= ekher;
        return ret ;
    };
    int ekh=9 ;
    for (int i= 0 ; i<= n-1 ; i++){
        ans[i+1]= get(i, i + n, ekh);
    }

    for (int i=1 ; i<=n ; i++) cout << ans[i]<< " " ; cout << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}