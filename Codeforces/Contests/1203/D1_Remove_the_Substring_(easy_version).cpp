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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve() {
    string a, b ;
    cin >> a >> b ;
    int n = a.size() ;
    map <char , vector<int>> mp ;
    set <int,greater<>> st ;

    for (int i= 0 ; i<n ;i++)mp[a[i]].pb(i);

    int curr = -1 ;
    for (auto c: b ){
        int pos = upper_bound(all(mp[c]),curr)- mp[c].begin();
        curr =mp[c][pos];
        st.insert(curr) ;
    }
    kar (st);
    int ans =*prev(st.end()) ;
    ans = max (ans ,n - *st.begin()-1);
    curr = INF ;
    for (int i= b.size()-1 ; i>=0 ; i--){
        st.erase(*st.begin());
        int pos  = lower_bound(all(mp[b[i]]),curr)- mp[b[i]].begin();
        curr = mp[b[i]][--pos];
        int other = -1 ;
        if (st.size())other = *st.begin() ;
        ans = max (ans , curr-other-1) ;
    }

    cout << ans << endl;
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}