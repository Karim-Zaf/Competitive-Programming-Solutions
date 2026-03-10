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


int r , c, q ;

char t[505][505] ;

bool can_move (array<int,3>a){
    return a[0]>=1 && a[1]>=1 && a[0]<=r && a[1] <= c && t[a[0]][a[1]]!='#';
}

int conv (char cc){
    if (cc=='U') return 90 ;
    if (cc=='L') return 180 ;
    if (cc=='D') return 270 ;
    if (cc=='R') return 0 ;
}

array<int,3> rot (array<int,3> a ){
    int & curr = a[2] ;
    curr -= 90 ;
    curr %= 360;
    curr += 360;
    curr %= 360;
    return a;
}

array<int,3> kadem (array<int,3> a){
    if (a[2]==0)a[1]++ ;
    if (a[2]==180)a[1]-- ;
    if (a[2]==90)a[0]-- ;
    if (a[2]==270)a[0]++ ;
    return a ;
}

array<int,3> frw (array<int,3> a){
    int cnt = 0;
    while (!can_move(kadem(a))&& ++cnt <10 ) a = rot (a) ;
    if (can_move(kadem(a))) a =  kadem(a) ;
    return a;
}

void Solve() {
    int x, y ; char d ;
    cin >> r >> c >> q >> x >> y >> d;
    vector<char> seq ,query;
    array<int,3> curr ={x,y,conv(d)};

    for (int i= 1; i<=r ;i++)
        for (int j= 1; j<=c; j++)
            cin >> t[i][j] ;

    vector<pair<char,int>> vp ;

    for (int i= 1; i<=q ; i++) {
        char cc ;
        cin >> cc ;
        if (cc=='R') query.pb('R');
        else {
            int xx ;
            cin >> xx ;
            for (int j= 1; j<=xx ; j++) query.pb('F') ;
        }
    }

    int i= 0 ;
    while(i<query.size() ){
        char act = query[i] ;
        int cnt = 0 ;
        while(i<query.size() && query[i]==act){
            i++ ;
            cnt ++ ;
        }
        if (act=='R')cnt%=4 ;
        vp.pb({act,cnt});
    }

    if (vp.back().F == 'R') vp.pop_back();



    for (auto [cc,xx] : vp){

        if (cc=='F') {
            for (int j= 1; j<=xx ;j++) curr = frw (curr) ;
            seq.pb('F') ;
            continue;
        }

        array<int,3> init = curr ;
        for (int j = 1; j<= xx ; j++){
            array<int,3> nw = init ;
            array<int,3> one = frw(nw) ;
            for (int k=j ; k<=xx ; k++)nw = rot (nw) ;
            array<int,3> two = frw(nw);
            if (one == two ) {seq.pb('F') ;break;}
            else seq.pb('R') ;
            init = rot(init) ;
        }

        for (int j = 1; j<= xx ; j++) curr = rot (curr) ;
    }


    int ans = 0 ;i = 0;
    while (i< seq.size() ){
        if (seq[i]=='F'){
            ans ++ ;
            while (i<seq.size() && seq[i]=='F') i++ ;
        }else ans ++ ,i++;
    }


    cout << ans << endl;
}


int32_t main(){
        freopen("reduce.in","r",stdin);
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}