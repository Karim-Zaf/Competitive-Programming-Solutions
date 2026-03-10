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

const ll N =1e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

void solve(){
    int n ;
    cin >> n;
    vector <int> v ;
    for (int i= 0 ; i<=N ;i++){
        int curr = i*i ;
        int j = sqrtl(i*i -n) ;
        if (i*i -j*j==n &&j>=1) v.pb(i) ;
    }
    cout << v.size() << endl;
    for (int i= 0; i<v.size() ; i++){
        cout << v[i] ;
        if (i!= v.size()-1) cout << " " ;
    }
}
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}