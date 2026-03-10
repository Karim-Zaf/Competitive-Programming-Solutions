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
 
const int  N=5e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;
 
 
void Solve() {
    int n , m , q , x, y , ans = 0;
    cin >> q >> n >> m>> x >> y ;
    int  mna = INF , mnb = INF ;
    vector <pair <int,int>> vpa (q),vpb(q);
    vector <int> a (q),b (q);
    for (int i= 0 ;i<q ;i++){
        cin >> vpa[i].F >> vpa[i].S ;
        a[i] = (x-vpa[i].F)*(x-vpa[i].F) + (y-vpa[i].S)*(y-vpa[i].S);
        mna = min (mna , a[i]);
    }
    for (int i= 0 ;i<q ;i++){
        cin >> vpb[i].F >> vpb[i].S ;
        b[i] = (x-vpb[i].F)*(x-vpb[i].F) + (y-vpb[i].S)*(y-vpb[i].S);
        mnb = min (mnb , b[i]);
    }
    if (mna <= mnb){
        for (auto xx :a) ans += (xx <=mnb);
        cout << "A "<< ans << endl; ;
    }else{
 
        for (auto xx :b) ans += (xx <=mna);
        cout << "R "<< ans << endl; ;
    }
 
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}