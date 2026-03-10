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
#define ld long double

const ll N =100+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

void solve(){
    map <int,int> mp ;
    int r , c , k ,res =0 ;
    cin >> r >> c >> k ;
    for (int i= 0 ; i< c ; i++){
        int x ; cin >> x;
        mp[x]++ ;
    }
    vector <int> v;
    for (auto x : mp) v.pb(x.S) ;
    sort (rall(v));
    for (int i= 0 ; i< min(k ,(int)(v.size()) ); i++) res += v[i] ;

    cout << res << endl ;
}
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}