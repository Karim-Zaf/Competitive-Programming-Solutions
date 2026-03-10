/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
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
#define endl '\n'
#define int ll

const ll N = 1e6+ 5 ,  MOD =1e9+7, mod=1e9 +7, INF = 1e18+5;

void solve(){
    int n ;
    cin >> n;
    vector <int> a(n) , b(n) ;
    vector <pair <int,int>> v(n) ;
    for (auto &x: a) cin >> x ;
    for (auto &x: b) cin >> x ;
    for (int i= 1; i<= n ;i++) v[i-1]= {a[i-1]-b[i-1],i};
    sort (rall(v));
    int akber = v[0].F ;
    vector <int> res  ;
    for (int i= 0 ; i<n ;i++){
        if (v[i].F == akber) res.pb(v[i].S);
    }
    cout << res .size()<< endl; ;
    sort (all(res));
    for (auto x: res) cout << x << " " ; cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}