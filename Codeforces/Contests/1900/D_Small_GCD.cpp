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

const int  N=1e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int mp[N] , pref[N], ans[N];
vector <int> divi[N] ;

void Solve() {
    int n, res = 0;
    cin >> n;
    vector <int> v(n) ;
    memset (mp,0,sizeof(mp));
    memset (pref,0,sizeof(pref));
    memset (ans,0,sizeof(ans));
    for (int i= 0 ; i<N ; i++) divi[i].clear();
    for (auto &x: v) {
        cin >> x;
        mp[x]++;
        for (int d = 1; d*d <= x; d++){
            if (x%d) continue;
            divi[d].pb(x);
            if (d== x/d) continue;
            divi[x/d].pb(x);
        }
    }
    for (int i= 1 ; i<N ; i++) sort (all(divi[i]));
    for ( int i= 1; i<N ;i++)
        pref[i]= pref[i-1]+ mp[i];
    sort (all(v));
    memset (mp,0,sizeof(mp));
    for (int i= N-1; i>=1; i-- ){
        vector <int> & vect = divi[i];
        for (int j= vect.size()-1 ; j>=0 ; j--){
            int curr= vect[j];
            int kodem = n - pref[curr]+mp[curr];
            ans[i]+= kodem * j ;
            mp[curr]++;
        }

        for (auto d: vect ) mp[d]-- ;
        for (int j= i+i ; j<N ; j+=i){
            ans[i]-=ans[j];
        }
//        cout << i << " " << ans[i] << endl;
        res += i*ans[i];
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