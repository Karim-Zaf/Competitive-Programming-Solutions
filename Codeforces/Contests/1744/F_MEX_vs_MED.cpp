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

const int  N=1e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+6;


void Solve() {
    int n , ans = 0 ,left = INF , right = -INF ;
    cin >> n;
    vector <int> v(n)  , pos(n) ;
    for (int i= 0 ; i<n ; i++){
        cin >> v[i] ;
        pos[v[i]]= i ;
    }

    auto cnt=[] (int x , int l , int r) -> int{
        if (l+r <x) return 0 ;
        r = min (r, x);
        l = min (l, x);
        return (l+r) - x+1 ;
    };

    for (int i= 0 ; i<n ;i++){
        left = min (left , pos[i]);
        right = max (right , pos[i]);
        if (right -left +1 > 2*(i+1)) continue;
        if (right -left +1 == 2*(i+1)) {ans ++ ;continue;}
        int nb_blasa = 2*(i+1) - (right -left +1) ;
        int rem_lef = left , rem_right = n- right -1 ;
        ans += cnt (nb_blasa-1,rem_lef, rem_right);
        ans += cnt (nb_blasa,rem_lef, rem_right);
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
