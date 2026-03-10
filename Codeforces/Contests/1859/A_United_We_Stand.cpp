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

const ll N =2e5+ 8 ,  MOD =1e9+7 , mod=1e9+7 , INF = 1e18;

void solve(){
    int n ;
    cin >> n ;
    vector <int> v(n) ;
    map <int,int > cnt  ;
    int mn = INF ;
    for (auto &x :v) {
        cin >> x;
        cnt [x]++ ;
        mn = min (mn , x ) ;
    }
    if (cnt[mn]==n) {cout << -1 << endl; return ;} ;

    cout << cnt[mn] <<  " " << n - cnt[mn]<< endl; ;
    for (int i= 0 ;i<cnt[mn] ; i++) cout << mn << " " ; cout << endl;
    for (int i= 0 ;i<n ; i++) if (v[i]!=mn) cout << v[i] << " " ; cout << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}