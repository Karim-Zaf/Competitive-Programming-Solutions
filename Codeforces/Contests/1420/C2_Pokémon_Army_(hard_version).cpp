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
    int n ,q ,j=1 , sum=0;
    cin >> n >> q;

    vector<int> v(n+5);
    set<pair<int,int>> vp;

    for (int i= 1;i<=n ;i++) cin >> v[i] ;

    auto get =[&](int x ){
        return *prev(vp.lower_bound({x,INF}));
    };

    auto fasekh=[&](pair<int,int> p){
        if(vp.find(p)==vp.end()) return ;
        vp.erase(p);
        sum -= v[p.F] ;
        sum += v[p.S];
    };
    auto add =[&](pair<int,int> p){
        if (p.F>p.S)return;
        vp.insert(p);
        sum +=v[p.F];
        sum -= v[p.S];
    };
    auto merge=[&] (pair<int,int> one ,pair<int,int> two){
        pair <int,int> ret ={min(one.F,two.F),max(one.S,two.S)};
        fasekh(one);
        fasekh(two);
        add(ret);
    };

    auto split =[&] (pair<int,int> p, int indx){
        fasekh(p);
        int l1=p.F , r1 =indx-1 , l2= indx+1 ,r2 = p.S ;
        add({indx,indx});
        add({l1,r1});
        add({l2,r2});
    };

    auto work =[&](int x){
        if (x>1 && v[x]<v[x-1]) merge (get(x),get(x-1));

        if (x<n && v[x]>v[x+1]) merge (get(x),get(x+1));

    };

    while (j<=n){
        int l = j,r =j;
        while(r+1<=n && v[r]>v[r+1])r++;
        vp.insert({l,r});
        j=r+1;
    }
    for (auto [l,r]: vp)sum += v[l]-v[r];
    cout << sum + v[n] << endl;

    while (q--){
        int l ,r ; cin >> l >> r ;
        pair<int,int> oldintl=get(l) ;
        split (oldintl,l);
        pair<int,int> oldintr=get(r);
        split (oldintr,r);
        swap(v[l],v[r]);
        work(l);
        work(r);
        cout << sum + v[n] << endl;
    }

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}