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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve() {
    int n ;
    cin >> n ;
    vector<int> mp(n+4) , v(n+1);
    for (int i= 1; i<=n ;i++){
        cin >> v[i] ;
        mp[v[i]]= i ;
    }
    int q ;
    cin >> q;
    while(q--){
        int x , l , r;
        cin >> x >> l >> r ;
        if (x==1){
            int prev = -1 , ans= 1 ;
            for (int i= l; i<=r ;i++){
                if (mp[i]>=prev){
                    prev = mp[i];
                    continue;
                }
                prev =mp[i];
                ans ++ ;
            }
            cout << ans << endl;

        }else {
            swap(mp[v[l]],mp[v[r]]);
            swap(v[l],v[r]);
        }
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}