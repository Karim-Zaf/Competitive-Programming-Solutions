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
    int n , res= 0 , cnt= 1; cin >> n ;
    vector <int> v(n+1),suff(n+5) , indexes;
    for (int i= 1; i<= n ; i++) cin >> v[i] ;
    for (int i= n ; i>=1 ; i--){
        suff[i]= v[i] + suff[i+1];
        if (suff[i]>=0&&i>=2)indexes.pb(i);
    }
    reverse(all(indexes));
    res= suff[1];
    for (auto i : indexes){
        res+= suff[i] ;
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