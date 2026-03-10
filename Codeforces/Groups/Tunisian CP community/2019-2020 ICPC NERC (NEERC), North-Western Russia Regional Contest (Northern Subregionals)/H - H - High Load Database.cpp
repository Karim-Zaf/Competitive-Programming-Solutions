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

const int N=1e6+30,mod=1e9+7,MOD=mod,INF=1e18+10;

int ans[N] ;

void Solve() {
    int n ;
    cin >> n ;

    set<int> s ;
    vector<int> v(n+1) , pref(n+1),qu , ss ;
    for (int i= 1; i<=n ;i++){
        cin >> v[i] ;
        pref[i]+= pref[i-1]+ v[i] ;
    }

    int q ; cin >> q;
    while(q--){
        int x ; cin>> x;
        qu.pb(x);
        s.insert(x);
    }
    for (auto x: s )ss.pb(x);

    int mx = *max_element(all(v));
    for (auto x :ss){
        int i= 0 ;
        if (x<mx) continue;
        while (i<n ){
            ans[x] ++;
            i = upper_bound(all(pref) , pref[i]+x) -pref.begin()-1;
        }
    }


    for (auto x: qu)
        if (x>=mx)cout << ans[x] << endl;
        else cout << "Impossible\n";
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}