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

const int  N=1e5+8,MOD=1e9+7,mod=1e9+7,INF=1e17;

void Solve() {
    int n , ans = 1 ;
    cin >> n;
    vector <int> v(n) , pos(n);
    for (int i=0 ;i<n;i++){
        cin >> v[i];
        pos[v[i]]=i ;
    }

    int l = pos[0], r= pos[0] ;
    for (int i= 1;i<n;i++){
        if (l<=pos[i]&& pos[i]<=r){
            ans *= (r-l-i+1);
            ans%=mod ;
        }else {
            l = min (pos[i],l);
            r = max (pos[i],r);
        }
    }
    cout << ans << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while(Test_case--)Solve();
}