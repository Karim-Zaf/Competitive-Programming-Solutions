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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

void Solve() {
    int l =-INF, r=INF ;
    int n ;
    cin >> n ;
    set <int> s ;
    for (int i= 1; i<=n ; i++){
        int one , two ;
        cin >> one >> two ;
        kar (one);
        if (one==3)s.insert (two);
        if (one == 1){
        l = max (l , two  ) ;
        }else if (one ==2)r = min (two , r) ;
    }



    if (l>r)cout <<0 << endl;
    else {
    kar (l) ;
    kar (r);
        int cnt = 0;
        kar (s);
        auto it = s.lower_bound(l) ;
        while (it!=s.end()&& (*it)<=r){
            cnt++;
            it ++ ;
        }
        cout << r-l+1-cnt << endl;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}