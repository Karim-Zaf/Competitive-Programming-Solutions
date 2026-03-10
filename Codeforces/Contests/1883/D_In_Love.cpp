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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+6;


void Solve() {
    int q ;
    cin >> q ;
    multiset <int> l , r ;
    for (int i= 0;i<q ; i++){
        int lef ,righ ;char c ;

        cin >> c>> lef >> righ ;
//
        if ( c=='+'){
            l.insert(lef);
            r.insert(righ);
        }
        else{
            l.erase(l.find(lef));
            r.erase(r.find(righ));
        }
        if (!r.empty()&& *r.begin()< *prev(l.end()))cout << "YES\n";
        else cout << "NO\n";
    }

//    int n ,res = 0 , prev ;
//    cin >> n;
//    vector <int> v(n) ;
//    for (int i= 0 ; i<n ;i++){
//        cin >>v[i] ;
//        int curr = ceil(log2(v[i]));
//        if (!i) {
//            prev = curr ;
//            continue;
//        }
//        res += max (0ll, prev-curr);
//        kar (prev) ;
//        kar (curr);
//        prev = max (curr , prev);
//    }
//    cout << res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}