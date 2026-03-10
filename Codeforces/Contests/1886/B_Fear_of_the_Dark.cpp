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

const int  N=1e5+8,MOD=1e9+7,mod=1e9+7,INF=1e17;

pair<long double,long double> p, a, b, o{0,0};

long double dist (pair <int,int> one , pair <int,int> two ){
    return sqrtl ((one.F-two.F)*(one.F-two.F) +(one.S-two.S)*(one.S-two.S) );
}

bool ok (long double md){
    if (dist(a,p)<=md && dist(a,o)<=md) return true ;
    if (dist(b,p)<=md && dist(b,o)<=md) return true ;
    kar (dist(a,b));
    if (dist(a,p))
    if (dist (a,b)/2.0 <=md&&(dist(a,p)<=md||dist(b,p)<=md) &&(dist(a,o)<=md||dist(b,o)<=md) ) return true; return false ;
}

void Solve() {
    cin >> p.F >> p.S >> a.F >> a.S >> b.F>> b.S ;
    long double l = 0 , r = 1e12 ;
    kar (dist (o,a));

    kar (ok(3.17))
    while (r-l>=0.0000001){
        long double md = l + (r-l)/2.0 ;
        if (ok(md)){
            r = md ;
        }else l = md ;
    }
    cout << fixed << setprecision(6)<< l << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}