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

const int  N=2e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

vector <int> divisors[N] ;

int mp[N] ;

void Solve() {
    int n , ans = 1 , flag =1;
    cin >> n ;
    vector <int> v(n), diff ;
    map<int,int> occ ;
    set <int> differences , nw ;
    for(auto &x: v) cin >> x ;
    for (auto x: v){
        for (auto y : v){
            differences.insert(abs(x-y));
        }
    }
    kar (differences);
    for (auto x: differences){
        for (int d= 1 ; d*d <=x; d++){
            if (x%d) continue;
            nw.insert(d);
            nw.insert(x/d);
        }
    }
    for (auto x: nw) diff.pb(x);

    for (auto x: v ) {
        occ[x]++;
        if (occ[x] >=n/2) {cout << -1 << endl; return ;}
    }
    kar (diff);
    for (auto i: diff){
        for (auto x: v ) {
            int curr = (x%i+i)%i;
            mp[curr]++;
            if (mp[curr]>=n/2) ans = i;
        }
        for (auto x: v ) mp[(x%i+i)%i]--;
    }
    cout << ans << endl;
}

int32_t main(){
     #ifndef ONLINE_JUDGE
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
     #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}