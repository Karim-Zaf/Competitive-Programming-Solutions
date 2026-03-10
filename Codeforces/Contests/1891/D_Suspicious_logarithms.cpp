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
#define int __int128
#define endl '\n'

const int  N=1e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int lg [70][70] ;

int binpow(int a, int k){
    int res = 1;
    while (k){
        if (k % 2)
            res = (res * a);
        a = (a*a) ;
        k/=2 ;
    }
    return res ;
}

int mult(int a, int b){return a%MOD*b%MOD;}
int add (int a, int b){ return ((a%mod + b%mod)%mod + mod)%mod;}

void Solve(){
    ll l , r;
    __int128 res =0;
    cin >> l >> r ;
    for (int j= 0 ;j<70 ;j++){
        if (lg[2][j]<l)continue;
        if (lg[2][j-1]>=r)break;

        ll nw_r = min( r, (ll)lg[2][j] ) , nw_l = max ( l , (ll)lg[2][j-1]+1 ) ;
        for (int i = 1 ; i<70; i++){
            if (lg[j][i]<nw_l) continue;
            if (lg[j][i-1]>=nw_r)break;

            int lef = lg[j][i-1]+1,righ = lg[j][i];
            if (nw_l >=lef)lef = nw_l;
            if (nw_r <=righ)righ = nw_r;

            res = add(res,mult(i,add(righ,-lef+1)));
        }
    }
    cout << (ll)res << endl;
}

void preprocess() {
    for (int i= 1 ;i<70 ; i++){
        for (int j= 0;j <70; j++){
            lg[i][j]= binpow(i,j+1)-1;
            if (lg[i][j]>=INF) break;
        }
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);ll Test_case=1;
    preprocess();
    cin >> Test_case;
    while (Test_case--) Solve();
}
