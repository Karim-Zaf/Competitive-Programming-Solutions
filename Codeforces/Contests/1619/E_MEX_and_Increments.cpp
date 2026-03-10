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
 #include "debug.h"
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

const int  N=1e5+8,MOD=1e9+7,mod=1e9+7,INF=1e17;


void Solve() {
    int n , cnt = 0 , other =0;
    cin >> n ;
    vector <int> v(n), mp(n+1) ,res(n+1);
    multiset <int> s ;
    for (auto &x: v) {
        cin >> x ;
        mp[x]++;
    }
    for (int i= 0 ; i<= n ; i++){
        if (cnt <i||cnt==-1){
            cnt = -1 ;
            res[i]=-1 ;
            continue;
        }
        res [i]= mp[i]+other;
        for (int j= 1 ;j<mp[i]; j++)s.insert(i);
        cnt += mp[i];
        if (!mp[i]&&!s.empty()){
            int x = *prev(s.end());
            other += i-x ;
            s.erase(s.find(x));
        }
    }
    for (auto x: res) cout << x << " " ; cout << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}