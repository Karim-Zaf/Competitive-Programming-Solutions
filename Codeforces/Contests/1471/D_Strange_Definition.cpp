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

const int N=1e6+30,mod=1e9+7,MOD=mod,INF=1e18+10;

map<int,int> mp ;

vector <int> spf (N) ;

void sieve(){
    for (int i=1 ; i< N ; i++ ) spf[i]= i ;
    for  (int i =2 ; i<N ; i++){
        if (spf[i] != i) continue;
        for ( int j= i ; j<N ; j+=i)
            spf[j]=min(spf[i], i);
    }
}

int factors(int n){
    int ret =1 ;
    map<int,int> cnt;
    while ( n > 1 ) {
        cnt[spf[n]]++; ;
        n/= spf[n] ;
    }
    for (auto x: cnt)
        if (x.S%2) ret*=x.F ;

    return ret ;
}

void Solve() {
    int n ,q ;
    cin >> n ;
    mp.clear();
    vector<int> v(n) , ans(2);
    for (auto &x: v){
        cin >> x ;
        int curr = ++mp[factors(x)];
        ans[0]= max (ans[0], curr);
    }
    ans[1]=ans[0];
    for (auto x: mp){
        if (x.S%2|| x.F==1) continue;
        mp[1]+= x.S ;
        ans[1]= max (ans[1],mp[1]);
    }

    cin >> q ;
    while (q--){
        int x ; cin >> x;
        if (x==0 ) cout << ans[0]<<endl ;
        else cout << ans[1] << endl;
    }

}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    sieve();
    cin >> Test_case;
    while (Test_case--) Solve();
}