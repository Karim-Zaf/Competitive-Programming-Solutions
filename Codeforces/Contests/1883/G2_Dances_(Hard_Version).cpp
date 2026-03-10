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
    int n ,m, res = 0;
    cin >> n >>m;
    vector <int> a (n-1),b(n) ;
    for (auto &x: a) cin>> x ;
    for (auto &x: b) cin>> x ;
    vector <int> nw_a = a;
    a.pb(1); sort (all(a)); sort (all(b));

    for (int i=n-1, pt= n-1; i>=0 ;i--)
        if (a[i]>=b[pt])res++;
        else pt--;
    int l = 1, r = m , ans =- 1;
    while (l<=r){
        int md = l + (r-l)/2 ;
        a=nw_a ;
        a.pb(md);
        sort(all(a));
        int cnt = 0;
        for (int i=n-1, pt= n-1; i>=0 ;i--)
            if (a[i]>=b[pt])cnt++;
            else pt--;
        if (cnt>res){
            r = md -1 ;
            ans = md ;
        }else l = md +1 ;
    }
    if (ans != -1 )  cout << res * m + m-ans+1 << endl;
    else cout << res *m << endl;

}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}