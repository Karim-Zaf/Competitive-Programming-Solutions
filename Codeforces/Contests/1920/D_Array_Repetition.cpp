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
#define int __int128
#define endl '\n'

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

void Solve() {
    ll n , q , flag = false  ;
    cin >> n >> q ;

    vector<int> v (1,0), nb(1, 0) , sz(1,0) ;

    for (int i= 0 ; i<n ;i++){
        ll one , two ;
        cin >> one >> two ;
        if (flag) continue;
        if (one == 1 ){
            v.pb(two) ;
            sz.pb(nb.back()*sz.back()+1);
            nb.pb(1) ;
            if (sz.back() >= (int)INF )flag = true;
        }else {
            nb[nb.size()-1]*=++two;
            if (nb.back()>=INF)flag =true;
        }
    }
    kar (sz);
    kar (nb);
    kar (v);
    for (int i= 1; i<=q ; i++){
        ll curr ,ans=-1;
        cin >> curr ;
            kar (curr);
        while (curr>=0){
            ll pos = upper_bound(all(sz),curr)-sz.begin()-1;
            kar (pos);

            curr %= sz[pos] ;
//            curr--;
            if (curr<=0){
                ans = v[pos] ;
                break;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);ll Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}