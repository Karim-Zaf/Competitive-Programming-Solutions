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

const int  N=1e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

vector <int> spf (N) ;

void sieve(){
    for(int i =2 ; i<N ; i++){
        if (spf[i])continue;
        for ( int j= i ; j<N ; j+=i)
            spf[j]= i;
    }
}

int factors(int n){
    int ans = 1 ;
    map <int,int> temp ;
    while ( n > 1 ) {
        temp[spf[n]]++;
        n/= spf[n] ;
    }
    for (auto val : temp )
        if (val.S%2)
            ans *= val.F ;
    return ans;
}


void Solve() {
    int n , q , mx1 = 1, mx2=1;
    cin >> n ;
    vector<int> v(n) ;
    map <int,int> mp ;
    for (auto &x: v) {
        cin >> x ;
        mx1 = max (mx1 , ++mp[factors(x)]);
    }
    for (auto x: mp){
        if (x.F ==1||x.S%2){
            mx2=max (mx2,x.S);
            continue;
        }
        mp[1]+= x.S ;
        mx2 = max(mx2,mp[1]) ;
    }
    cin >> q ;
    while (q--){
        int x ; cin >> x;
        if (x==0)cout << mx1 << endl;
        else cout << mx2 << endl;
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
