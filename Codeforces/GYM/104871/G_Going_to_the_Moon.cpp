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
#define ld long double
#define endl '\n'

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

int xa, ya,xb ,yb, xc, yc ,r ;


ld dist (pair<ld,ld> x, pair<ld,ld> y ){
    return sqrtl((x.F -y.F)*(x.F-y.F)+ (x.S-y.S) *(x.S-y.S)) ;
}

ld f (ld x){
    ld c = r*r -x*x - xc*xc -yc*yc + 2*x*xc ;
    c*=-1;
    ld b = -2*yc ;

    ld delta = b*b - 4*c;

    if (delta ==0)  return -b / 2 ;

    return (-b - sqrtl(delta)) / 2 ;

}

ld f2 (ld x){
    ld c = r*r -x*x - xc*xc -yc*yc + 2*x*xc ;
    c*=-1;
    ld b = -2*yc ;
    ld delta = b*b - 4*c;

    if (delta ==0) return -b / 2 ;

    return (-b + sqrtl(delta)) / 2 ;

}

ld calc(ld x ){
    pair<ld,ld> a = {xa,ya};
    pair<ld,ld> b = {xb,yb};
    pair<ld,ld> nw = {x , f(x)} ;
    pair<ld,ld> nw2 = {x , f2(x)} ;

    ld mn = dist (a,nw)+ dist(nw,b);
    mn =min (mn , dist (a,nw2)+ dist(nw2,b));
    return mn;
}

ld work(){
    ld ret=0;

    ld l = xc -r , ri = xc + r ;

    while (ri-l>=0.0000000001) {
        ld md1 = l + (ri-l)/3 ;
        ld md2 = l + 2*(ri-l)/3 ;

        ld one = calc(md1) , two = calc(md2);


        if (one<= two){
            ret=one ;
            ri = md2 ;
        }else {
            ret = two ;
            l = md1 ;
        }
    }
    return ret ;
}

void Solve() {
    cout << fixed << setprecision(7) ;

    cin >> xa >> ya >> xb >> yb >> xc >> yc >> r;
    ld mn = dist({xa,ya},{xc,yc});
    mn = min(mn,dist({xb,yb},{xc,yc}));

    if (r==0){
        cout << dist ({xc,yc},{xa,ya})+dist ({xc,yc},{xb,yb})<<endl;
        return;
    }
    if (mn <= r){
        cout << dist({xa,ya},{xb,yb}) << endl;
        return ;
    }
    kar (2*sqrtl(20));
    cout << work() << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}