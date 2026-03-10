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

const int  N=3e6+40 ,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int n ,q ;
int a[N], x[N], y[N], id[N], ans [N];
int freq[N];
int l , r , k , cnt = 0;

void  add(int x ){
    cnt += freq[x^k] ;
    freq[x]++;
}

void rmv ( int x){
    freq[x]--;
    cnt -= freq[x^k] ;
}

void update(int id){
    while ( r<y[id]) add(a[++r]);
    while (l>x[id]) add(a[--l]);
    while (r> y[id]) rmv (a[r--]);
    while ( l<x[id]) rmv ( a[l++]);
}

void mo (){
    int B = sqrt (n);
    sort (id,id+q,[&](ll a , ll b ){
        return make_pair(x[a]/B,y[a])<make_pair(x[b]/B,y[b]);
    });
    cnt =0 , l = 0 , r= -1 ;
    for (int i=0 ;i<  q; i++){
        int currid = id[i];
        update ( currid);
        ans [currid]= cnt ;
    }
}

void Solve(){
    cin >> n >> q >> k;
    for (int i=1 ;i<=n ;i++) {
        cin >> a[i];
        a[i]^= a[i-1] ;
    }
    for (int i=0 ;i<q; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        id[i] = i;
    }
    mo();
    for (int i=0 ;i<q; i++) cout << ans[i] << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}