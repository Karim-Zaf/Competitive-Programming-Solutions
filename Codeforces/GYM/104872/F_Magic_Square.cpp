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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int t [1005][1005] ;

void Solve() {
    int n ;
    cin >> n ;

    for (int i= 0 ; i<n ;i++)
        for (int j= 0 ; j<n; j++)
            cin >> t[i][j] ;


    int lezem = n* (n*n +1 ) / 2 ;
    vector<int> ligne , column , sumlg (n+1) ,sumcol(n+1) ;
    vector<pair<int,int>> vp ;

    for (int i= 0 ; i<n ;i++){
        for (int j= 0 ;j<n ;j++) sumlg[i] += t[i][j] ;
        if (sumlg[i] != lezem) ligne.pb(i) ;
    }

    for (int j= 0 ;j<n ;j++ ){
        for (int i= 0 ; i<n ;i++) sumcol[j] += t[i][j] ;
        if (sumcol[j] != lezem) column.pb(j) ;
    }

    if (!column.empty() && !ligne.empty())
        for (auto lg : ligne)
            for (auto col : column) {
                vp.pb({lg,col});
            }
    if (column.empty ())
        for (auto lg : ligne){
            for (int j= 0; j<n ;j++)
                vp.pb({lg,j});
        }
    if (ligne.empty())
        for (auto col : column) {
            for (int i= 0 ; i<n ;i++)
                vp.pb({i,col});
        }
    for (auto [x,y] : vp ){
        for (auto [x2,y2] : vp){
            if (x==x2&& y == y2 ) continue;
            int lg1 = sumlg[x] ,lg2 = sumlg [x2] ,col1 = sumcol [y] ,col2 = sumcol [y2] ;
            int one = t[x][y], two = t[x2][y2] ;
            if (x!=x2)lg1 = lg1 -one + two ;
            if (y!=y2)col1 = col1 -one + two ;
            if (x!=x2)lg2 = lg2 -two+one ;
            if (y!=y2)col2 = col2 -two+one ;


            if (lg1 == lezem && col1 == lezem && lg2 == lezem &&col2 == lezem ){
                cout << x+1<< " " << y+1<< "\n"<< x2+1<<" " <<y2+1<< endl;
                return ;
            }


        }
    }
    assert (false) ;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}