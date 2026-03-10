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

const int  N=2e3+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

vector<pair<int,int>> dp[N][2];


void Solve(){
    int n ,res =0;
    cin >> n ;
    vector <array<int,4>> v(n+1) ;
    for (int i= 1 ;i<=n; i++)
        for (int j= 0 ; j<4;j ++)
            cin >> v[i][j];
    auto wkt = [] (pair <int,int> ins , vector <pair <int,int>> &ret){
        if (!ret.empty() && ins.F == ret.back().F)ret[ret.size()-1].S = max(ret.back().S,ins.S);
        else ret.pb(ins);
    };

    auto merge=[&] (int rema ,int remb ,vector<pair<int,int>>&ret, vector<pair<int,int>>&a ,vector<pair<int,int>>&b){
        int sza = a.size(), szb= b.size(), pa=0 , pb = 0;

        auto zidha= [] (pair <int,int> pp, int zid){return make_pair(pp.F+zid,pp.S);};
        while (pa<sza && pb<szb){
            if(a[pa].F <b[pb].F) wkt(zidha(a[pa++],rema),ret);
            else if(a[pa].F >b[pb].F) wkt(zidha(b[pb++],remb),ret);
            else if(a[pa].S <b[pb].S) wkt(zidha(a[pa++],rema),ret);
            else wkt(zidha(b[pb++],remb),ret);
        }
        while (pa<sza)wkt(zidha(a[pa++],rema),ret);
        while (pb<szb)wkt(zidha(b[pb++],remb),ret);
    };
    auto merge2=[&] (vector<pair<int,int>>&ret, vector<pair<int,int>>&a ,vector<pair<int,int>>&b){
        int sza = a.size(), szb= b.size(), pa=0 , pb = 0;

        while (pa<sza && pb<szb){
            if(a[pa].F <b[pb].F) wkt(a[pa++],ret);
            else if(a[pa].F >b[pb].F) wkt(b[pb++],ret);
            else if(a[pa].S <b[pb].S) wkt(a[pa++],ret);
            else wkt(b[pb++],ret);
        }
        while (pa<sza)wkt(a[pa++],ret);
        while (pb<szb)wkt(b[pb++],ret);
    };
    auto work =[](int add , vector <pair <int,int>> &a){
        vector <pair <int,int>> ret ;
        for (auto x: a){
            pair <int,int> ins = x ;
            ins.F -= add ;
            ins.S ++;
            if (ins.F>=0) {
                if (!ret.empty() && ins.F == ret.back().F)ret[ret.size()-1].S = max(ret.back().S,ins.S);
                else ret.pb(ins);
            }
        }
        return ret ;
    };
    auto nettoie=[]( vector <pair<int,int>> v){
        vector <pair<int,int>> ret ;

        map <int,int> mp ;
        for (auto x: v){
            mp[x.S]=max (mp[x.S],x.F);
        }
        for (auto x: mp){
            ret.pb({x.S,x.F});
        }
        return ret ;
    };

    dp[0][1].pb({0,0});
    dp[0][0].pb({0,0});
    for (int i= 1 ;i<=n; i++){
        merge (v[i][0]-v[i-1][2],v[i][0]-v[i-1][1],dp[i][0],dp[i-1][0],dp[i-1][1]);
        vector<pair<int,int>> v1 = work (v[i][3]-(v[i][0]-v[i-1][2]),dp[i-1][0]);
        vector<pair<int,int>> v2 = work (v[i][3]-(v[i][0]-v[i-1][1]),dp[i-1][1]);
        merge2(dp[i][1],v1,v2);
        dp[i][1]=nettoie (dp[i][1]);
        dp[i][0]= nettoie(dp[i][0]);
        kar (dp[i][0]);
        kar (dp[i][1]);
    }
    for (auto x: dp[n][0]) res = max (res,x.S);
    for (auto x: dp[n][1]) res = max (res,x.S);
    cout << res<<endl;
}

//2
//0 12 14 1
//14 15 15 1



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}