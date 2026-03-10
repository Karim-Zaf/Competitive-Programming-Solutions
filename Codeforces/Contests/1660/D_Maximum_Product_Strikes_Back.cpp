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

const int  N=1e8+30,MOD=1e9+7,mod=1e9+7,INF=1e18+6;
void Solve() {
    int n, mx= 0 ;
    cin >> n ;
    vector< int > v(n+1)  , neg(n+1),pref(n+1), pos;
    set <array <int,3>> sa ;
    pos.pb(0);
    for (int i= 1 ; i<=n ;i++){
        cin >> v[i] ;
        pref[i]= pref[i-1]+ (abs(v[i])==2);
        neg[i]= neg[i-1]+ (v[i]<0) ;
        if(v[i]==0) pos.pb(i) ;
    }
    pos.pb(n+1);
    for (int i=1 ; i<pos.size() ; i++){
        int l= pos[i-1] , r= pos[i] ;
        set <int> s[2] ;
        s[neg[l]%2].insert(l) ;
        for (int j =l+1 ; j<=r-1 ; j++){
            if (!s[neg[j]%2].empty()){
                int other = *s[neg[j]%2].begin()  ;
                sa.insert({pref[j] - pref[other], other , n-j});
            }
            s[neg[j]%2].insert(j);
        }
    }
    kar (sa);
    if (!sa.empty()) {
        array<int,3> it = *prev(sa.end());
        cout << it[1]<<  " " << it[2] << endl;
    }
    else cout <<0 <<  " " << n << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
