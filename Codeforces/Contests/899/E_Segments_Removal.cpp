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

void Solve() {
    int n , cnt =0;
    cin >> n ;
    vector<int> v(n) ;
    set<array<int,4>> inter , s;
    for (auto &x: v) cin >> x;

    int i= 0 ;
    while (i<n){
        int j= i ;
        while(i<n && v[j]==v[i])i++ ;
        inter.insert({j-i,j,i-1,v[j]});
    }

    for (auto [sz,l,r,x]: inter)
        s.insert({l,r,sz,x});


    while(!inter.empty()){
        cnt ++ ;

        auto [sz,l,r,x] = *inter.begin();

        s.erase({l,r,sz,x});
        inter.erase(*inter.begin());

        auto after = s.upper_bound({r,-1,0,0});

        if (after == s.begin())continue;

        auto before = prev(after) ;

        auto [l1,r1,sz1,x1] = *before;
        auto [l2,r2,sz2,x2] = *after;

        if (x1!=x2)continue;

        s.erase(before);
        s.erase(after);


        inter.erase({sz1,l1,r1,x1});
        inter.erase({sz2,l2,r2,x2});

        s.insert({l1,r2,sz1+sz2,x1});
        inter.insert({sz1+sz2,l1,r2,x1});
    }

    cout << cnt << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}