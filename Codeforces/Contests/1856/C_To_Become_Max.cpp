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

const ll N = 2e6+ 5 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18+5;

void solve(){
    int n , k , res =-1;
    cin >> n >> k ;
    vector <int> v(n ) ;
    for (auto &x : v) cin >> x;
    int l = 1 , r = 1e9 ;
    while (l<=r ){
        int  md= l + (r-l)/2 ;
        int ok = 0 ;
        for (int i= 0 ; i<n ;i++){
            vector <int> t(n);
            for (int j= 0 ; j<n ;j++) t[j]= v[j];
            if (t[i]>=md) {ok =1 ;break;}
            int mstaamel = 0 ;
            t[i]= md  ;
            mstaamel =t[i] -v[i];
            if (mstaamel > k) continue;
            for (int j= i ; j<n-1 ;j++){
                t[j+1] = t[j]-1 ;
                if (t[j+1] <= v[j+1]) {ok =1 ; break;}
                mstaamel += (t[j+1]-v[j+1]);
                if (mstaamel > k) break;
            }
        }
        if (ok) {
            l = md + 1;
            res = md;
        }
        else r = md -1 ;
    }
    cout << res << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}