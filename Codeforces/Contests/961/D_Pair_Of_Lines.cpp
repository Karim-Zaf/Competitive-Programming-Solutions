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
#define endl '\n'
//#define int ll
#define int __int128
const long long N=1e3+8,MOD=1e9+7,mod=1e9+7,INF=1e18;



array <int,4> equation (pair <int,int> a , pair <int,int> b){
    array <int,4> ret ;
    if (a.F == b.F)return {a.F,1,INF,INF};
    ret[0] = (a.S -b.S)/ __gcd((a.F -b.F),(a.S -b.S));
    ret[1]=(a.F -b.F)/ __gcd((a.F -b.F),(a.S -b.S));
    ret[2] = b.S*ret[1] - ret[0] * b.F ;
    ret[3] = ret[1] ;
    int g = __gcd (ret[2],ret[3]);
    ret[2]/=g ;
    ret[3]/=g;
    if (ret[1]<=0){
        ret[1]*=-1;
        ret[0]*=-1;
    }
    if (ret[3]<=0){
        ret[3]*=-1;
        ret[2]*=-1;
    }
    return ret ;
}

bool appartient (pair<int,int>a , array <int,4> d){
    if (d[2]==INF && a.F == d[0]) return true;
    if (d[2]==INF) return false ;

    int y= a.F*d[0]*d[3] + d[2]*d[1] ;
    int louta = d[1]*d[3];
    int g= __gcd(louta,y);
    if (g<=0) g*=-1 ;
    y/=g;
    louta/=g ;
    if (louta==1 && y==a.S)return true;
    return false ;
}


void Solve(){
    int32_t n ; cin >> n ;
    vector<pair<int32_t,int32_t>>v(n);
    for (int32_t i= 0;i<n;i++) cin >> v[i].F >> v[i].S ;

    if (n==1) {cout << "YES" << endl;return;}

    auto work=[&](pair<int,int> a , pair <int,int>b )->pair<int,int>{
        array <int,4> droite =equation(a,b);
        vector <int> s;
        for (int32_t i= 0 ;i<n;i++)if(!appartient(v[i],droite))s.pb(i);
        if (s.size()<=2)return {INF,INF};
        droite = equation (v[s[0]],v[s[2]]);
        vector <int> s2 ;
        for (auto i :s )if(!appartient(v[i],droite))s2.pb(i);
        if (s2.size()==0)return {INF,INF};
        return v[s[0]] ;
    };

    pair<int,int> p1 = work(v[0],v[1]);
    if (p1.F ==INF) {cout << "YES" << endl;return;}
    pair<int,int> p2 = work(v[0],p1);
    if (p2.F ==INF) {cout << "YES" << endl;return;}
    pair <int,int>p = work(p1,p2);
    if (p.F ==INF) {cout << "YES" << endl;return;}
    cout << "NO\n";
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}