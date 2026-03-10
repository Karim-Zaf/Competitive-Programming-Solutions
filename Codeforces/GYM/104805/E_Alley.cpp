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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

const double pi =3.14159265359;

double get (double x , pair<double , double> b ){
    return sqrt(b.S*b.S - (x-b.F)*(x-b.F)) ;
}

double area (pair<double , double> b ) {
    return b.S * b.S * pi;
}

double work (pair<double,double> a , pair<double,double> b ){
    double r = a.F+a.S, l = b.F-b.S , x=1 , ans = 0;
    while (r-l>=0.00001){
        double md = l + (r-l)/2 ;
        double y1 = get(md,a);
        double y2 = get(md,b);
        if (y1<=y2)r = md;
        else l = md;
    }
    x = r ;
    double y = get (x,b);

    double angle = 2* acos (abs(x-a.F)/a.S);
    kar (angle*pi)
    ans += area (a)*(angle/(2*pi));
    ans -= abs(x-a.F)*y ;

    kar (angle);
    kar (angle);

    angle = 2* acos(abs(b.F-x)/b.S);
    ans += area (b)*(angle/(2*pi));
    ans -= abs(x-b.F)*y ;
    return ans ;
}


void Solve() {
    int n ;
    double ans = 0 ;
    cin >> n ;
    vector<pair<double,double>>  v;
    for (int i= 1; i<=n ;i++){
        double x, y ;
        cin >> x >> y ;
        v.pb({x,y});
        ans += area(v.back());
    }
    sort (all(v));
    for (int i= 1; i<n ; i++){
        if (v[i-1].F+v[i-1].S<v[i].F-v[i].S)continue;
        ans -= work (v[i-1],v[i]);
    }

    cout << fixed<< setprecision(5) << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}