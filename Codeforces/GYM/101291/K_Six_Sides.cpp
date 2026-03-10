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

const ll N =2e6+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;


void solve(){
    vector <int> mpa(7),mpb(7);
    ld res = 0;
    for (int i= 0 ; i<6 ; i++) { int x ; cin>> x ; mpa[x]++;}
    for (int i= 0 ; i<6 ; i++) { int x ; cin>> x ; mpb[x]++;}
    for (int i= 1 ; i<=6 ; i++)
        for (int j= 1 ; j<i ; j++)
            res += ((ld)(mpa[i])/(ld)(6))*((ld)(mpb[j])/(ld)(6));
    ld  ans = res ;
    for (int i= 10000 ; i>=0 ; i--){
        ld nw = 0 ;
        for (int a  = 1 ; a<=6 ; a++) {
            nw += ((ld)(mpa[a]) / (ld) (6)) * ((ld) (mpb[a]) / (ld) (6));
        }
        ans *= nw ;
        res += ans ;
    }
    cout << fixed <<  setprecision(5)  << res << endl;

}
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}