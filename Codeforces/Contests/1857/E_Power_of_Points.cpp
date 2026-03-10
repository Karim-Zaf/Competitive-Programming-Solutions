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
    vector <int > v(n ) , ans(n);
    vector <pair <int,int>> vp(n ) ;
    for (int i= 0 ; i<n ;i++){
        cin >> v[i] ;
        vp[i]= {v[i], i};
    }
    sort (all(vp));
    for (int j= 0 ; j<n ;j++)
        ans[vp[0].S] += vp[j].F -vp[0].F+1 ;
    for (int j= 1 ; j<n ;j++ ){
        int kodemek = n- j ;
        int wrak = j ;
        int curr =vp[j].S, prec = vp[j-1].S ;
        ans[curr]= ans[prec] ;
        ans [curr]-= (v[curr] - v[prec])*kodemek ;
        ans [curr]+= (v[curr] - v[prec]) *wrak ;
    }
    for (int j= 0 ; j<n ;j++) cout << ans[j] << " " ; cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}