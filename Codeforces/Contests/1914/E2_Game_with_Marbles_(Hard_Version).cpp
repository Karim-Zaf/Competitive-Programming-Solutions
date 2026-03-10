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

const int  N=3e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;



void Solve() {
    int n, curr =0,ans = 0;
    cin >> n ;
    vector <int> a(n) , b(n),p;
    multiset<int,greater<>> one;
    multiset <array<int,3>,greater<>> nw ;
    for (int i=0 ; i<n ; i++) cin >> a[i];
    for (int i=0 ; i<n ; i++) cin >> b[i];
    for (int i=0 ; i<n ; i++) {
        nw.insert({a[i]+b[i],a[i],b[i]});
    }
    kar (nw);
    for (auto x : nw){
        if (curr==0){
            ans += x[1]-1;
        }else{
            ans -= x[2]-1;
        }
        curr^=1;
    }

    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}